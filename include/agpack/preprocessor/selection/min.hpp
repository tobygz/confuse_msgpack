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
# ifndef AGPACK_PREPROCESSOR_SELECTION_MIN_HPP
# define AGPACK_PREPROCESSOR_SELECTION_MIN_HPP
#
# include <agpack/preprocessor/comparison/less_equal.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/iif.hpp>
#
# /* AGPACK_PP_MIN */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_MIN(x, y) AGPACK_PP_IIF(AGPACK_PP_LESS_EQUAL(y, x), y, x)
# else
#    define AGPACK_PP_MIN(x, y) AGPACK_PP_MIN_I(x, y)
#    define AGPACK_PP_MIN_I(x, y) AGPACK_PP_IIF(AGPACK_PP_LESS_EQUAL(y, x), y, x)
# endif
#
# /* AGPACK_PP_MIN_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_MIN_D(d, x, y) AGPACK_PP_IIF(AGPACK_PP_LESS_EQUAL_D(d, y, x), y, x)
# else
#    define AGPACK_PP_MIN_D(d, x, y) AGPACK_PP_MIN_D_I(d, x, y)
#    define AGPACK_PP_MIN_D_I(d, x, y) AGPACK_PP_IIF(AGPACK_PP_LESS_EQUAL_D(d, y, x), y, x)
# endif
#
# endif
