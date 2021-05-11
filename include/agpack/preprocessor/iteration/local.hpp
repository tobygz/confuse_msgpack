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
# ifndef AGPACK_PREPROCESSOR_ITERATION_LOCAL_HPP
# define AGPACK_PREPROCESSOR_ITERATION_LOCAL_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/slot/slot.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_LOCAL_ITERATE */
#
# define AGPACK_PP_LOCAL_ITERATE() <agpack/preprocessor/iteration/detail/local.hpp>
#
# define AGPACK_PP_LOCAL_C(n) (AGPACK_PP_LOCAL_S) <= n && (AGPACK_PP_LOCAL_F) >= n
# define AGPACK_PP_LOCAL_R(n) (AGPACK_PP_LOCAL_F) <= n && (AGPACK_PP_LOCAL_S) >= n
#
# endif
