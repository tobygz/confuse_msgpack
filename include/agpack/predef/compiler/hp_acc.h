/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_HP_ACC_H
#define AGPACK_PREDEF_COMPILER_HP_ACC_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_HPACC`]

HP aC++ compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__HP_aCC`] [__predef_detection__]]

    [[`__HP_aCC`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_HPACC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__HP_aCC)
#   if !defined(AGPACK_COMP_HPACC_DETECTION) && (__HP_aCC > 1)
#       define AGPACK_COMP_HPACC_DETECTION AGPACK_PREDEF_MAKE_10_VVRRPP(__HP_aCC)
#   endif
#   if !defined(AGPACK_COMP_HPACC_DETECTION)
#       define AGPACK_COMP_HPACC_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_HPACC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_HPACC_EMULATED AGPACK_COMP_HPACC_DETECTION
#   else
#       undef AGPACK_COMP_HPACC
#       define AGPACK_COMP_HPACC AGPACK_COMP_HPACC_DETECTION
#   endif
#   define AGPACK_COMP_HPACC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_HPACC_NAME "HP aC++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_HPACC,AGPACK_COMP_HPACC_NAME)

#ifdef AGPACK_COMP_HPACC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_HPACC_EMULATED,AGPACK_COMP_HPACC_NAME)
#endif
