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
# ifndef AGPACK_PREPROCESSOR_SEQ_TRANSFORM_HPP
# define AGPACK_PREPROCESSOR_SEQ_TRANSFORM_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/seq/fold_left.hpp>
# include <agpack/preprocessor/seq/seq.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_SEQ_TRANSFORM */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_TRANSFORM(op, data, seq) AGPACK_PP_SEQ_TAIL(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_SEQ_FOLD_LEFT(AGPACK_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# else
#    define AGPACK_PP_SEQ_TRANSFORM(op, data, seq) AGPACK_PP_SEQ_TRANSFORM_I(op, data, seq)
#    define AGPACK_PP_SEQ_TRANSFORM_I(op, data, seq) AGPACK_PP_SEQ_TAIL(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_SEQ_FOLD_LEFT(AGPACK_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# endif
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_SEQ_TRANSFORM_O(s, state, elem) AGPACK_PP_SEQ_TRANSFORM_O_IM(s, AGPACK_PP_TUPLE_REM_3 state, elem)
#    define AGPACK_PP_SEQ_TRANSFORM_O_IM(s, im, elem) AGPACK_PP_SEQ_TRANSFORM_O_I(s, im, elem)
# else
#    define AGPACK_PP_SEQ_TRANSFORM_O(s, state, elem) AGPACK_PP_SEQ_TRANSFORM_O_I(s, AGPACK_PP_TUPLE_ELEM(3, 0, state), AGPACK_PP_TUPLE_ELEM(3, 1, state), AGPACK_PP_TUPLE_ELEM(3, 2, state), elem)
# endif
#
# define AGPACK_PP_SEQ_TRANSFORM_O_I(s, op, data, res, elem) (op, data, res (op(s, data, elem)))
#
# /* AGPACK_PP_SEQ_TRANSFORM_S */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_TRANSFORM_S(s, op, data, seq) AGPACK_PP_SEQ_TAIL(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_SEQ_FOLD_LEFT_ ## s(AGPACK_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# else
#    define AGPACK_PP_SEQ_TRANSFORM_S(s, op, data, seq) AGPACK_PP_SEQ_TRANSFORM_S_I(s, op, data, seq)
#    define AGPACK_PP_SEQ_TRANSFORM_S_I(s, op, data, seq) AGPACK_PP_SEQ_TAIL(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_SEQ_FOLD_LEFT_ ## s(AGPACK_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# endif
#
# endif
