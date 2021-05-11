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
# ifndef AGPACK_PREPROCESSOR_LIST_FILTER_HPP
# define AGPACK_PREPROCESSOR_LIST_FILTER_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/list/fold_right.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_LIST_FILTER */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FILTER(pred, data, list) AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_LIST_FOLD_RIGHT(AGPACK_PP_LIST_FILTER_O, (pred, data, AGPACK_PP_NIL), list))
# else
#    define AGPACK_PP_LIST_FILTER(pred, data, list) AGPACK_PP_LIST_FILTER_I(pred, data, list)
#    define AGPACK_PP_LIST_FILTER_I(pred, data, list) AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_LIST_FOLD_RIGHT(AGPACK_PP_LIST_FILTER_O, (pred, data, AGPACK_PP_NIL), list))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FILTER_O(d, pdr, elem) AGPACK_PP_LIST_FILTER_O_D(d, AGPACK_PP_TUPLE_ELEM(3, 0, pdr), AGPACK_PP_TUPLE_ELEM(3, 1, pdr), AGPACK_PP_TUPLE_ELEM(3, 2, pdr), elem)
# else
#    define AGPACK_PP_LIST_FILTER_O(d, pdr, elem) AGPACK_PP_LIST_FILTER_O_I(d, AGPACK_PP_TUPLE_REM_3 pdr, elem)
#    define AGPACK_PP_LIST_FILTER_O_I(d, im, elem) AGPACK_PP_LIST_FILTER_O_D(d, im, elem)
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_DMC()
#    define AGPACK_PP_LIST_FILTER_O_D(d, pred, data, res, elem) (pred, data, AGPACK_PP_IF(pred(d, data, elem), (elem, res), res))
# else
#    define AGPACK_PP_LIST_FILTER_O_D(d, pred, data, res, elem) (pred, data, AGPACK_PP_IF(pred##(d, data, elem), (elem, res), res))
# endif
#
# /* AGPACK_PP_LIST_FILTER_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FILTER_D(d, pred, data, list) AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_LIST_FOLD_RIGHT_ ## d(AGPACK_PP_LIST_FILTER_O, (pred, data, AGPACK_PP_NIL), list))
# else
#    define AGPACK_PP_LIST_FILTER_D(d, pred, data, list) AGPACK_PP_LIST_FILTER_D_I(d, pred, data, list)
#    define AGPACK_PP_LIST_FILTER_D_I(d, pred, data, list) AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_LIST_FOLD_RIGHT_ ## d(AGPACK_PP_LIST_FILTER_O, (pred, data, AGPACK_PP_NIL), list))
# endif
#
# endif
