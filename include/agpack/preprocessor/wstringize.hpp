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
# ifndef AGPACK_PREPROCESSOR_WSTRINGIZE_HPP
# define AGPACK_PREPROCESSOR_WSTRINGIZE_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_WSTRINGIZE */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_WSTRINGIZE(text) AGPACK_PP_WSTRINGIZE_I(text)
# else
#    define AGPACK_PP_WSTRINGIZE(text) AGPACK_PP_WSTRINGIZE_OO((text))
#    define AGPACK_PP_WSTRINGIZE_OO(par) AGPACK_PP_WSTRINGIZE_I ## par
# endif
#
# define AGPACK_PP_WSTRINGIZE_I(text) AGPACK_PP_WSTRINGIZE_II(#text)
# define AGPACK_PP_WSTRINGIZE_II(str) L ## str
#
# endif
