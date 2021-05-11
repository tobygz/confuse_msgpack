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
# ifndef AGPACK_PREPROCESSOR_LOGICAL_NOT_HPP
# define AGPACK_PREPROCESSOR_LOGICAL_NOT_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/logical/bool.hpp>
# include <agpack/preprocessor/logical/compl.hpp>
#
# /* AGPACK_PP_NOT */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_NOT(x) AGPACK_PP_COMPL(AGPACK_PP_BOOL(x))
# else
#    define AGPACK_PP_NOT(x) AGPACK_PP_NOT_I(x)
#    define AGPACK_PP_NOT_I(x) AGPACK_PP_COMPL(AGPACK_PP_BOOL(x))
# endif
#
# endif
