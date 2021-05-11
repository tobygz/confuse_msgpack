/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_METROWERKS_H
#define AGPACK_PREDEF_COMPILER_METROWERKS_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_MWERKS`]

[@http://en.wikipedia.org/wiki/CodeWarrior Metrowerks CodeWarrior] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MWERKS__`] [__predef_detection__]]
    [[`__CWCC__`] [__predef_detection__]]

    [[`__CWCC__`] [V.R.P]]
    [[`__MWERKS__`] [V.R.P >= 4.2.0]]
    [[`__MWERKS__`] [9.R.0]]
    [[`__MWERKS__`] [8.R.0]]
    ]
 */

#define AGPACK_COMP_MWERKS AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MWERKS__) || defined(__CWCC__)
#   if !defined(AGPACK_COMP_MWERKS_DETECTION) && defined(__CWCC__)
#       define AGPACK_COMP_MWERKS_DETECTION AGPACK_PREDEF_MAKE_0X_VRPP(__CWCC__)
#   endif
#   if !defined(AGPACK_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x4200)
#       define AGPACK_COMP_MWERKS_DETECTION AGPACK_PREDEF_MAKE_0X_VRPP(__MWERKS__)
#   endif
#   if !defined(AGPACK_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3204) // note the "skip": 04->9.3
#       define AGPACK_COMP_MWERKS_DETECTION AGPACK_VERSION_NUMBER(9,(__MWERKS__)%100-1,0)
#   endif
#   if !defined(AGPACK_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3200)
#       define AGPACK_COMP_MWERKS_DETECTION AGPACK_VERSION_NUMBER(9,(__MWERKS__)%100,0)
#   endif
#   if !defined(AGPACK_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3000)
#       define AGPACK_COMP_MWERKS_DETECTION AGPACK_VERSION_NUMBER(8,(__MWERKS__)%100,0)
#   endif
#   if !defined(AGPACK_COMP_MWERKS_DETECTION)
#       define AGPACK_COMP_MWERKS_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_MWERKS_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_MWERKS_EMULATED AGPACK_COMP_MWERKS_DETECTION
#   else
#       undef AGPACK_COMP_MWERKS
#       define AGPACK_COMP_MWERKS AGPACK_COMP_MWERKS_DETECTION
#   endif
#   define AGPACK_COMP_MWERKS_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_MWERKS_NAME "Metrowerks CodeWarrior"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_MWERKS,AGPACK_COMP_MWERKS_NAME)

#ifdef AGPACK_COMP_MWERKS_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_MWERKS_EMULATED,AGPACK_COMP_MWERKS_NAME)
#endif
