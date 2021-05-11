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
# ifndef AGPACK_PREPROCESSOR_SEQ_SEQ_HPP
# define AGPACK_PREPROCESSOR_SEQ_SEQ_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/seq/elem.hpp>
#
# /* AGPACK_PP_SEQ_HEAD */
#
# define AGPACK_PP_SEQ_HEAD(seq) AGPACK_PP_SEQ_ELEM(0, seq)
#
# /* AGPACK_PP_SEQ_TAIL */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_SEQ_TAIL(seq) AGPACK_PP_SEQ_TAIL_1((seq))
#    define AGPACK_PP_SEQ_TAIL_1(par) AGPACK_PP_SEQ_TAIL_2 ## par
#    define AGPACK_PP_SEQ_TAIL_2(seq) AGPACK_PP_SEQ_TAIL_I ## seq
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_SEQ_TAIL(seq) AGPACK_PP_SEQ_TAIL_ID(AGPACK_PP_SEQ_TAIL_I seq)
#    define AGPACK_PP_SEQ_TAIL_ID(id) id
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_TAIL(seq) AGPACK_PP_SEQ_TAIL_D(seq)
#    define AGPACK_PP_SEQ_TAIL_D(seq) AGPACK_PP_SEQ_TAIL_I seq
# else
#    define AGPACK_PP_SEQ_TAIL(seq) AGPACK_PP_SEQ_TAIL_I seq
# endif
#
# define AGPACK_PP_SEQ_TAIL_I(x)
#
# /* AGPACK_PP_SEQ_NIL */
#
# define AGPACK_PP_SEQ_NIL(x) (x)
#
# endif
