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
# ifndef AGPACK_PREPROCESSOR_LOGICAL_BITNOR_HPP
# define AGPACK_PREPROCESSOR_LOGICAL_BITNOR_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_BITNOR */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_BITNOR(x, y) AGPACK_PP_BITNOR_I(x, y)
# else
#    define AGPACK_PP_BITNOR(x, y) AGPACK_PP_BITNOR_OO((x, y))
#    define AGPACK_PP_BITNOR_OO(par) AGPACK_PP_BITNOR_I ## par
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_BITNOR_I(x, y) AGPACK_PP_BITNOR_ ## x ## y
# else
#    define AGPACK_PP_BITNOR_I(x, y) AGPACK_PP_BITNOR_ID(AGPACK_PP_BITNOR_ ## x ## y)
#    define AGPACK_PP_BITNOR_ID(id) id
# endif
#
# define AGPACK_PP_BITNOR_00 1
# define AGPACK_PP_BITNOR_01 0
# define AGPACK_PP_BITNOR_10 0
# define AGPACK_PP_BITNOR_11 0
#
# endif
