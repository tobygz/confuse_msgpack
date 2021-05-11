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
# ifndef AGPACK_PREPROCESSOR_DEBUG_ASSERT_HPP
# define AGPACK_PREPROCESSOR_DEBUG_ASSERT_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/expr_iif.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/logical/not.hpp>
# include <agpack/preprocessor/tuple/eat.hpp>
#
# /* AGPACK_PP_ASSERT */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ASSERT AGPACK_PP_ASSERT_D
# else
#    define AGPACK_PP_ASSERT(cond) AGPACK_PP_ASSERT_D(cond)
# endif
#
# define AGPACK_PP_ASSERT_D(cond) AGPACK_PP_IIF(AGPACK_PP_NOT(cond), AGPACK_PP_ASSERT_ERROR, AGPACK_PP_TUPLE_EAT_1)(...)
# define AGPACK_PP_ASSERT_ERROR(x, y, z)
#
# /* AGPACK_PP_ASSERT_MSG */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ASSERT_MSG AGPACK_PP_ASSERT_MSG_D
# else
#    define AGPACK_PP_ASSERT_MSG(cond, msg) AGPACK_PP_ASSERT_MSG_D(cond, msg)
# endif
#
# define AGPACK_PP_ASSERT_MSG_D(cond, msg) AGPACK_PP_EXPR_IIF(AGPACK_PP_NOT(cond), msg)
#
# endif
