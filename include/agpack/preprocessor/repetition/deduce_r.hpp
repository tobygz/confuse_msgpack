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
# ifndef AGPACK_PREPROCESSOR_REPETITION_DEDUCE_R_HPP
# define AGPACK_PREPROCESSOR_REPETITION_DEDUCE_R_HPP
#
# include <agpack/preprocessor/detail/auto_rec.hpp>
# include <agpack/preprocessor/repetition/for.hpp>
#
# /* AGPACK_PP_DEDUCE_R */
#
# define AGPACK_PP_DEDUCE_R() AGPACK_PP_AUTO_REC(AGPACK_PP_FOR_P, 256)
#
# endif
