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
# ifndef AGPACK_PREPROCESSOR_CONTROL_IF_HPP
# define AGPACK_PREPROCESSOR_CONTROL_IF_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/logical/bool.hpp>
#
# /* AGPACK_PP_IF */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_IF(cond, t, f) AGPACK_PP_IIF(AGPACK_PP_BOOL(cond), t, f)
# else
#    define AGPACK_PP_IF(cond, t, f) AGPACK_PP_IF_I(cond, t, f)
#    define AGPACK_PP_IF_I(cond, t, f) AGPACK_PP_IIF(AGPACK_PP_BOOL(cond), t, f)
# endif
#
# endif
