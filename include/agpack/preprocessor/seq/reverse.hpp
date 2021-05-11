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
# ifndef AGPACK_PREPROCESSOR_SEQ_REVERSE_HPP
# define AGPACK_PREPROCESSOR_SEQ_REVERSE_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/facilities/empty.hpp>
# include <agpack/preprocessor/seq/fold_left.hpp>
#
# /* AGPACK_PP_SEQ_REVERSE */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_REVERSE(seq) AGPACK_PP_SEQ_FOLD_LEFT(AGPACK_PP_SEQ_REVERSE_O, AGPACK_PP_EMPTY, seq)()
# else
#    define AGPACK_PP_SEQ_REVERSE(seq) AGPACK_PP_SEQ_REVERSE_I(seq)
#    define AGPACK_PP_SEQ_REVERSE_I(seq) AGPACK_PP_SEQ_FOLD_LEFT(AGPACK_PP_SEQ_REVERSE_O, AGPACK_PP_EMPTY, seq)()
# endif
#
# define AGPACK_PP_SEQ_REVERSE_O(s, state, elem) (elem) state
#
# /* AGPACK_PP_SEQ_REVERSE_S */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_REVERSE_S(s, seq) AGPACK_PP_SEQ_FOLD_LEFT_ ## s(AGPACK_PP_SEQ_REVERSE_O, AGPACK_PP_EMPTY, seq)()
# else
#    define AGPACK_PP_SEQ_REVERSE_S(s, seq) AGPACK_PP_SEQ_REVERSE_S_I(s, seq)
#    define AGPACK_PP_SEQ_REVERSE_S_I(s, seq) AGPACK_PP_SEQ_FOLD_LEFT_ ## s(AGPACK_PP_SEQ_REVERSE_O, AGPACK_PP_EMPTY, seq)()
# endif
#
# endif
