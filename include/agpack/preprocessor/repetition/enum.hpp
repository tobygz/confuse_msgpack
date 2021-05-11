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
# ifndef AGPACK_PREPROCESSOR_REPETITION_ENUM_HPP
# define AGPACK_PREPROCESSOR_REPETITION_ENUM_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/debug/error.hpp>
# include <agpack/preprocessor/detail/auto_rec.hpp>
# include <agpack/preprocessor/punctuation/comma_if.hpp>
# include <agpack/preprocessor/repetition/repeat.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_ENUM */
#
# if 0
#    define AGPACK_PP_ENUM(count, macro, data)
# endif
#
# define AGPACK_PP_ENUM AGPACK_PP_CAT(AGPACK_PP_ENUM_, AGPACK_PP_AUTO_REC(AGPACK_PP_REPEAT_P, 4))
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ENUM_1(c, m, d) AGPACK_PP_REPEAT_1(c, AGPACK_PP_ENUM_M_1, (m, d))
#    define AGPACK_PP_ENUM_2(c, m, d) AGPACK_PP_REPEAT_2(c, AGPACK_PP_ENUM_M_2, (m, d))
#    define AGPACK_PP_ENUM_3(c, m, d) AGPACK_PP_REPEAT_3(c, AGPACK_PP_ENUM_M_3, (m, d))
# else
#    define AGPACK_PP_ENUM_1(c, m, d) AGPACK_PP_ENUM_1_I(c, m, d)
#    define AGPACK_PP_ENUM_2(c, m, d) AGPACK_PP_ENUM_2_I(c, m, d)
#    define AGPACK_PP_ENUM_3(c, m, d) AGPACK_PP_ENUM_3_I(c, m, d)
#    define AGPACK_PP_ENUM_1_I(c, m, d) AGPACK_PP_REPEAT_1(c, AGPACK_PP_ENUM_M_1, (m, d))
#    define AGPACK_PP_ENUM_2_I(c, m, d) AGPACK_PP_REPEAT_2(c, AGPACK_PP_ENUM_M_2, (m, d))
#    define AGPACK_PP_ENUM_3_I(c, m, d) AGPACK_PP_REPEAT_3(c, AGPACK_PP_ENUM_M_3, (m, d))
# endif
#
# define AGPACK_PP_ENUM_4(c, m, d) AGPACK_PP_ERROR(0x0003)
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_ENUM_M_1(z, n, md) AGPACK_PP_ENUM_M_1_IM(z, n, AGPACK_PP_TUPLE_REM_2 md)
#    define AGPACK_PP_ENUM_M_2(z, n, md) AGPACK_PP_ENUM_M_2_IM(z, n, AGPACK_PP_TUPLE_REM_2 md)
#    define AGPACK_PP_ENUM_M_3(z, n, md) AGPACK_PP_ENUM_M_3_IM(z, n, AGPACK_PP_TUPLE_REM_2 md)
#    define AGPACK_PP_ENUM_M_1_IM(z, n, im) AGPACK_PP_ENUM_M_1_I(z, n, im)
#    define AGPACK_PP_ENUM_M_2_IM(z, n, im) AGPACK_PP_ENUM_M_2_I(z, n, im)
#    define AGPACK_PP_ENUM_M_3_IM(z, n, im) AGPACK_PP_ENUM_M_3_I(z, n, im)
# else
#    define AGPACK_PP_ENUM_M_1(z, n, md) AGPACK_PP_ENUM_M_1_I(z, n, AGPACK_PP_TUPLE_ELEM(2, 0, md), AGPACK_PP_TUPLE_ELEM(2, 1, md))
#    define AGPACK_PP_ENUM_M_2(z, n, md) AGPACK_PP_ENUM_M_2_I(z, n, AGPACK_PP_TUPLE_ELEM(2, 0, md), AGPACK_PP_TUPLE_ELEM(2, 1, md))
#    define AGPACK_PP_ENUM_M_3(z, n, md) AGPACK_PP_ENUM_M_3_I(z, n, AGPACK_PP_TUPLE_ELEM(2, 0, md), AGPACK_PP_TUPLE_ELEM(2, 1, md))
# endif
#
# define AGPACK_PP_ENUM_M_1_I(z, n, m, d) AGPACK_PP_COMMA_IF(n) m(z, n, d)
# define AGPACK_PP_ENUM_M_2_I(z, n, m, d) AGPACK_PP_COMMA_IF(n) m(z, n, d)
# define AGPACK_PP_ENUM_M_3_I(z, n, m, d) AGPACK_PP_COMMA_IF(n) m(z, n, d)
#
# endif
