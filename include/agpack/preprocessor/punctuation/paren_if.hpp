# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_PUNCTUATION_PAREN_IF_HPP
# define AGPACK_PREPROCESSOR_PUNCTUATION_PAREN_IF_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/facilities/empty.hpp>
# include <agpack/preprocessor/punctuation/paren.hpp>
#
# /* AGPACK_PP_LPAREN_IF */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LPAREN_IF(cond) AGPACK_PP_IF(cond, AGPACK_PP_LPAREN, AGPACK_PP_EMPTY)()
# else
#    define AGPACK_PP_LPAREN_IF(cond) AGPACK_PP_LPAREN_IF_I(cond)
#    define AGPACK_PP_LPAREN_IF_I(cond) AGPACK_PP_IF(cond, AGPACK_PP_LPAREN, AGPACK_PP_EMPTY)()
# endif
#
# /* AGPACK_PP_RPAREN_IF */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_RPAREN_IF(cond) AGPACK_PP_IF(cond, AGPACK_PP_RPAREN, AGPACK_PP_EMPTY)()
# else
#    define AGPACK_PP_RPAREN_IF(cond) AGPACK_PP_RPAREN_IF_I(cond)
#    define AGPACK_PP_RPAREN_IF_I(cond) AGPACK_PP_IF(cond, AGPACK_PP_RPAREN, AGPACK_PP_EMPTY)()
# endif
#
# endif
