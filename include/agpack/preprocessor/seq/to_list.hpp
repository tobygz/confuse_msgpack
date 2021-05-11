# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_SEQ_TO_LIST_HPP
# define AGPACK_PREPROCESSOR_SEQ_TO_LIST_HPP
#
# include <agpack/preprocessor/punctuation/comma.hpp>
# include <agpack/preprocessor/punctuation/paren.hpp>
# include <agpack/preprocessor/seq/detail/binary_transform.hpp>
#
# /* AGPACK_PP_SEQ_TO_LIST */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
# include <agpack/preprocessor/seq/size.hpp>
# include <agpack/preprocessor/seq/detail/to_list_msvc.hpp>
# define AGPACK_PP_SEQ_TO_LIST(seq) \
    AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC \
        ( \
        AGPACK_PP_SEQ_TO_LIST_I(AGPACK_PP_SEQ_BINARY_TRANSFORM(seq)), \
        AGPACK_PP_SEQ_SIZE(seq) \
        ) \
/**/
# else
# define AGPACK_PP_SEQ_TO_LIST(seq) AGPACK_PP_SEQ_TO_LIST_I(AGPACK_PP_SEQ_BINARY_TRANSFORM(seq))
# endif
# define AGPACK_PP_SEQ_TO_LIST_I(bseq) AGPACK_PP_SEQ_TO_LIST_A bseq AGPACK_PP_NIL AGPACK_PP_SEQ_TO_LIST_B bseq
# define AGPACK_PP_SEQ_TO_LIST_A(m, e) m(AGPACK_PP_LPAREN() e AGPACK_PP_COMMA() AGPACK_PP_SEQ_TO_LIST_A_ID)
# define AGPACK_PP_SEQ_TO_LIST_A_ID() AGPACK_PP_SEQ_TO_LIST_A
# define AGPACK_PP_SEQ_TO_LIST_B(m, e) m(AGPACK_PP_RPAREN() AGPACK_PP_SEQ_TO_LIST_B_ID)
# define AGPACK_PP_SEQ_TO_LIST_B_ID() AGPACK_PP_SEQ_TO_LIST_B
#
# endif
