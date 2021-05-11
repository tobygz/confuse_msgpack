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
# ifndef AGPACK_PREPROCESSOR_FACILITIES_APPLY_HPP
# define AGPACK_PREPROCESSOR_FACILITIES_APPLY_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/expr_iif.hpp>
# include <agpack/preprocessor/detail/is_unary.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_APPLY */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_APPLY(x) AGPACK_PP_APPLY_I(x)
#    define AGPACK_PP_APPLY_I(x) AGPACK_PP_EXPR_IIF(AGPACK_PP_IS_UNARY(x), AGPACK_PP_TUPLE_REM_1 x)
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_BCC()
#    define AGPACK_PP_APPLY(x) AGPACK_PP_APPLY_I(x)
#    define AGPACK_PP_APPLY_I(x) AGPACK_PP_APPLY_ ## x
#    define AGPACK_PP_APPLY_(x) x
#    define AGPACK_PP_APPLY_AGPACK_PP_NIL
# else
#    define AGPACK_PP_APPLY(x) AGPACK_PP_EXPR_IIF(AGPACK_PP_IS_UNARY(x), AGPACK_PP_TUPLE_REM_1 x)
# endif
#
# endif
