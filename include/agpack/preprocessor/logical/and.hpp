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
# ifndef AGPACK_PREPROCESSOR_LOGICAL_AND_HPP
# define AGPACK_PREPROCESSOR_LOGICAL_AND_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/logical/bool.hpp>
# include <agpack/preprocessor/logical/bitand.hpp>
#
# /* AGPACK_PP_AND */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_AND(p, q) AGPACK_PP_BITAND(AGPACK_PP_BOOL(p), AGPACK_PP_BOOL(q))
# else
#    define AGPACK_PP_AND(p, q) AGPACK_PP_AND_I(p, q)
#    define AGPACK_PP_AND_I(p, q) AGPACK_PP_BITAND(AGPACK_PP_BOOL(p), AGPACK_PP_BOOL(q))
# endif
#
# endif
