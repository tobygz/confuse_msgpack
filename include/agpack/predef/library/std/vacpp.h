/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_STD_VACPP_H
#define AGPACK_PREDEF_LIBRARY_STD_VACPP_H

#include <agpack/predef/library/std/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_STD_IBM`]

[@http://www.ibm.com/software/awdtools/xlcpp/ IBM VACPP Standard C++] library.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__IBMCPP__`] [__predef_detection__]]
    ]
 */

#define AGPACK_LIB_STD_IBM AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IBMCPP__)
#   undef AGPACK_LIB_STD_IBM
#   define AGPACK_LIB_STD_IBM AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_LIB_STD_IBM
#   define AGPACK_LIB_STD_IBM_AVAILABLE
#endif

#define AGPACK_LIB_STD_IBM_NAME "IBM VACPP"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_STD_IBM,AGPACK_LIB_STD_IBM_NAME)
