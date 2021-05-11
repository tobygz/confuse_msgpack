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
# ifndef AGPACK_PREPROCESSOR_STRINGIZE_HPP
# define AGPACK_PREPROCESSOR_STRINGIZE_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_STRINGIZE */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_STRINGIZE(text) AGPACK_PP_STRINGIZE_A((text))
#    define AGPACK_PP_STRINGIZE_A(arg) AGPACK_PP_STRINGIZE_I arg
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_STRINGIZE(text) AGPACK_PP_STRINGIZE_OO((text))
#    define AGPACK_PP_STRINGIZE_OO(par) AGPACK_PP_STRINGIZE_I ## par
# else
#    define AGPACK_PP_STRINGIZE(text) AGPACK_PP_STRINGIZE_I(text)
# endif
#
# define AGPACK_PP_STRINGIZE_I(text) #text
#
# endif
