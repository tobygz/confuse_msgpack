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
# ifndef AGPACK_PREPROCESSOR_CAT_HPP
# define AGPACK_PREPROCESSOR_CAT_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_CAT */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_CAT(a, b) AGPACK_PP_CAT_I(a, b)
# else
#    define AGPACK_PP_CAT(a, b) AGPACK_PP_CAT_OO((a, b))
#    define AGPACK_PP_CAT_OO(par) AGPACK_PP_CAT_I ## par
# endif
#
# if (~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()) || (defined(__INTEL_COMPILER) && __INTEL_COMPILER >= 1700)
#    define AGPACK_PP_CAT_I(a, b) a ## b
# else
#    define AGPACK_PP_CAT_I(a, b) AGPACK_PP_CAT_II(~, a ## b)
#    define AGPACK_PP_CAT_II(p, res) res
# endif
#
# endif
