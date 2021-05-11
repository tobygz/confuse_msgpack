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
# ifndef AGPACK_PREPROCESSOR_SEQ_FOR_EACH_HPP
# define AGPACK_PREPROCESSOR_SEQ_FOR_EACH_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/repetition/for.hpp>
# include <agpack/preprocessor/seq/seq.hpp>
# include <agpack/preprocessor/seq/size.hpp>
# include <agpack/preprocessor/seq/detail/is_empty.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_SEQ_FOR_EACH */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_FOR_EACH(macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK(macro, data, seq)
# else
#    define AGPACK_PP_SEQ_FOR_EACH(macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_D(macro, data, seq)
#    define AGPACK_PP_SEQ_FOR_EACH_D(macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK(macro, data, seq)
# endif
#
#    define AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_EXEC(macro, data, seq) AGPACK_PP_FOR((macro, data, seq, AGPACK_PP_SEQ_SIZE(seq)), AGPACK_PP_SEQ_FOR_EACH_P, AGPACK_PP_SEQ_FOR_EACH_O, AGPACK_PP_SEQ_FOR_EACH_M)
#    define AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_EMPTY(macro, data, seq)
#
#    define AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK(macro, data, seq) \
		AGPACK_PP_IIF \
			( \
			AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq), \
			AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_EXEC, \
			AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_EMPTY \
			) \
		(macro, data, seq) \
/**/
#
# define AGPACK_PP_SEQ_FOR_EACH_P(r, x) AGPACK_PP_TUPLE_ELEM(4, 3, x)
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_SEQ_FOR_EACH_O(r, x) AGPACK_PP_SEQ_FOR_EACH_O_I x
# else
#    define AGPACK_PP_SEQ_FOR_EACH_O(r, x) AGPACK_PP_SEQ_FOR_EACH_O_I(AGPACK_PP_TUPLE_ELEM(4, 0, x), AGPACK_PP_TUPLE_ELEM(4, 1, x), AGPACK_PP_TUPLE_ELEM(4, 2, x), AGPACK_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define AGPACK_PP_SEQ_FOR_EACH_O_I(macro, data, seq, sz) \
	AGPACK_PP_SEQ_FOR_EACH_O_I_DEC(macro, data, seq, AGPACK_PP_DEC(sz)) \
/**/
# define AGPACK_PP_SEQ_FOR_EACH_O_I_DEC(macro, data, seq, sz) \
	( \
	macro, \
	data, \
	AGPACK_PP_IF \
		( \
		sz, \
		AGPACK_PP_SEQ_FOR_EACH_O_I_TAIL, \
		AGPACK_PP_SEQ_FOR_EACH_O_I_NIL \
		) \
	(seq), \
	sz \
	) \
/**/
# define AGPACK_PP_SEQ_FOR_EACH_O_I_TAIL(seq) AGPACK_PP_SEQ_TAIL(seq)
# define AGPACK_PP_SEQ_FOR_EACH_O_I_NIL(seq) AGPACK_PP_NIL
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_SEQ_FOR_EACH_M(r, x) AGPACK_PP_SEQ_FOR_EACH_M_IM(r, AGPACK_PP_TUPLE_REM_4 x)
#    define AGPACK_PP_SEQ_FOR_EACH_M_IM(r, im) AGPACK_PP_SEQ_FOR_EACH_M_I(r, im)
# else
#    define AGPACK_PP_SEQ_FOR_EACH_M(r, x) AGPACK_PP_SEQ_FOR_EACH_M_I(r, AGPACK_PP_TUPLE_ELEM(4, 0, x), AGPACK_PP_TUPLE_ELEM(4, 1, x), AGPACK_PP_TUPLE_ELEM(4, 2, x), AGPACK_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define AGPACK_PP_SEQ_FOR_EACH_M_I(r, macro, data, seq, sz) macro(r, data, AGPACK_PP_SEQ_HEAD(seq))
#
# /* AGPACK_PP_SEQ_FOR_EACH_R */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_FOR_EACH_R(r, macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_R(r, macro, data, seq)
# else
#    define AGPACK_PP_SEQ_FOR_EACH_R(r, macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_R_I(r, macro, data, seq)
#    define AGPACK_PP_SEQ_FOR_EACH_R_I(r, macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_R(r, macro, data, seq)
# endif
#
#    define AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_EXEC_R(r, macro, data, seq) AGPACK_PP_FOR_ ## r((macro, data, seq, AGPACK_PP_SEQ_SIZE(seq)), AGPACK_PP_SEQ_FOR_EACH_P, AGPACK_PP_SEQ_FOR_EACH_O, AGPACK_PP_SEQ_FOR_EACH_M)
#    define AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_EMPTY_R(r, macro, data, seq)
#
#    define AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_R(r, macro, data, seq) \
		AGPACK_PP_IIF \
			( \
			AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq), \
			AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_EXEC_R, \
			AGPACK_PP_SEQ_FOR_EACH_DETAIL_CHECK_EMPTY_R \
			) \
		(r, macro, data, seq) \
/**/
#
# endif
