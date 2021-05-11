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
# ifndef AGPACK_PREPROCESSOR_LIST_TRANSFORM_HPP
# define AGPACK_PREPROCESSOR_LIST_TRANSFORM_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/list/fold_right.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_LIST_TRANSFORM */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_TRANSFORM(op, data, list) AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_LIST_FOLD_RIGHT(AGPACK_PP_LIST_TRANSFORM_O, (op, data, AGPACK_PP_NIL), list))
# else
#    define AGPACK_PP_LIST_TRANSFORM(op, data, list) AGPACK_PP_LIST_TRANSFORM_I(op, data, list)
#    define AGPACK_PP_LIST_TRANSFORM_I(op, data, list) AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_LIST_FOLD_RIGHT(AGPACK_PP_LIST_TRANSFORM_O, (op, data, AGPACK_PP_NIL), list))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_TRANSFORM_O(d, odr, elem) AGPACK_PP_LIST_TRANSFORM_O_D(d, AGPACK_PP_TUPLE_ELEM(3, 0, odr), AGPACK_PP_TUPLE_ELEM(3, 1, odr), AGPACK_PP_TUPLE_ELEM(3, 2, odr), elem)
# else
#    define AGPACK_PP_LIST_TRANSFORM_O(d, odr, elem) AGPACK_PP_LIST_TRANSFORM_O_I(d, AGPACK_PP_TUPLE_REM_3 odr, elem)
#    define AGPACK_PP_LIST_TRANSFORM_O_I(d, im, elem) AGPACK_PP_LIST_TRANSFORM_O_D(d, im, elem)
# endif
#
# define AGPACK_PP_LIST_TRANSFORM_O_D(d, op, data, res, elem) (op, data, (op(d, data, elem), res))
#
# /* AGPACK_PP_LIST_TRANSFORM_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_TRANSFORM_D(d, op, data, list) AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_LIST_FOLD_RIGHT_ ## d(AGPACK_PP_LIST_TRANSFORM_O, (op, data, AGPACK_PP_NIL), list))
# else
#    define AGPACK_PP_LIST_TRANSFORM_D(d, op, data, list) AGPACK_PP_LIST_TRANSFORM_D_I(d, op, data, list)
#    define AGPACK_PP_LIST_TRANSFORM_D_I(d, op, data, list) AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_LIST_FOLD_RIGHT_ ## d(AGPACK_PP_LIST_TRANSFORM_O, (op, data, AGPACK_PP_NIL), list))
# endif
#
# endif
