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
# ifndef AGPACK_PREPROCESSOR_SEQ_POP_FRONT_HPP
# define AGPACK_PREPROCESSOR_SEQ_POP_FRONT_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/seq/seq.hpp>
#
# /* AGPACK_PP_SEQ_POP_FRONT */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_POP_FRONT(seq) AGPACK_PP_SEQ_TAIL(seq)
# else
#    define AGPACK_PP_SEQ_POP_FRONT(seq) AGPACK_PP_SEQ_POP_FRONT_I(seq)
#    define AGPACK_PP_SEQ_POP_FRONT_I(seq) AGPACK_PP_SEQ_TAIL(seq)
# endif
#
# endif
