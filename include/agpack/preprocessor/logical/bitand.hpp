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
# ifndef AGPACK_PREPROCESSOR_LOGICAL_BITAND_HPP
# define AGPACK_PREPROCESSOR_LOGICAL_BITAND_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_BITAND */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_BITAND(x, y) AGPACK_PP_BITAND_I(x, y)
# else
#    define AGPACK_PP_BITAND(x, y) AGPACK_PP_BITAND_OO((x, y))
#    define AGPACK_PP_BITAND_OO(par) AGPACK_PP_BITAND_I ## par
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_BITAND_I(x, y) AGPACK_PP_BITAND_ ## x ## y
# else
#    define AGPACK_PP_BITAND_I(x, y) AGPACK_PP_BITAND_ID(AGPACK_PP_BITAND_ ## x ## y)
#    define AGPACK_PP_BITAND_ID(res) res
# endif
#
# define AGPACK_PP_BITAND_00 0
# define AGPACK_PP_BITAND_01 0
# define AGPACK_PP_BITAND_10 0
# define AGPACK_PP_BITAND_11 1
#
# endif
