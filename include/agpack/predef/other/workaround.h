/*
Copyright Rene Rivera 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_WORKAROUND_H
#define AGPACK_PREDEF_WORKAROUND_H

/*`
[heading `AGPACK_PREDEF_WORKAROUND`]

``
AGPACK_PREDEF_WORKAROUND(symbol,comp,major,minor,patch)
``

Usage:

``
#if AGPACK_PREDEF_WORKAROUND(AGPACK_COMP_CLANG,<,3,0,0)
    // Workaround for old clang compilers..
#endif
``

Defines a comparison against two version numbers that depends on the definion
of `AGPACK_STRICT_CONFIG`. When `AGPACK_STRICT_CONFIG` is defined this will expand
to a value convertible to `false`. Which has the effect of disabling all code
conditionally guarded by `AGPACK_PREDEF_WORKAROUND`. When `AGPACK_STRICT_CONFIG`
is undefine this expand to test the given `symbol` version value with the
`comp` comparison against `AGPACK_VERSION_NUMBER(major,minor,patch)`.
*/
#ifdef AGPACK_STRICT_CONFIG
#   define AGPACK_PREDEF_WORKAROUND(symbol, comp, major, minor, patch) (0)
#else
#   include <agpack/predef/version_number.h>
#   define AGPACK_PREDEF_WORKAROUND(symbol, comp, major, minor, patch) \
        ( (symbol) != (0) ) && \
        ( (symbol) comp (AGPACK_VERSION_NUMBER( (major) , (minor) , (patch) )) )
#endif

/*`
[heading `AGPACK_PREDEF_TESTED_AT`]

``
AGPACK_PREDEF_TESTED_AT(symbol,major,minor,patch)
``

Usage:

``
#if AGPACK_PREDEF_TESTED_AT(AGPACK_COMP_CLANG,3,5,0)
    // Needed for clang, and last checked for 3.5.0.
#endif
``

Defines a comparison against two version numbers that depends on the definion
of `AGPACK_STRICT_CONFIG` and `AGPACK_DETECT_OUTDATED_WORKAROUNDS`.
When `AGPACK_STRICT_CONFIG` is defined this will expand to a value convertible
to `false`. Which has the effect of disabling all code
conditionally guarded by `AGPACK_PREDEF_TESTED_AT`. When `AGPACK_STRICT_CONFIG`
is undefined this expand to either:

* A value convertible to `true` when `AGPACK_DETECT_OUTDATED_WORKAROUNDS` is not
  defined.
* A value convertible `true` when the expansion of
  `AGPACK_PREDEF_WORKAROUND(symbol, <=, major, minor, patch)` is `true` and
  `AGPACK_DETECT_OUTDATED_WORKAROUNDS` is defined.
* A compile error when the expansion of
  `AGPACK_PREDEF_WORKAROUND(symbol, >, major, minor, patch)` is true and
  `AGPACK_DETECT_OUTDATED_WORKAROUNDS` is defined.
*/
#ifdef AGPACK_STRICT_CONFIG
#   define AGPACK_PREDEF_TESTED_AT(symbol, major, minor, patch) (0)
#else
#   ifdef AGPACK_DETECT_OUTDATED_WORKAROUNDS
#       define AGPACK_PREDEF_TESTED_AT(symbol, major, minor, patch) ( \
            AGPACK_PREDEF_WORKAROUND(symbol, <=, major, minor, patch) \
            ? 1 \
            : (1%0) )
#   else
#       define AGPACK_PREDEF_TESTED_AT(symbol, major, minor, patch) \
            ( (symbol) >= AGPACK_VERSION_NUMBER_AVAILABLE )
#   endif
#endif

#endif
