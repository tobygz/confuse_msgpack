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
# ifndef AGPACK_PREPROCESSOR_SEQ_POP_BACK_HPP
# define AGPACK_PREPROCESSOR_SEQ_POP_BACK_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/seq/first_n.hpp>
# include <agpack/preprocessor/seq/size.hpp>
#
# /* AGPACK_PP_SEQ_POP_BACK */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_POP_BACK(seq) AGPACK_PP_SEQ_FIRST_N(AGPACK_PP_DEC(AGPACK_PP_SEQ_SIZE(seq)), seq)
# else
#    define AGPACK_PP_SEQ_POP_BACK(seq) AGPACK_PP_SEQ_POP_BACK_I(seq)
#    define AGPACK_PP_SEQ_POP_BACK_I(seq) AGPACK_PP_SEQ_FIRST_N(AGPACK_PP_DEC(AGPACK_PP_SEQ_SIZE(seq)), seq)
# endif
#
# endif
