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
# ifndef AGPACK_PREPROCESSOR_COMPARISON_EQUAL_HPP
# define AGPACK_PREPROCESSOR_COMPARISON_EQUAL_HPP
#
# include <agpack/preprocessor/comparison/not_equal.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/logical/compl.hpp>
#
# /* AGPACK_PP_EQUAL */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_EQUAL(x, y) AGPACK_PP_COMPL(AGPACK_PP_NOT_EQUAL(x, y))
# else
#    define AGPACK_PP_EQUAL(x, y) AGPACK_PP_EQUAL_I(x, y)
#    define AGPACK_PP_EQUAL_I(x, y) AGPACK_PP_COMPL(AGPACK_PP_NOT_EQUAL(x, y))
# endif
#
# /* AGPACK_PP_EQUAL_D */
#
# define AGPACK_PP_EQUAL_D(d, x, y) AGPACK_PP_EQUAL(x, y)
#
# endif
