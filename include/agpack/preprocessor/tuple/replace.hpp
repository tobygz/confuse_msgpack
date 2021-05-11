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
# ifndef AGPACK_PREPROCESSOR_TUPLE_REPLACE_HPP
# define AGPACK_PREPROCESSOR_TUPLE_REPLACE_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if AGPACK_PP_VARIADICS
#
# include <agpack/preprocessor/array/replace.hpp>
# include <agpack/preprocessor/array/to_tuple.hpp>
# include <agpack/preprocessor/tuple/to_array.hpp>
#
# /* AGPACK_PP_TUPLE_REPLACE */
#
# define AGPACK_PP_TUPLE_REPLACE(tuple, i, elem) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_REPLACE(AGPACK_PP_TUPLE_TO_ARRAY(tuple), i, elem)) \
/**/
#
# /* AGPACK_PP_TUPLE_REPLACE_D */
#
# define AGPACK_PP_TUPLE_REPLACE_D(d, tuple, i, elem) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_REPLACE_D(d, AGPACK_PP_TUPLE_TO_ARRAY(tuple), i, elem)) \
/**/
#
# endif // AGPACK_PP_VARIADICS
#
# endif // AGPACK_PREPROCESSOR_TUPLE_REPLACE_HPP
