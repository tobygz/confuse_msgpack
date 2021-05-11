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
# ifndef AGPACK_PREPROCESSOR_DEBUG_ERROR_HPP
# define AGPACK_PREPROCESSOR_DEBUG_ERROR_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_ERROR */
#
# if AGPACK_PP_CONFIG_ERRORS
#    define AGPACK_PP_ERROR(code) AGPACK_PP_CAT(AGPACK_PP_ERROR_, code)
# endif
#
# define AGPACK_PP_ERROR_0x0000 AGPACK_PP_ERROR(0x0000, AGPACK_PP_INDEX_OUT_OF_BOUNDS)
# define AGPACK_PP_ERROR_0x0001 AGPACK_PP_ERROR(0x0001, AGPACK_PP_WHILE_OVERFLOW)
# define AGPACK_PP_ERROR_0x0002 AGPACK_PP_ERROR(0x0002, AGPACK_PP_FOR_OVERFLOW)
# define AGPACK_PP_ERROR_0x0003 AGPACK_PP_ERROR(0x0003, AGPACK_PP_REPEAT_OVERFLOW)
# define AGPACK_PP_ERROR_0x0004 AGPACK_PP_ERROR(0x0004, AGPACK_PP_LIST_FOLD_OVERFLOW)
# define AGPACK_PP_ERROR_0x0005 AGPACK_PP_ERROR(0x0005, AGPACK_PP_SEQ_FOLD_OVERFLOW)
# define AGPACK_PP_ERROR_0x0006 AGPACK_PP_ERROR(0x0006, AGPACK_PP_ARITHMETIC_OVERFLOW)
# define AGPACK_PP_ERROR_0x0007 AGPACK_PP_ERROR(0x0007, AGPACK_PP_DIVISION_BY_ZERO)
#
# endif
