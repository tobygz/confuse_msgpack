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
#ifndef AGPACK_PREPROCESSOR_DETAIL_IS_EMPTY_HPP
#define AGPACK_PREPROCESSOR_DETAIL_IS_EMPTY_HPP

#include <agpack/preprocessor/punctuation/is_begin_parens.hpp>

#if AGPACK_PP_VARIADICS_MSVC

# pragma warning(once:4002)

#define AGPACK_PP_DETAIL_IS_EMPTY_IIF_0(t, b) b
#define AGPACK_PP_DETAIL_IS_EMPTY_IIF_1(t, b) t

#else

#define AGPACK_PP_DETAIL_IS_EMPTY_IIF_0(t, ...) __VA_ARGS__
#define AGPACK_PP_DETAIL_IS_EMPTY_IIF_1(t, ...) t

#endif

#if AGPACK_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define AGPACK_PP_DETAIL_IS_EMPTY_PROCESS(param) \
	AGPACK_PP_IS_BEGIN_PARENS \
    	( \
        AGPACK_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C param () \
        ) \
/**/

#else

#define AGPACK_PP_DETAIL_IS_EMPTY_PROCESS(...) \
	AGPACK_PP_IS_BEGIN_PARENS \
        ( \
        AGPACK_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C __VA_ARGS__ () \
        ) \
/**/

#endif

#define AGPACK_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(a, b) a ## b
#define AGPACK_PP_DETAIL_IS_EMPTY_IIF(bit) AGPACK_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(AGPACK_PP_DETAIL_IS_EMPTY_IIF_,bit)
#define AGPACK_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C(...) ()

#endif /* AGPACK_PREPROCESSOR_DETAIL_IS_EMPTY_HPP */
