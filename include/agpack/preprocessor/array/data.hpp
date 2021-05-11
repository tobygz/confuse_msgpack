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
# ifndef AGPACK_PREPROCESSOR_ARRAY_DATA_HPP
# define AGPACK_PREPROCESSOR_ARRAY_DATA_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_ARRAY_DATA */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ARRAY_DATA(array) AGPACK_PP_TUPLE_ELEM(2, 1, array)
# else
#    define AGPACK_PP_ARRAY_DATA(array) AGPACK_PP_ARRAY_DATA_I(array)
#    define AGPACK_PP_ARRAY_DATA_I(array) AGPACK_PP_ARRAY_DATA_II array
#    define AGPACK_PP_ARRAY_DATA_II(size, data) data
# endif
#
# endif
