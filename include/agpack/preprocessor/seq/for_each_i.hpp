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
# ifndef AGPACK_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
# define AGPACK_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/arithmetic/inc.hpp>
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
# /* AGPACK_PP_SEQ_FOR_EACH_I */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_FOR_EACH_I(macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_I_DETAIL_CHECK(macro, data, seq)
# else
#    define AGPACK_PP_SEQ_FOR_EACH_I(macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_I_I(macro, data, seq)
#    define AGPACK_PP_SEQ_FOR_EACH_I_I(macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_I_DETAIL_CHECK(macro, data, seq)
# endif
#
#    define AGPACK_PP_SEQ_FOR_EACH_I_DETAIL_CHECK_EXEC(macro, data, seq) AGPACK_PP_FOR((macro, data, seq, 0, AGPACK_PP_SEQ_SIZE(seq)), AGPACK_PP_SEQ_FOR_EACH_I_P, AGPACK_PP_SEQ_FOR_EACH_I_O, AGPACK_PP_SEQ_FOR_EACH_I_M)
#    define AGPACK_PP_SEQ_FOR_EACH_I_DETAIL_CHECK_EMPTY(macro, data, seq)
#
#    define AGPACK_PP_SEQ_FOR_EACH_I_DETAIL_CHECK(macro, data, seq) \
		AGPACK_PP_IIF \
			( \
			AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq), \
			AGPACK_PP_SEQ_FOR_EACH_I_DETAIL_CHECK_EXEC, \
			AGPACK_PP_SEQ_FOR_EACH_I_DETAIL_CHECK_EMPTY \
			) \
		(macro, data, seq) \
/**/
#
# define AGPACK_PP_SEQ_FOR_EACH_I_P(r, x) AGPACK_PP_TUPLE_ELEM(5, 4, x)
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_SEQ_FOR_EACH_I_O(r, x) AGPACK_PP_SEQ_FOR_EACH_I_O_I x
# else
#    define AGPACK_PP_SEQ_FOR_EACH_I_O(r, x) AGPACK_PP_SEQ_FOR_EACH_I_O_I(AGPACK_PP_TUPLE_ELEM(5, 0, x), AGPACK_PP_TUPLE_ELEM(5, 1, x), AGPACK_PP_TUPLE_ELEM(5, 2, x), AGPACK_PP_TUPLE_ELEM(5, 3, x), AGPACK_PP_TUPLE_ELEM(5, 4, x))
# endif
#
# define AGPACK_PP_SEQ_FOR_EACH_I_O_I(macro, data, seq, i, sz) \
	AGPACK_PP_SEQ_FOR_EACH_I_O_I_DEC(macro, data, seq, i, AGPACK_PP_DEC(sz)) \
/**/
# define AGPACK_PP_SEQ_FOR_EACH_I_O_I_DEC(macro, data, seq, i, sz) \
	( \
	macro, \
	data, \
	AGPACK_PP_IF \
		( \
		sz, \
		AGPACK_PP_SEQ_FOR_EACH_I_O_I_TAIL, \
		AGPACK_PP_SEQ_FOR_EACH_I_O_I_NIL \
		) \
	(seq), \
	AGPACK_PP_INC(i), \
	sz \
	) \
/**/
# define AGPACK_PP_SEQ_FOR_EACH_I_O_I_TAIL(seq) AGPACK_PP_SEQ_TAIL(seq)
# define AGPACK_PP_SEQ_FOR_EACH_I_O_I_NIL(seq) AGPACK_PP_NIL
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_SEQ_FOR_EACH_I_M(r, x) AGPACK_PP_SEQ_FOR_EACH_I_M_IM(r, AGPACK_PP_TUPLE_REM_5 x)
#    define AGPACK_PP_SEQ_FOR_EACH_I_M_IM(r, im) AGPACK_PP_SEQ_FOR_EACH_I_M_I(r, im)
# else
#    define AGPACK_PP_SEQ_FOR_EACH_I_M(r, x) AGPACK_PP_SEQ_FOR_EACH_I_M_I(r, AGPACK_PP_TUPLE_ELEM(5, 0, x), AGPACK_PP_TUPLE_ELEM(5, 1, x), AGPACK_PP_TUPLE_ELEM(5, 2, x), AGPACK_PP_TUPLE_ELEM(5, 3, x), AGPACK_PP_TUPLE_ELEM(5, 4, x))
# endif
#
# define AGPACK_PP_SEQ_FOR_EACH_I_M_I(r, macro, data, seq, i, sz) macro(r, data, i, AGPACK_PP_SEQ_HEAD(seq))
#
# /* AGPACK_PP_SEQ_FOR_EACH_I_R */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK(r, macro, data, seq)
# else
#    define AGPACK_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq)
#    define AGPACK_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq) AGPACK_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK(r, macro, data, seq)
# endif
#
#    define AGPACK_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK_EXEC(r, macro, data, seq) AGPACK_PP_FOR_ ## r((macro, data, seq, 0, AGPACK_PP_SEQ_SIZE(seq)), AGPACK_PP_SEQ_FOR_EACH_I_P, AGPACK_PP_SEQ_FOR_EACH_I_O, AGPACK_PP_SEQ_FOR_EACH_I_M)
#    define AGPACK_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK_EMPTY(r, macro, data, seq)
#
#    define AGPACK_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK(r, macro, data, seq) \
		AGPACK_PP_IIF \
			( \
			AGPACK_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq), \
			AGPACK_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK_EXEC, \
			AGPACK_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK_EMPTY \
			) \
		(r, macro, data, seq) \
/**/
#
# endif
