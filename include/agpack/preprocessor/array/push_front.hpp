# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_ARRAY_PUSH_FRONT_HPP
# define AGPACK_PREPROCESSOR_ARRAY_PUSH_FRONT_HPP
#
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/array/data.hpp>
# include <agpack/preprocessor/array/size.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/punctuation/comma_if.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
# include <agpack/preprocessor/array/detail/get_data.hpp>
#
# /* AGPACK_PP_ARRAY_PUSH_FRONT */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ARRAY_PUSH_FRONT(array, elem) AGPACK_PP_ARRAY_PUSH_FRONT_I(AGPACK_PP_ARRAY_SIZE(array), AGPACK_PP_ARRAY_DATA(array), elem)
# else
#    define AGPACK_PP_ARRAY_PUSH_FRONT(array, elem) AGPACK_PP_ARRAY_PUSH_FRONT_D(array, elem)
#    define AGPACK_PP_ARRAY_PUSH_FRONT_D(array, elem) AGPACK_PP_ARRAY_PUSH_FRONT_I(AGPACK_PP_ARRAY_SIZE(array), AGPACK_PP_ARRAY_DATA(array), elem)
# endif
#
# define AGPACK_PP_ARRAY_PUSH_FRONT_I(size, data, elem) (AGPACK_PP_INC(size), (elem AGPACK_PP_COMMA_IF(size) AGPACK_PP_ARRAY_DETAIL_GET_DATA(size,data)))
#
# endif
