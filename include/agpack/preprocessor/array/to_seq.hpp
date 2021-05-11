# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_ARRAY_TO_SEQ_HPP
# define AGPACK_PREPROCESSOR_ARRAY_TO_SEQ_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/array/size.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/tuple/to_seq.hpp>
#
# /* AGPACK_PP_ARRAY_TO_SEQ */
#
#    define AGPACK_PP_ARRAY_TO_SEQ(array) \
		AGPACK_PP_IF \
			( \
			AGPACK_PP_ARRAY_SIZE(array), \
			AGPACK_PP_ARRAY_TO_SEQ_DO, \
			AGPACK_PP_ARRAY_TO_SEQ_EMPTY \
			) \
		(array) \
/**/
#    define AGPACK_PP_ARRAY_TO_SEQ_EMPTY(array)
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_ARRAY_TO_SEQ_DO(array) AGPACK_PP_ARRAY_TO_SEQ_I(AGPACK_PP_TUPLE_TO_SEQ, array)
#    define AGPACK_PP_ARRAY_TO_SEQ_I(m, args) AGPACK_PP_ARRAY_TO_SEQ_II(m, args)
#    define AGPACK_PP_ARRAY_TO_SEQ_II(m, args) AGPACK_PP_CAT(m ## args,)
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_ARRAY_TO_SEQ_DO(array) AGPACK_PP_ARRAY_TO_SEQ_I(array)
#    define AGPACK_PP_ARRAY_TO_SEQ_I(array) AGPACK_PP_TUPLE_TO_SEQ ## array
# else
#    define AGPACK_PP_ARRAY_TO_SEQ_DO(array) AGPACK_PP_TUPLE_TO_SEQ array
# endif
#
# endif
