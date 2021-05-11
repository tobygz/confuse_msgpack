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
# ifndef AGPACK_PREPROCESSOR_SEQ_REST_N_HPP
# define AGPACK_PREPROCESSOR_SEQ_REST_N_HPP
#
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/comparison/not_equal.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/expr_iif.hpp>
# include <agpack/preprocessor/facilities/identity.hpp>
# include <agpack/preprocessor/logical/bitand.hpp>
# include <agpack/preprocessor/seq/detail/is_empty.hpp>
# include <agpack/preprocessor/seq/detail/split.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_SEQ_REST_N */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_REST_N(n, seq) AGPACK_PP_SEQ_REST_N_DETAIL_EXEC(n, seq, AGPACK_PP_SEQ_DETAIL_EMPTY_SIZE(seq))
# else
#    define AGPACK_PP_SEQ_REST_N(n, seq) AGPACK_PP_SEQ_REST_N_I(n, seq)
#    define AGPACK_PP_SEQ_REST_N_I(n, seq) AGPACK_PP_SEQ_REST_N_DETAIL_EXEC(n, seq, AGPACK_PP_SEQ_DETAIL_EMPTY_SIZE(seq))
# endif
#
#    define AGPACK_PP_SEQ_REST_N_DETAIL_EXEC(n, seq, size) \
		AGPACK_PP_EXPR_IIF \
			( \
			AGPACK_PP_BITAND \
				( \
				AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY_SIZE(size), \
				AGPACK_PP_NOT_EQUAL(n,size) \
				), \
			AGPACK_PP_TUPLE_ELEM(2, 1, AGPACK_PP_SEQ_SPLIT(AGPACK_PP_INC(n), AGPACK_PP_IDENTITY( (nil) seq )))() \
			) \
/**/
#
# endif
