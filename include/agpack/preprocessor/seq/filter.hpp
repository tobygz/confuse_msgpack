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
# ifndef AGPACK_PREPROCESSOR_SEQ_FILTER_HPP
# define AGPACK_PREPROCESSOR_SEQ_FILTER_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/expr_if.hpp>
# include <agpack/preprocessor/facilities/empty.hpp>
# include <agpack/preprocessor/seq/fold_left.hpp>
# include <agpack/preprocessor/seq/seq.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_SEQ_FILTER */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_FILTER(pred, data, seq) AGPACK_PP_SEQ_TAIL(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_SEQ_FOLD_LEFT(AGPACK_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# else
#    define AGPACK_PP_SEQ_FILTER(pred, data, seq) AGPACK_PP_SEQ_FILTER_I(pred, data, seq)
#    define AGPACK_PP_SEQ_FILTER_I(pred, data, seq) AGPACK_PP_SEQ_TAIL(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_SEQ_FOLD_LEFT(AGPACK_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# endif
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_SEQ_FILTER_O(s, st, elem) AGPACK_PP_SEQ_FILTER_O_IM(s, AGPACK_PP_TUPLE_REM_3 st, elem)
#    define AGPACK_PP_SEQ_FILTER_O_IM(s, im, elem) AGPACK_PP_SEQ_FILTER_O_I(s, im, elem)
# else
#    define AGPACK_PP_SEQ_FILTER_O(s, st, elem) AGPACK_PP_SEQ_FILTER_O_I(s, AGPACK_PP_TUPLE_ELEM(3, 0, st), AGPACK_PP_TUPLE_ELEM(3, 1, st), AGPACK_PP_TUPLE_ELEM(3, 2, st), elem)
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_DMC()
#   define AGPACK_PP_SEQ_FILTER_O_I(s, pred, data, res, elem) (pred, data, res AGPACK_PP_EXPR_IF(pred(s, data, elem), (elem)))
# else
#   define AGPACK_PP_SEQ_FILTER_O_I(s, pred, data, res, elem) (pred, data, res AGPACK_PP_EXPR_IF(pred##(s, data, elem), (elem)))
# endif
#
# /* AGPACK_PP_SEQ_FILTER_S */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_FILTER_S(s, pred, data, seq) AGPACK_PP_SEQ_TAIL(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_SEQ_FOLD_LEFT_ ## s(AGPACK_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# else
#    define AGPACK_PP_SEQ_FILTER_S(s, pred, data, seq) AGPACK_PP_SEQ_FILTER_S_I(s, pred, data, seq)
#    define AGPACK_PP_SEQ_FILTER_S_I(s, pred, data, seq) AGPACK_PP_SEQ_TAIL(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_SEQ_FOLD_LEFT_ ## s(AGPACK_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# endif
#
# endif
