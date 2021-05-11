# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
#ifndef AGPACK_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP
#define AGPACK_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP

#if AGPACK_PP_VARIADICS_MSVC

#include <agpack/preprocessor/facilities/empty.hpp>

#define AGPACK_PP_DETAIL_VD_IBP_CAT(a, b) AGPACK_PP_DETAIL_VD_IBP_CAT_I(a, b)
#define AGPACK_PP_DETAIL_VD_IBP_CAT_I(a, b) AGPACK_PP_DETAIL_VD_IBP_CAT_II(a ## b)
#define AGPACK_PP_DETAIL_VD_IBP_CAT_II(res) res

#define AGPACK_PP_DETAIL_IBP_SPLIT(i, ...) \
    AGPACK_PP_DETAIL_VD_IBP_CAT(AGPACK_PP_DETAIL_IBP_PRIMITIVE_CAT(AGPACK_PP_DETAIL_IBP_SPLIT_,i)(__VA_ARGS__),AGPACK_PP_EMPTY()) \
/**/

#define AGPACK_PP_DETAIL_IBP_IS_VARIADIC_C(...) 1 1

#else

#define AGPACK_PP_DETAIL_IBP_SPLIT(i, ...) \
    AGPACK_PP_DETAIL_IBP_PRIMITIVE_CAT(AGPACK_PP_DETAIL_IBP_SPLIT_,i)(__VA_ARGS__) \
/**/

#define AGPACK_PP_DETAIL_IBP_IS_VARIADIC_C(...) 1

#endif /* AGPACK_PP_VARIADICS_MSVC */

#define AGPACK_PP_DETAIL_IBP_SPLIT_0(a, ...) a
#define AGPACK_PP_DETAIL_IBP_SPLIT_1(a, ...) __VA_ARGS__

#define AGPACK_PP_DETAIL_IBP_CAT(a, ...) AGPACK_PP_DETAIL_IBP_PRIMITIVE_CAT(a,__VA_ARGS__)
#define AGPACK_PP_DETAIL_IBP_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define AGPACK_PP_DETAIL_IBP_IS_VARIADIC_R_1 1,
#define AGPACK_PP_DETAIL_IBP_IS_VARIADIC_R_AGPACK_PP_DETAIL_IBP_IS_VARIADIC_C 0,

#endif /* AGPACK_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP */
