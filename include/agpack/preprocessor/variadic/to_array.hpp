# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_VARIADIC_TO_ARRAY_HPP
# define AGPACK_PREPROCESSOR_VARIADIC_TO_ARRAY_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/to_array.hpp>
# if AGPACK_PP_VARIADICS_MSVC
#    include <agpack/preprocessor/variadic/size.hpp>
# endif
#
# /* AGPACK_PP_VARIADIC_TO_ARRAY */
#
# if AGPACK_PP_VARIADICS
#    if AGPACK_PP_VARIADICS_MSVC
#        define AGPACK_PP_VARIADIC_TO_ARRAY(...) AGPACK_PP_TUPLE_TO_ARRAY_2(AGPACK_PP_VARIADIC_SIZE(__VA_ARGS__),(__VA_ARGS__))
#    else
#        define AGPACK_PP_VARIADIC_TO_ARRAY(...) AGPACK_PP_TUPLE_TO_ARRAY((__VA_ARGS__))
#    endif
# endif
#
# endif
