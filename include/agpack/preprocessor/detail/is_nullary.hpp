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
# ifndef AGPACK_PREPROCESSOR_DETAIL_IS_NULLARY_HPP
# define AGPACK_PREPROCESSOR_DETAIL_IS_NULLARY_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/detail/check.hpp>
#
# /* AGPACK_PP_IS_NULLARY */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_IS_NULLARY(x) AGPACK_PP_CHECK(x, AGPACK_PP_IS_NULLARY_CHECK)
# else
#    define AGPACK_PP_IS_NULLARY(x) AGPACK_PP_IS_NULLARY_I(x)
#    define AGPACK_PP_IS_NULLARY_I(x) AGPACK_PP_CHECK(x, AGPACK_PP_IS_NULLARY_CHECK)
# endif
#
# define AGPACK_PP_IS_NULLARY_CHECK() 1
# define AGPACK_PP_CHECK_RESULT_AGPACK_PP_IS_NULLARY_CHECK 0, AGPACK_PP_NIL
#
# endif
