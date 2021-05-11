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
# ifndef AGPACK_PREPROCESSOR_CONTROL_IIF_HPP
# define AGPACK_PREPROCESSOR_CONTROL_IIF_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_IIF(bit, t, f) AGPACK_PP_IIF_I(bit, t, f)
# else
#    define AGPACK_PP_IIF(bit, t, f) AGPACK_PP_IIF_OO((bit, t, f))
#    define AGPACK_PP_IIF_OO(par) AGPACK_PP_IIF_I ## par
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_IIF_I(bit, t, f) AGPACK_PP_IIF_ ## bit(t, f)
# else
#    define AGPACK_PP_IIF_I(bit, t, f) AGPACK_PP_IIF_II(AGPACK_PP_IIF_ ## bit(t, f))
#    define AGPACK_PP_IIF_II(id) id
# endif
#
# define AGPACK_PP_IIF_0(t, f) f
# define AGPACK_PP_IIF_1(t, f) t
#
# endif
