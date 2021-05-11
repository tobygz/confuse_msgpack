# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_FACILITIES_EXPAND_HPP
# define AGPACK_PREPROCESSOR_FACILITIES_EXPAND_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC() && ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_DMC()
#    define AGPACK_PP_EXPAND(x) AGPACK_PP_EXPAND_I(x)
# else
#    define AGPACK_PP_EXPAND(x) AGPACK_PP_EXPAND_OO((x))
#    define AGPACK_PP_EXPAND_OO(par) AGPACK_PP_EXPAND_I ## par
# endif
#
# define AGPACK_PP_EXPAND_I(x) x
#
# endif
