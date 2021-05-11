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
# ifndef AGPACK_PREPROCESSOR_LOGICAL_COMPL_HPP
# define AGPACK_PREPROCESSOR_LOGICAL_COMPL_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_COMPL */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_COMPL(x) AGPACK_PP_COMPL_I(x)
# else
#    define AGPACK_PP_COMPL(x) AGPACK_PP_COMPL_OO((x))
#    define AGPACK_PP_COMPL_OO(par) AGPACK_PP_COMPL_I ## par
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_COMPL_I(x) AGPACK_PP_COMPL_ ## x
# else
#    define AGPACK_PP_COMPL_I(x) AGPACK_PP_COMPL_ID(AGPACK_PP_COMPL_ ## x)
#    define AGPACK_PP_COMPL_ID(id) id
# endif
#
# define AGPACK_PP_COMPL_0 1
# define AGPACK_PP_COMPL_1 0
#
# endif
