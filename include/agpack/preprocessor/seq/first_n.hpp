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
# ifndef AGPACK_PREPROCESSOR_SEQ_FIRST_N_HPP
# define AGPACK_PREPROCESSOR_SEQ_FIRST_N_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/seq/detail/split.hpp>
# include <agpack/preprocessor/tuple/eat.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_SEQ_FIRST_N */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_FIRST_N(n, seq) AGPACK_PP_IF(n, AGPACK_PP_TUPLE_ELEM, AGPACK_PP_TUPLE_EAT_3)(2, 0, AGPACK_PP_SEQ_SPLIT(n, seq (nil)))
# else
#    define AGPACK_PP_SEQ_FIRST_N(n, seq) AGPACK_PP_SEQ_FIRST_N_I(n, seq)
#    define AGPACK_PP_SEQ_FIRST_N_I(n, seq) AGPACK_PP_IF(n, AGPACK_PP_TUPLE_ELEM, AGPACK_PP_TUPLE_EAT_3)(2, 0, AGPACK_PP_SEQ_SPLIT(n, seq (nil)))
# endif
#
# endif
