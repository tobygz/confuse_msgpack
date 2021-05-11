# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2012.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_SEQ_VARIADIC_SEQ_TO_SEQ_HPP
# define AGPACK_PREPROCESSOR_SEQ_VARIADIC_SEQ_TO_SEQ_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_VARIADIC_SEQ_TO_SEQ */
#
# if AGPACK_PP_VARIADICS
#    define AGPACK_PP_VARIADIC_SEQ_TO_SEQ(vseq) AGPACK_PP_CAT(AGPACK_PP_VARIADIC_SEQ_TO_SEQ_A vseq, 0)
#    define AGPACK_PP_VARIADIC_SEQ_TO_SEQ_A(...) ((__VA_ARGS__)) AGPACK_PP_VARIADIC_SEQ_TO_SEQ_B
#    define AGPACK_PP_VARIADIC_SEQ_TO_SEQ_B(...) ((__VA_ARGS__)) AGPACK_PP_VARIADIC_SEQ_TO_SEQ_A
#    define AGPACK_PP_VARIADIC_SEQ_TO_SEQ_A0
#    define AGPACK_PP_VARIADIC_SEQ_TO_SEQ_B0
# endif
#
# endif
