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
# ifndef AGPACK_PREPROCESSOR_ARRAY_ELEM_HPP
# define AGPACK_PREPROCESSOR_ARRAY_ELEM_HPP
#
# include <agpack/preprocessor/array/data.hpp>
# include <agpack/preprocessor/array/size.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_ARRAY_ELEM */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ARRAY_ELEM(i, array) AGPACK_PP_TUPLE_ELEM(AGPACK_PP_ARRAY_SIZE(array), i, AGPACK_PP_ARRAY_DATA(array))
# else
#    define AGPACK_PP_ARRAY_ELEM(i, array) AGPACK_PP_ARRAY_ELEM_I(i, array)
#    define AGPACK_PP_ARRAY_ELEM_I(i, array) AGPACK_PP_TUPLE_ELEM(AGPACK_PP_ARRAY_SIZE(array), i, AGPACK_PP_ARRAY_DATA(array))
# endif
#
# endif
