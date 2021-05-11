# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2015.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_SEQ_DETAIL_IS_EMPTY_HPP
# define AGPACK_PREPROCESSOR_SEQ_DETAIL_IS_EMPTY_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/logical/bool.hpp>
# include <agpack/preprocessor/logical/compl.hpp>
# include <agpack/preprocessor/seq/size.hpp>
#
/* An empty seq is one that is just AGPACK_PP_SEQ_NIL */
#
# define AGPACK_PP_SEQ_DETAIL_IS_EMPTY(seq) \
	AGPACK_PP_COMPL \
		( \
		AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq) \
		) \
/**/
#
# define AGPACK_PP_SEQ_DETAIL_IS_EMPTY_SIZE(size) \
	AGPACK_PP_COMPL \
		( \
		AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY_SIZE(size) \
		) \
/**/
#
# define AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq) \
	AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY_SIZE(AGPACK_PP_SEQ_DETAIL_EMPTY_SIZE(seq)) \
/**/
#
# define AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY_SIZE(size) \
	AGPACK_PP_BOOL(size) \
/**/
#
# define AGPACK_PP_SEQ_DETAIL_EMPTY_SIZE(seq) \
	AGPACK_PP_DEC(AGPACK_PP_SEQ_SIZE(seq (nil))) \
/**/
#
# endif
