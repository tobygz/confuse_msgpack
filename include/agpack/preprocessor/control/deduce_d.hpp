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
# ifndef AGPACK_PREPROCESSOR_CONTROL_DEDUCE_D_HPP
# define AGPACK_PREPROCESSOR_CONTROL_DEDUCE_D_HPP
#
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/detail/auto_rec.hpp>
#
# /* AGPACK_PP_DEDUCE_D */
#
# define AGPACK_PP_DEDUCE_D() AGPACK_PP_AUTO_REC(AGPACK_PP_WHILE_P, 256)
#
# endif
