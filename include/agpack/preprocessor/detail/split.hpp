# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# ifndef AGPACK_PREPROCESSOR_DETAIL_SPLIT_HPP
# define AGPACK_PREPROCESSOR_DETAIL_SPLIT_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_SPLIT */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_SPLIT(n, im) AGPACK_PP_SPLIT_I((n, im))
#    define AGPACK_PP_SPLIT_I(par) AGPACK_PP_SPLIT_II ## par
#    define AGPACK_PP_SPLIT_II(n, a, b) AGPACK_PP_SPLIT_ ## n(a, b)
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_SPLIT(n, im) AGPACK_PP_SPLIT_I(n((im)))
#    define AGPACK_PP_SPLIT_I(n) AGPACK_PP_SPLIT_ID(AGPACK_PP_SPLIT_II_ ## n)
#    define AGPACK_PP_SPLIT_II_0(s) AGPACK_PP_SPLIT_ID(AGPACK_PP_SPLIT_0 s)
#    define AGPACK_PP_SPLIT_II_1(s) AGPACK_PP_SPLIT_ID(AGPACK_PP_SPLIT_1 s)
#    define AGPACK_PP_SPLIT_ID(id) id
# else
#    define AGPACK_PP_SPLIT(n, im) AGPACK_PP_SPLIT_I(n)(im)
#    define AGPACK_PP_SPLIT_I(n) AGPACK_PP_SPLIT_ ## n
# endif
#
# define AGPACK_PP_SPLIT_0(a, b) a
# define AGPACK_PP_SPLIT_1(a, b) b
#
# endif
