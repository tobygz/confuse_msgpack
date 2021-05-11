# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
# define AGPACK_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/debug/error.hpp>
# include <agpack/preprocessor/detail/auto_rec.hpp>
#
# if 0
#    define AGPACK_PP_LIST_FOLD_RIGHT(op, state, list)
# endif
#
# define AGPACK_PP_LIST_FOLD_RIGHT AGPACK_PP_CAT(AGPACK_PP_LIST_FOLD_RIGHT_, AGPACK_PP_AUTO_REC(AGPACK_PP_WHILE_P, 256))
#
# define AGPACK_PP_LIST_FOLD_RIGHT_257(o, s, l) AGPACK_PP_ERROR(0x0004)
#
# define AGPACK_PP_LIST_FOLD_RIGHT_D(d, o, s, l) AGPACK_PP_LIST_FOLD_RIGHT_ ## d(o, s, l)
# define AGPACK_PP_LIST_FOLD_RIGHT_2ND AGPACK_PP_LIST_FOLD_RIGHT
# define AGPACK_PP_LIST_FOLD_RIGHT_2ND_D AGPACK_PP_LIST_FOLD_RIGHT_D
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    include <agpack/preprocessor/list/detail/edg/fold_right.hpp>
# else
#    include <agpack/preprocessor/list/detail/fold_right.hpp>
# endif
#
# endif
