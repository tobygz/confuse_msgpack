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
# ifndef AGPACK_PREPROCESSOR_ARRAY_POP_BACK_HPP
# define AGPACK_PREPROCESSOR_ARRAY_POP_BACK_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/array/elem.hpp>
# include <agpack/preprocessor/array/size.hpp>
# include <agpack/preprocessor/repetition/enum.hpp>
# include <agpack/preprocessor/repetition/deduce_z.hpp>
#
# /* AGPACK_PP_ARRAY_POP_BACK */
#
# define AGPACK_PP_ARRAY_POP_BACK(array) AGPACK_PP_ARRAY_POP_BACK_Z(AGPACK_PP_DEDUCE_Z(), array)
#
# /* AGPACK_PP_ARRAY_POP_BACK_Z */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ARRAY_POP_BACK_Z(z, array) AGPACK_PP_ARRAY_POP_BACK_I(z, AGPACK_PP_ARRAY_SIZE(array), array)
# else
#    define AGPACK_PP_ARRAY_POP_BACK_Z(z, array) AGPACK_PP_ARRAY_POP_BACK_Z_D(z, array)
#    define AGPACK_PP_ARRAY_POP_BACK_Z_D(z, array) AGPACK_PP_ARRAY_POP_BACK_I(z, AGPACK_PP_ARRAY_SIZE(array), array)
# endif
#
# define AGPACK_PP_ARRAY_POP_BACK_I(z, size, array) (AGPACK_PP_DEC(size), (AGPACK_PP_ENUM_ ## z(AGPACK_PP_DEC(size), AGPACK_PP_ARRAY_POP_BACK_M, array)))
# define AGPACK_PP_ARRAY_POP_BACK_M(z, n, data) AGPACK_PP_ARRAY_ELEM(n, data)
#
# endif
