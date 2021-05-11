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
# ifndef AGPACK_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_HPP
# define AGPACK_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_HPP
#
# include <agpack/preprocessor/arithmetic/add.hpp>
# include <agpack/preprocessor/arithmetic/sub.hpp>
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/debug/error.hpp>
# include <agpack/preprocessor/detail/auto_rec.hpp>
# include <agpack/preprocessor/repetition/repeat.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_REPEAT_FROM_TO */
#
# if 0
#    define AGPACK_PP_REPEAT_FROM_TO(first, last, macro, data)
# endif
#
# define AGPACK_PP_REPEAT_FROM_TO AGPACK_PP_CAT(AGPACK_PP_REPEAT_FROM_TO_, AGPACK_PP_AUTO_REC(AGPACK_PP_REPEAT_P, 4))
#
# define AGPACK_PP_REPEAT_FROM_TO_1(f, l, m, dt) AGPACK_PP_REPEAT_FROM_TO_D_1(AGPACK_PP_AUTO_REC(AGPACK_PP_WHILE_P, 256), f, l, m, dt)
# define AGPACK_PP_REPEAT_FROM_TO_2(f, l, m, dt) AGPACK_PP_REPEAT_FROM_TO_D_2(AGPACK_PP_AUTO_REC(AGPACK_PP_WHILE_P, 256), f, l, m, dt)
# define AGPACK_PP_REPEAT_FROM_TO_3(f, l, m, dt) AGPACK_PP_REPEAT_FROM_TO_D_3(AGPACK_PP_AUTO_REC(AGPACK_PP_WHILE_P, 256), f, l, m, dt)
# define AGPACK_PP_REPEAT_FROM_TO_4(f, l, m, dt) AGPACK_PP_ERROR(0x0003)
#
# define AGPACK_PP_REPEAT_FROM_TO_1ST AGPACK_PP_REPEAT_FROM_TO_1
# define AGPACK_PP_REPEAT_FROM_TO_2ND AGPACK_PP_REPEAT_FROM_TO_2
# define AGPACK_PP_REPEAT_FROM_TO_3RD AGPACK_PP_REPEAT_FROM_TO_3
#
# /* AGPACK_PP_REPEAT_FROM_TO_D */
#
# if 0
#    define AGPACK_PP_REPEAT_FROM_TO_D(d, first, last, macro, data)
# endif
#
# define AGPACK_PP_REPEAT_FROM_TO_D AGPACK_PP_CAT(AGPACK_PP_REPEAT_FROM_TO_D_, AGPACK_PP_AUTO_REC(AGPACK_PP_REPEAT_P, 4))
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_REPEAT_FROM_TO_D_1(d, f, l, m, dt) AGPACK_PP_REPEAT_1(AGPACK_PP_SUB_D(d, l, f), AGPACK_PP_REPEAT_FROM_TO_M_1, (d, f, m, dt))
#    define AGPACK_PP_REPEAT_FROM_TO_D_2(d, f, l, m, dt) AGPACK_PP_REPEAT_2(AGPACK_PP_SUB_D(d, l, f), AGPACK_PP_REPEAT_FROM_TO_M_2, (d, f, m, dt))
#    define AGPACK_PP_REPEAT_FROM_TO_D_3(d, f, l, m, dt) AGPACK_PP_REPEAT_3(AGPACK_PP_SUB_D(d, l, f), AGPACK_PP_REPEAT_FROM_TO_M_3, (d, f, m, dt))
# else
#    define AGPACK_PP_REPEAT_FROM_TO_D_1(d, f, l, m, dt) AGPACK_PP_REPEAT_FROM_TO_D_1_I(d, f, l, m, dt)
#    define AGPACK_PP_REPEAT_FROM_TO_D_2(d, f, l, m, dt) AGPACK_PP_REPEAT_FROM_TO_D_2_I(d, f, l, m, dt)
#    define AGPACK_PP_REPEAT_FROM_TO_D_3(d, f, l, m, dt) AGPACK_PP_REPEAT_FROM_TO_D_3_I(d, f, l, m, dt)
#    define AGPACK_PP_REPEAT_FROM_TO_D_1_I(d, f, l, m, dt) AGPACK_PP_REPEAT_1(AGPACK_PP_SUB_D(d, l, f), AGPACK_PP_REPEAT_FROM_TO_M_1, (d, f, m, dt))
#    define AGPACK_PP_REPEAT_FROM_TO_D_2_I(d, f, l, m, dt) AGPACK_PP_REPEAT_2(AGPACK_PP_SUB_D(d, l, f), AGPACK_PP_REPEAT_FROM_TO_M_2, (d, f, m, dt))
#    define AGPACK_PP_REPEAT_FROM_TO_D_3_I(d, f, l, m, dt) AGPACK_PP_REPEAT_3(AGPACK_PP_SUB_D(d, l, f), AGPACK_PP_REPEAT_FROM_TO_M_3, (d, f, m, dt))
# endif
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_REPEAT_FROM_TO_M_1(z, n, dfmd) AGPACK_PP_REPEAT_FROM_TO_M_1_IM(z, n, AGPACK_PP_TUPLE_REM_4 dfmd)
#    define AGPACK_PP_REPEAT_FROM_TO_M_2(z, n, dfmd) AGPACK_PP_REPEAT_FROM_TO_M_2_IM(z, n, AGPACK_PP_TUPLE_REM_4 dfmd)
#    define AGPACK_PP_REPEAT_FROM_TO_M_3(z, n, dfmd) AGPACK_PP_REPEAT_FROM_TO_M_3_IM(z, n, AGPACK_PP_TUPLE_REM_4 dfmd)
#    define AGPACK_PP_REPEAT_FROM_TO_M_1_IM(z, n, im) AGPACK_PP_REPEAT_FROM_TO_M_1_I(z, n, im)
#    define AGPACK_PP_REPEAT_FROM_TO_M_2_IM(z, n, im) AGPACK_PP_REPEAT_FROM_TO_M_2_I(z, n, im)
#    define AGPACK_PP_REPEAT_FROM_TO_M_3_IM(z, n, im) AGPACK_PP_REPEAT_FROM_TO_M_3_I(z, n, im)
# else
#    define AGPACK_PP_REPEAT_FROM_TO_M_1(z, n, dfmd) AGPACK_PP_REPEAT_FROM_TO_M_1_I(z, n, AGPACK_PP_TUPLE_ELEM(4, 0, dfmd), AGPACK_PP_TUPLE_ELEM(4, 1, dfmd), AGPACK_PP_TUPLE_ELEM(4, 2, dfmd), AGPACK_PP_TUPLE_ELEM(4, 3, dfmd))
#    define AGPACK_PP_REPEAT_FROM_TO_M_2(z, n, dfmd) AGPACK_PP_REPEAT_FROM_TO_M_2_I(z, n, AGPACK_PP_TUPLE_ELEM(4, 0, dfmd), AGPACK_PP_TUPLE_ELEM(4, 1, dfmd), AGPACK_PP_TUPLE_ELEM(4, 2, dfmd), AGPACK_PP_TUPLE_ELEM(4, 3, dfmd))
#    define AGPACK_PP_REPEAT_FROM_TO_M_3(z, n, dfmd) AGPACK_PP_REPEAT_FROM_TO_M_3_I(z, n, AGPACK_PP_TUPLE_ELEM(4, 0, dfmd), AGPACK_PP_TUPLE_ELEM(4, 1, dfmd), AGPACK_PP_TUPLE_ELEM(4, 2, dfmd), AGPACK_PP_TUPLE_ELEM(4, 3, dfmd))
# endif
#
# define AGPACK_PP_REPEAT_FROM_TO_M_1_I(z, n, d, f, m, dt) AGPACK_PP_REPEAT_FROM_TO_M_1_II(z, AGPACK_PP_ADD_D(d, n, f), m, dt)
# define AGPACK_PP_REPEAT_FROM_TO_M_2_I(z, n, d, f, m, dt) AGPACK_PP_REPEAT_FROM_TO_M_2_II(z, AGPACK_PP_ADD_D(d, n, f), m, dt)
# define AGPACK_PP_REPEAT_FROM_TO_M_3_I(z, n, d, f, m, dt) AGPACK_PP_REPEAT_FROM_TO_M_3_II(z, AGPACK_PP_ADD_D(d, n, f), m, dt)
#
# define AGPACK_PP_REPEAT_FROM_TO_M_1_II(z, n, m, dt) m(z, n, dt)
# define AGPACK_PP_REPEAT_FROM_TO_M_2_II(z, n, m, dt) m(z, n, dt)
# define AGPACK_PP_REPEAT_FROM_TO_M_3_II(z, n, m, dt) m(z, n, dt)
#
# endif
