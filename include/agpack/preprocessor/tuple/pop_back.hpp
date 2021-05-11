# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2013.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_TUPLE_POP_BACK_HPP
# define AGPACK_PREPROCESSOR_TUPLE_POP_BACK_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if AGPACK_PP_VARIADICS
#
# include <agpack/preprocessor/array/pop_back.hpp>
# include <agpack/preprocessor/array/to_tuple.hpp>
# include <agpack/preprocessor/comparison/greater.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/tuple/size.hpp>
# include <agpack/preprocessor/tuple/to_array.hpp>
#
# /* AGPACK_PP_TUPLE_POP_BACK */
#
# define AGPACK_PP_TUPLE_POP_BACK(tuple) \
	AGPACK_PP_IIF \
		( \
		AGPACK_PP_GREATER(AGPACK_PP_TUPLE_SIZE(tuple),1), \
		AGPACK_PP_TUPLE_POP_BACK_EXEC, \
		AGPACK_PP_TUPLE_POP_BACK_RETURN \
		) \
	(tuple) \
/**/
#
# define AGPACK_PP_TUPLE_POP_BACK_EXEC(tuple) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_POP_BACK(AGPACK_PP_TUPLE_TO_ARRAY(tuple))) \
/**/
#
# define AGPACK_PP_TUPLE_POP_BACK_RETURN(tuple) tuple
#
# /* AGPACK_PP_TUPLE_POP_BACK_Z */
#
# define AGPACK_PP_TUPLE_POP_BACK_Z(z, tuple) \
	AGPACK_PP_IIF \
		( \
		AGPACK_PP_GREATER(AGPACK_PP_TUPLE_SIZE(tuple),1), \
		AGPACK_PP_TUPLE_POP_BACK_Z_EXEC, \
		AGPACK_PP_TUPLE_POP_BACK_Z_RETURN \
		) \
	(z, tuple) \
/**/
#
# define AGPACK_PP_TUPLE_POP_BACK_Z_EXEC(z, tuple) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_POP_BACK_Z(z, AGPACK_PP_TUPLE_TO_ARRAY(tuple))) \
/**/
#
# define AGPACK_PP_TUPLE_POP_BACK_Z_RETURN(z, tuple) tuple
#
# endif // AGPACK_PP_VARIADICS
#
# endif // AGPACK_PREPROCESSOR_TUPLE_POP_BACK_HPP
