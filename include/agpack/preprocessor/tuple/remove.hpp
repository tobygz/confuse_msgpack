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
# ifndef AGPACK_PREPROCESSOR_TUPLE_REMOVE_HPP
# define AGPACK_PREPROCESSOR_TUPLE_REMOVE_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if AGPACK_PP_VARIADICS
#
# include <agpack/preprocessor/array/remove.hpp>
# include <agpack/preprocessor/array/to_tuple.hpp>
# include <agpack/preprocessor/comparison/greater.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/tuple/size.hpp>
# include <agpack/preprocessor/tuple/to_array.hpp>
#
# /* AGPACK_PP_TUPLE_REMOVE */
#
# define AGPACK_PP_TUPLE_REMOVE(tuple, i) \
	AGPACK_PP_IIF \
		( \
		AGPACK_PP_GREATER(AGPACK_PP_TUPLE_SIZE(tuple),1), \
		AGPACK_PP_TUPLE_REMOVE_EXEC, \
		AGPACK_PP_TUPLE_REMOVE_RETURN \
		) \
	(tuple, i) \
/**/
#
# define AGPACK_PP_TUPLE_REMOVE_EXEC(tuple, i) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_REMOVE(AGPACK_PP_TUPLE_TO_ARRAY(tuple), i)) \
/**/
#
# define AGPACK_PP_TUPLE_REMOVE_RETURN(tuple, i) tuple
#
# /* AGPACK_PP_TUPLE_REMOVE_D */
#
# define AGPACK_PP_TUPLE_REMOVE_D(d, tuple, i) \
	AGPACK_PP_IIF \
		( \
		AGPACK_PP_GREATER_D(d, AGPACK_PP_TUPLE_SIZE(tuple), 1), \
		AGPACK_PP_TUPLE_REMOVE_D_EXEC, \
		AGPACK_PP_TUPLE_REMOVE_D_RETURN \
		) \
	(d, tuple, i) \
/**/
#
# define AGPACK_PP_TUPLE_REMOVE_D_EXEC(d, tuple, i) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_REMOVE_D(d, AGPACK_PP_TUPLE_TO_ARRAY(tuple), i)) \
/**/
#
# define AGPACK_PP_TUPLE_REMOVE_D_RETURN(d, tuple, i) tuple
#
# endif // AGPACK_PP_VARIADICS
#
# endif // AGPACK_PREPROCESSOR_TUPLE_REMOVE_HPP
