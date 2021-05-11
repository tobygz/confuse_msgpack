# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_VARIADIC_TO_SEQ_HPP
# define AGPACK_PREPROCESSOR_VARIADIC_TO_SEQ_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/to_seq.hpp>
#
# /* AGPACK_PP_VARIADIC_TO_SEQ */
#
# if AGPACK_PP_VARIADICS
#    define AGPACK_PP_VARIADIC_TO_SEQ(...) AGPACK_PP_TUPLE_TO_SEQ((__VA_ARGS__))
# endif
#
# endif
