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
# ifndef AGPACK_PREPROCESSOR_TUPLE_SIZE_HPP
# define AGPACK_PREPROCESSOR_TUPLE_SIZE_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/variadic/size.hpp>
#
# if AGPACK_PP_VARIADICS
#    if AGPACK_PP_VARIADICS_MSVC
#        define AGPACK_PP_TUPLE_SIZE(tuple) AGPACK_PP_CAT(AGPACK_PP_VARIADIC_SIZE tuple,)
#    else
#        define AGPACK_PP_TUPLE_SIZE(tuple) AGPACK_PP_VARIADIC_SIZE tuple
#    endif
# endif
#
# endif
