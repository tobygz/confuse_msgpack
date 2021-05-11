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
# ifndef AGPACK_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
# define AGPACK_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_EXPR_IIF */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_EXPR_IIF(bit, expr) AGPACK_PP_EXPR_IIF_I(bit, expr)
# else
#    define AGPACK_PP_EXPR_IIF(bit, expr) AGPACK_PP_EXPR_IIF_OO((bit, expr))
#    define AGPACK_PP_EXPR_IIF_OO(par) AGPACK_PP_EXPR_IIF_I ## par
# endif
#
# define AGPACK_PP_EXPR_IIF_I(bit, expr) AGPACK_PP_EXPR_IIF_ ## bit(expr)
#
# define AGPACK_PP_EXPR_IIF_0(expr)
# define AGPACK_PP_EXPR_IIF_1(expr) expr
#
# endif
