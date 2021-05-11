# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_ARITHMETIC_MOD_HPP
# define AGPACK_PREPROCESSOR_ARITHMETIC_MOD_HPP
#
# include <agpack/preprocessor/arithmetic/detail/div_base.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_MOD */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_MOD(x, y) AGPACK_PP_TUPLE_ELEM(3, 1, AGPACK_PP_DIV_BASE(x, y))
# else
#    define AGPACK_PP_MOD(x, y) AGPACK_PP_MOD_I(x, y)
#    define AGPACK_PP_MOD_I(x, y) AGPACK_PP_TUPLE_ELEM(3, 1, AGPACK_PP_DIV_BASE(x, y))
# endif
#
# /* AGPACK_PP_MOD_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_MOD_D(d, x, y) AGPACK_PP_TUPLE_ELEM(3, 1, AGPACK_PP_DIV_BASE_D(d, x, y))
# else
#    define AGPACK_PP_MOD_D(d, x, y) AGPACK_PP_MOD_D_I(d, x, y)
#    define AGPACK_PP_MOD_D_I(d, x, y) AGPACK_PP_TUPLE_ELEM(3, 1, AGPACK_PP_DIV_BASE_D(d, x, y))
# endif
#
# endif
