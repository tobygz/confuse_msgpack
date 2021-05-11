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
# ifndef AGPACK_PREPROCESSOR_LOGICAL_BITXOR_HPP
# define AGPACK_PREPROCESSOR_LOGICAL_BITXOR_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_BITXOR */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_BITXOR(x, y) AGPACK_PP_BITXOR_I(x, y)
# else
#    define AGPACK_PP_BITXOR(x, y) AGPACK_PP_BITXOR_OO((x, y))
#    define AGPACK_PP_BITXOR_OO(par) AGPACK_PP_BITXOR_I ## par
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_BITXOR_I(x, y) AGPACK_PP_BITXOR_ ## x ## y
# else
#    define AGPACK_PP_BITXOR_I(x, y) AGPACK_PP_BITXOR_ID(AGPACK_PP_BITXOR_ ## x ## y)
#    define AGPACK_PP_BITXOR_ID(id) id
# endif
#
# define AGPACK_PP_BITXOR_00 0
# define AGPACK_PP_BITXOR_01 1
# define AGPACK_PP_BITXOR_10 1
# define AGPACK_PP_BITXOR_11 0
#
# endif
