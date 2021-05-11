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
# ifndef AGPACK_PREPROCESSOR_ARRAY_REMOVE_HPP
# define AGPACK_PREPROCESSOR_ARRAY_REMOVE_HPP
#
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/array/elem.hpp>
# include <agpack/preprocessor/array/push_back.hpp>
# include <agpack/preprocessor/array/size.hpp>
# include <agpack/preprocessor/comparison/not_equal.hpp>
# include <agpack/preprocessor/control/deduce_d.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/tuple/eat.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_ARRAY_REMOVE */
#
# define AGPACK_PP_ARRAY_REMOVE(array, i) AGPACK_PP_ARRAY_REMOVE_I(AGPACK_PP_DEDUCE_D(), array, i)
# define AGPACK_PP_ARRAY_REMOVE_I(d, array, i) AGPACK_PP_ARRAY_REMOVE_D(d, array, i)
#
# /* AGPACK_PP_ARRAY_REMOVE_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ARRAY_REMOVE_D(d, array, i) AGPACK_PP_TUPLE_ELEM(4, 2, AGPACK_PP_WHILE_ ## d(AGPACK_PP_ARRAY_REMOVE_P, AGPACK_PP_ARRAY_REMOVE_O, (0, i, (0, ()), array)))
# else
#    define AGPACK_PP_ARRAY_REMOVE_D(d, array, i) AGPACK_PP_ARRAY_REMOVE_D_I(d, array, i)
#    define AGPACK_PP_ARRAY_REMOVE_D_I(d, array, i) AGPACK_PP_TUPLE_ELEM(4, 2, AGPACK_PP_WHILE_ ## d(AGPACK_PP_ARRAY_REMOVE_P, AGPACK_PP_ARRAY_REMOVE_O, (0, i, (0, ()), array)))
# endif
#
# define AGPACK_PP_ARRAY_REMOVE_P(d, st) AGPACK_PP_NOT_EQUAL(AGPACK_PP_TUPLE_ELEM(4, 0, st), AGPACK_PP_ARRAY_SIZE(AGPACK_PP_TUPLE_ELEM(4, 3, st)))
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_ARRAY_REMOVE_O(d, st) AGPACK_PP_ARRAY_REMOVE_O_I st
# else
#    define AGPACK_PP_ARRAY_REMOVE_O(d, st) AGPACK_PP_ARRAY_REMOVE_O_I(AGPACK_PP_TUPLE_ELEM(4, 0, st), AGPACK_PP_TUPLE_ELEM(4, 1, st), AGPACK_PP_TUPLE_ELEM(4, 2, st), AGPACK_PP_TUPLE_ELEM(4, 3, st))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_DMC()
#    define AGPACK_PP_ARRAY_REMOVE_O_I(n, i, res, arr) (AGPACK_PP_INC(n), i, AGPACK_PP_IIF(AGPACK_PP_NOT_EQUAL(n, i), AGPACK_PP_ARRAY_PUSH_BACK, res AGPACK_PP_TUPLE_EAT_2)(res, AGPACK_PP_ARRAY_ELEM(n, arr)), arr)
# else
#    define AGPACK_PP_ARRAY_REMOVE_O_I(n, i, res, arr) (AGPACK_PP_INC(n), i, AGPACK_PP_IIF(AGPACK_PP_NOT_EQUAL(n, i), AGPACK_PP_ARRAY_PUSH_BACK, AGPACK_PP_TUPLE_ELEM_2_0)(res, AGPACK_PP_ARRAY_ELEM(n, arr)), arr)
# endif
#
# endif
