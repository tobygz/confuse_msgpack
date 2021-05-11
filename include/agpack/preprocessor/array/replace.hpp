# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_ARRAY_REPLACE_HPP
# define AGPACK_PREPROCESSOR_ARRAY_REPLACE_HPP
#
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/array/elem.hpp>
# include <agpack/preprocessor/array/push_back.hpp>
# include <agpack/preprocessor/comparison/not_equal.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/deduce_d.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_ARRAY_REPLACE */
#
# define AGPACK_PP_ARRAY_REPLACE(array, i, elem) AGPACK_PP_ARRAY_REPLACE_I(AGPACK_PP_DEDUCE_D(), array, i, elem)
# define AGPACK_PP_ARRAY_REPLACE_I(d, array, i, elem) AGPACK_PP_ARRAY_REPLACE_D(d, array, i, elem)
#
# /* AGPACK_PP_ARRAY_REPLACE_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ARRAY_REPLACE_D(d, array, i, elem) AGPACK_PP_TUPLE_ELEM(5, 3, AGPACK_PP_WHILE_ ## d(AGPACK_PP_ARRAY_REPLACE_P, AGPACK_PP_ARRAY_REPLACE_O, (0, i, elem, (0, ()), array)))
# else
#    define AGPACK_PP_ARRAY_REPLACE_D(d, array, i, elem) AGPACK_PP_ARRAY_REPLACE_D_I(d, array, i, elem)
#    define AGPACK_PP_ARRAY_REPLACE_D_I(d, array, i, elem) AGPACK_PP_TUPLE_ELEM(5, 3, AGPACK_PP_WHILE_ ## d(AGPACK_PP_ARRAY_REPLACE_P, AGPACK_PP_ARRAY_REPLACE_O, (0, i, elem, (0, ()), array)))
# endif
#
# define AGPACK_PP_ARRAY_REPLACE_P(d, state) AGPACK_PP_NOT_EQUAL(AGPACK_PP_TUPLE_ELEM(5, 0, state), AGPACK_PP_ARRAY_SIZE(AGPACK_PP_TUPLE_ELEM(5, 4, state)))
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_ARRAY_REPLACE_O(d, state) AGPACK_PP_ARRAY_REPLACE_O_I state
# else
#    define AGPACK_PP_ARRAY_REPLACE_O(d, state) AGPACK_PP_ARRAY_REPLACE_O_I(AGPACK_PP_TUPLE_ELEM(5, 0, state), AGPACK_PP_TUPLE_ELEM(5, 1, state), AGPACK_PP_TUPLE_ELEM(5, 2, state), AGPACK_PP_TUPLE_ELEM(5, 3, state), AGPACK_PP_TUPLE_ELEM(5, 4, state))
# endif
#
# define AGPACK_PP_ARRAY_REPLACE_O_I(n, i, elem, res, arr) (AGPACK_PP_INC(n), i, elem, AGPACK_PP_ARRAY_PUSH_BACK(res, AGPACK_PP_IIF(AGPACK_PP_NOT_EQUAL(n, i), AGPACK_PP_ARRAY_ELEM(n, arr), elem)), arr)
#
# endif
