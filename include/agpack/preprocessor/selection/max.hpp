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
# ifndef AGPACK_PREPROCESSOR_SELECTION_MAX_HPP
# define AGPACK_PREPROCESSOR_SELECTION_MAX_HPP
#
# include <agpack/preprocessor/comparison/less_equal.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/iif.hpp>
#
# /* AGPACK_PP_MAX */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_MAX(x, y) AGPACK_PP_IIF(AGPACK_PP_LESS_EQUAL(x, y), y, x)
# else
#    define AGPACK_PP_MAX(x, y) AGPACK_PP_MAX_I(x, y)
#    define AGPACK_PP_MAX_I(x, y) AGPACK_PP_IIF(AGPACK_PP_LESS_EQUAL(x, y), y, x)
# endif
#
# /* AGPACK_PP_MAX_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_MAX_D(d, x, y) AGPACK_PP_IIF(AGPACK_PP_LESS_EQUAL_D(d, x, y), y, x)
# else
#    define AGPACK_PP_MAX_D(d, x, y) AGPACK_PP_MAX_D_I(d, x, y)
#    define AGPACK_PP_MAX_D_I(d, x, y) AGPACK_PP_IIF(AGPACK_PP_LESS_EQUAL_D(d, x, y), y, x)
# endif
#
# endif
