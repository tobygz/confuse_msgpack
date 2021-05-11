# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_SEQ_DETAIL_BINARY_TRANSFORM_HPP
# define AGPACK_PREPROCESSOR_SEQ_DETAIL_BINARY_TRANSFORM_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/eat.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
# include <agpack/preprocessor/variadic/detail/is_single_return.hpp>
#
# /* AGPACK_PP_SEQ_BINARY_TRANSFORM */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_SEQ_BINARY_TRANSFORM(seq) AGPACK_PP_SEQ_BINARY_TRANSFORM_I(, seq)
#    define AGPACK_PP_SEQ_BINARY_TRANSFORM_I(p, seq) AGPACK_PP_SEQ_BINARY_TRANSFORM_II(p ## seq)
#    define AGPACK_PP_SEQ_BINARY_TRANSFORM_II(seq) AGPACK_PP_SEQ_BINARY_TRANSFORM_III(seq)
#    define AGPACK_PP_SEQ_BINARY_TRANSFORM_III(seq) AGPACK_PP_CAT(AGPACK_PP_SEQ_BINARY_TRANSFORM_A seq, 0)
# else
#    define AGPACK_PP_SEQ_BINARY_TRANSFORM(seq) AGPACK_PP_CAT(AGPACK_PP_SEQ_BINARY_TRANSFORM_A seq, 0)
# endif
# if AGPACK_PP_VARIADICS
#    if AGPACK_PP_VARIADICS_MSVC
#		define AGPACK_PP_SEQ_BINARY_TRANSFORM_REM(data) data
#       define AGPACK_PP_SEQ_BINARY_TRANSFORM_A(...) (AGPACK_PP_SEQ_BINARY_TRANSFORM_REM, __VA_ARGS__)() AGPACK_PP_SEQ_BINARY_TRANSFORM_B
#       define AGPACK_PP_SEQ_BINARY_TRANSFORM_B(...) (AGPACK_PP_SEQ_BINARY_TRANSFORM_REM, __VA_ARGS__)() AGPACK_PP_SEQ_BINARY_TRANSFORM_A
#	 else
#       define AGPACK_PP_SEQ_BINARY_TRANSFORM_A(...) (AGPACK_PP_REM, __VA_ARGS__)() AGPACK_PP_SEQ_BINARY_TRANSFORM_B
#       define AGPACK_PP_SEQ_BINARY_TRANSFORM_B(...) (AGPACK_PP_REM, __VA_ARGS__)() AGPACK_PP_SEQ_BINARY_TRANSFORM_A
#	 endif
# else
#    define AGPACK_PP_SEQ_BINARY_TRANSFORM_A(e) (AGPACK_PP_REM, e)() AGPACK_PP_SEQ_BINARY_TRANSFORM_B
#    define AGPACK_PP_SEQ_BINARY_TRANSFORM_B(e) (AGPACK_PP_REM, e)() AGPACK_PP_SEQ_BINARY_TRANSFORM_A
# endif
# define AGPACK_PP_SEQ_BINARY_TRANSFORM_A0 (AGPACK_PP_EAT, ?)
# define AGPACK_PP_SEQ_BINARY_TRANSFORM_B0 (AGPACK_PP_EAT, ?)
#
# endif
