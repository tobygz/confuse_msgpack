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
# ifndef AGPACK_PREPROCESSOR_TUPLE_TO_ARRAY_HPP
# define AGPACK_PREPROCESSOR_TUPLE_TO_ARRAY_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/facilities/overload.hpp>
# include <agpack/preprocessor/tuple/size.hpp>
# include <agpack/preprocessor/variadic/size.hpp>
#
# /* AGPACK_PP_TUPLE_TO_ARRAY */
#
# if AGPACK_PP_VARIADICS
#    if AGPACK_PP_VARIADICS_MSVC
#        define AGPACK_PP_TUPLE_TO_ARRAY(...) AGPACK_PP_TUPLE_TO_ARRAY_I(AGPACK_PP_OVERLOAD(AGPACK_PP_TUPLE_TO_ARRAY_, __VA_ARGS__), (__VA_ARGS__))
#        define AGPACK_PP_TUPLE_TO_ARRAY_I(m, args) AGPACK_PP_TUPLE_TO_ARRAY_II(m, args)
#        define AGPACK_PP_TUPLE_TO_ARRAY_II(m, args) AGPACK_PP_CAT(m ## args,)
#        define AGPACK_PP_TUPLE_TO_ARRAY_1(tuple) (AGPACK_PP_TUPLE_SIZE(tuple), tuple)
#    else
#        define AGPACK_PP_TUPLE_TO_ARRAY(...) AGPACK_PP_OVERLOAD(AGPACK_PP_TUPLE_TO_ARRAY_, __VA_ARGS__)(__VA_ARGS__)
#        define AGPACK_PP_TUPLE_TO_ARRAY_1(tuple) (AGPACK_PP_VARIADIC_SIZE tuple, tuple)
#    endif
#    define AGPACK_PP_TUPLE_TO_ARRAY_2(size, tuple) (size, tuple)
# else
#    define AGPACK_PP_TUPLE_TO_ARRAY(size, tuple) (size, tuple)
# endif
#
# endif
