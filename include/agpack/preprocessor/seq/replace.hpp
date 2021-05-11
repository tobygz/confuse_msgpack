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
# ifndef AGPACK_PREPROCESSOR_SEQ_REPLACE_HPP
# define AGPACK_PREPROCESSOR_SEQ_REPLACE_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/comparison/equal.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/seq/first_n.hpp>
# include <agpack/preprocessor/seq/rest_n.hpp>
# include <agpack/preprocessor/seq/size.hpp>
#
# /* AGPACK_PP_SEQ_REPLACE */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_REPLACE(seq, i, elem) AGPACK_PP_SEQ_FIRST_N(i, seq) (elem) AGPACK_PP_SEQ_REPLACE_DETAIL_REST(seq, i)
# else
#    define AGPACK_PP_SEQ_REPLACE(seq, i, elem) AGPACK_PP_SEQ_REPLACE_I(seq, i, elem)
#    define AGPACK_PP_SEQ_REPLACE_I(seq, i, elem) AGPACK_PP_SEQ_FIRST_N(i, seq) (elem) AGPACK_PP_SEQ_REPLACE_DETAIL_REST(seq, i)
# endif
#
#    define AGPACK_PP_SEQ_REPLACE_DETAIL_REST_EMPTY(seq, i)
#    define AGPACK_PP_SEQ_REPLACE_DETAIL_REST_VALID(seq, i) AGPACK_PP_SEQ_REST_N(AGPACK_PP_INC(i), seq)
#    define AGPACK_PP_SEQ_REPLACE_DETAIL_REST(seq, i) \
		AGPACK_PP_IIF \
			( \
			AGPACK_PP_EQUAL(i,AGPACK_PP_DEC(AGPACK_PP_SEQ_SIZE(seq))), \
			AGPACK_PP_SEQ_REPLACE_DETAIL_REST_EMPTY, \
			AGPACK_PP_SEQ_REPLACE_DETAIL_REST_VALID \
			) \
		(seq, i) \
/**/
#
# endif
