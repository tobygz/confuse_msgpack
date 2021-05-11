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
# ifndef AGPACK_PREPROCESSOR_SEQ_REMOVE_HPP
# define AGPACK_PREPROCESSOR_SEQ_REMOVE_HPP
#
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/seq/first_n.hpp>
# include <agpack/preprocessor/seq/rest_n.hpp>
#
# /* AGPACK_PP_SEQ_REMOVE */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_REMOVE(seq, i) AGPACK_PP_SEQ_FIRST_N(i, seq) AGPACK_PP_SEQ_REST_N(AGPACK_PP_INC(i), seq)
# else
#    define AGPACK_PP_SEQ_REMOVE(seq, i) AGPACK_PP_SEQ_REMOVE_I(seq, i)
#    define AGPACK_PP_SEQ_REMOVE_I(seq, i) AGPACK_PP_SEQ_FIRST_N(i, seq) AGPACK_PP_SEQ_REST_N(AGPACK_PP_INC(i), seq)
# endif
#
# endif
