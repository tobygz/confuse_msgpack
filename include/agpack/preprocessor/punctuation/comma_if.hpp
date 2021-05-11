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
# ifndef AGPACK_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
# define AGPACK_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/facilities/empty.hpp>
# include <agpack/preprocessor/punctuation/comma.hpp>
#
# /* AGPACK_PP_COMMA_IF */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_COMMA_IF(cond) AGPACK_PP_IF(cond, AGPACK_PP_COMMA, AGPACK_PP_EMPTY)()
# else
#    define AGPACK_PP_COMMA_IF(cond) AGPACK_PP_COMMA_IF_I(cond)
#    define AGPACK_PP_COMMA_IF_I(cond) AGPACK_PP_IF(cond, AGPACK_PP_COMMA, AGPACK_PP_EMPTY)()
# endif
#
# endif
