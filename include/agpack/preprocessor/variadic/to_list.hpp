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
# ifndef AGPACK_PREPROCESSOR_VARIADIC_TO_LIST_HPP
# define AGPACK_PREPROCESSOR_VARIADIC_TO_LIST_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/to_list.hpp>
#
# /* AGPACK_PP_VARIADIC_TO_LIST */
#
# if AGPACK_PP_VARIADICS
#    define AGPACK_PP_VARIADIC_TO_LIST(...) AGPACK_PP_TUPLE_TO_LIST((__VA_ARGS__))
# endif
#
# endif
