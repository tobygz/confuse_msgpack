# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_FACILITIES_IS_1_HPP
# define AGPACK_PREPROCESSOR_FACILITIES_IS_1_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/facilities/is_empty.hpp>
#
# /* AGPACK_PP_IS_1 */
#
# define AGPACK_PP_IS_1(x) AGPACK_PP_IS_EMPTY(AGPACK_PP_CAT(AGPACK_PP_IS_1_HELPER_, x))
# define AGPACK_PP_IS_1_HELPER_1
#
# endif
