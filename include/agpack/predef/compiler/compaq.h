/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_COMPAQ_H
#define AGPACK_PREDEF_COMPILER_COMPAQ_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_DEC`]

[@http://www.openvms.compaq.com/openvms/brochures/deccplus/ Compaq C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__DECCXX`] [__predef_detection__]]
    [[`__DECC`] [__predef_detection__]]

    [[`__DECCXX_VER`] [V.R.P]]
    [[`__DECC_VER`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_DEC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DECC) || defined(__DECCXX)
#   if !defined(AGPACK_COMP_DEC_DETECTION) && defined(__DECCXX_VER)
#       define AGPACK_COMP_DEC_DETECTION AGPACK_PREDEF_MAKE_10_VVRR0PP00(__DECCXX_VER)
#   endif
#   if !defined(AGPACK_COMP_DEC_DETECTION) && defined(__DECC_VER)
#       define AGPACK_COMP_DEC_DETECTION AGPACK_PREDEF_MAKE_10_VVRR0PP00(__DECC_VER)
#   endif
#   if !defined(AGPACK_COMP_DEC_DETECTION)
#       define AGPACK_COM_DEC_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_DEC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_DEC_EMULATED AGPACK_COMP_DEC_DETECTION
#   else
#       undef AGPACK_COMP_DEC
#       define AGPACK_COMP_DEC AGPACK_COMP_DEC_DETECTION
#   endif
#   define AGPACK_COMP_DEC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_DEC_NAME "Compaq C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_DEC,AGPACK_COMP_DEC_NAME)

#ifdef AGPACK_COMP_DEC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_DEC_EMULATED,AGPACK_COMP_DEC_NAME)
#endif
