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
# ifndef AGPACK_PREPROCESSOR_SEQ_CAT_HPP
# define AGPACK_PREPROCESSOR_SEQ_CAT_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/seq/fold_left.hpp>
# include <agpack/preprocessor/seq/seq.hpp>
# include <agpack/preprocessor/seq/size.hpp>
# include <agpack/preprocessor/tuple/eat.hpp>
#
# /* AGPACK_PP_SEQ_CAT */
#
# define AGPACK_PP_SEQ_CAT(seq) \
    AGPACK_PP_IF( \
        AGPACK_PP_DEC(AGPACK_PP_SEQ_SIZE(seq)), \
        AGPACK_PP_SEQ_CAT_I, \
        AGPACK_PP_SEQ_HEAD \
    )(seq) \
    /**/
# define AGPACK_PP_SEQ_CAT_I(seq) AGPACK_PP_SEQ_FOLD_LEFT(AGPACK_PP_SEQ_CAT_O, AGPACK_PP_SEQ_HEAD(seq), AGPACK_PP_SEQ_TAIL(seq))
#
# define AGPACK_PP_SEQ_CAT_O(s, st, elem) AGPACK_PP_SEQ_CAT_O_I(st, elem)
# define AGPACK_PP_SEQ_CAT_O_I(a, b) a ## b
#
# /* AGPACK_PP_SEQ_CAT_S */
#
# define AGPACK_PP_SEQ_CAT_S(s, seq) \
    AGPACK_PP_IF( \
        AGPACK_PP_DEC(AGPACK_PP_SEQ_SIZE(seq)), \
        AGPACK_PP_SEQ_CAT_S_I_A, \
        AGPACK_PP_SEQ_CAT_S_I_B \
    )(s, seq) \
    /**/
# define AGPACK_PP_SEQ_CAT_S_I_A(s, seq) AGPACK_PP_SEQ_FOLD_LEFT_ ## s(AGPACK_PP_SEQ_CAT_O, AGPACK_PP_SEQ_HEAD(seq), AGPACK_PP_SEQ_TAIL(seq))
# define AGPACK_PP_SEQ_CAT_S_I_B(s, seq) AGPACK_PP_SEQ_HEAD(seq)
#
# endif
