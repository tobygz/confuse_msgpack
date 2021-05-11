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
# ifndef AGPACK_PREPROCESSOR_TUPLE_INSERT_HPP
# define AGPACK_PREPROCESSOR_TUPLE_INSERT_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if AGPACK_PP_VARIADICS
#
# include <agpack/preprocessor/array/insert.hpp>
# include <agpack/preprocessor/array/to_tuple.hpp>
# include <agpack/preprocessor/tuple/to_array.hpp>
#
# /* AGPACK_PP_TUPLE_INSERT */
#
# define AGPACK_PP_TUPLE_INSERT(tuple, i, elem) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_INSERT(AGPACK_PP_TUPLE_TO_ARRAY(tuple), i, elem)) \
/**/
#
# /* AGPACK_PP_TUPLE_INSERT_D */
#
# define AGPACK_PP_TUPLE_INSERT_D(d, tuple, i, elem) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_INSERT_D(d, AGPACK_PP_TUPLE_TO_ARRAY(tuple), i, elem)) \
/**/
#
# endif // AGPACK_PP_VARIADICS
#
# endif // AGPACK_PREPROCESSOR_TUPLE_INSERT_HPP
