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
# ifndef AGPACK_PREPROCESSOR_SLOT_SLOT_HPP
# define AGPACK_PREPROCESSOR_SLOT_SLOT_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/slot/detail/def.hpp>
#
# /* AGPACK_PP_ASSIGN_SLOT */
#
# define AGPACK_PP_ASSIGN_SLOT(i) AGPACK_PP_CAT(AGPACK_PP_ASSIGN_SLOT_, i)
#
# define AGPACK_PP_ASSIGN_SLOT_1 <agpack/preprocessor/slot/detail/slot1.hpp>
# define AGPACK_PP_ASSIGN_SLOT_2 <agpack/preprocessor/slot/detail/slot2.hpp>
# define AGPACK_PP_ASSIGN_SLOT_3 <agpack/preprocessor/slot/detail/slot3.hpp>
# define AGPACK_PP_ASSIGN_SLOT_4 <agpack/preprocessor/slot/detail/slot4.hpp>
# define AGPACK_PP_ASSIGN_SLOT_5 <agpack/preprocessor/slot/detail/slot5.hpp>
#
# /* AGPACK_PP_SLOT */
#
# define AGPACK_PP_SLOT(i) AGPACK_PP_CAT(AGPACK_PP_SLOT_, i)()
#
# endif
