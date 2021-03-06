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
# ifndef AGPACK_PREPROCESSOR_SLOT_DETAIL_DEF_HPP
# define AGPACK_PREPROCESSOR_SLOT_DETAIL_DEF_HPP
#
# /* AGPACK_PP_SLOT_OFFSET_x */
#
# define AGPACK_PP_SLOT_OFFSET_10(x) (x) % 1000000000UL
# define AGPACK_PP_SLOT_OFFSET_9(x) AGPACK_PP_SLOT_OFFSET_10(x) % 100000000UL
# define AGPACK_PP_SLOT_OFFSET_8(x) AGPACK_PP_SLOT_OFFSET_9(x) % 10000000UL
# define AGPACK_PP_SLOT_OFFSET_7(x) AGPACK_PP_SLOT_OFFSET_8(x) % 1000000UL
# define AGPACK_PP_SLOT_OFFSET_6(x) AGPACK_PP_SLOT_OFFSET_7(x) % 100000UL
# define AGPACK_PP_SLOT_OFFSET_5(x) AGPACK_PP_SLOT_OFFSET_6(x) % 10000UL
# define AGPACK_PP_SLOT_OFFSET_4(x) AGPACK_PP_SLOT_OFFSET_5(x) % 1000UL
# define AGPACK_PP_SLOT_OFFSET_3(x) AGPACK_PP_SLOT_OFFSET_4(x) % 100UL
# define AGPACK_PP_SLOT_OFFSET_2(x) AGPACK_PP_SLOT_OFFSET_3(x) % 10UL
#
# /* AGPACK_PP_SLOT_CC_x */
#
# define AGPACK_PP_SLOT_CC_2(a, b) AGPACK_PP_SLOT_CC_2_D(a, b)
# define AGPACK_PP_SLOT_CC_3(a, b, c) AGPACK_PP_SLOT_CC_3_D(a, b, c)
# define AGPACK_PP_SLOT_CC_4(a, b, c, d) AGPACK_PP_SLOT_CC_4_D(a, b, c, d)
# define AGPACK_PP_SLOT_CC_5(a, b, c, d, e) AGPACK_PP_SLOT_CC_5_D(a, b, c, d, e)
# define AGPACK_PP_SLOT_CC_6(a, b, c, d, e, f) AGPACK_PP_SLOT_CC_6_D(a, b, c, d, e, f)
# define AGPACK_PP_SLOT_CC_7(a, b, c, d, e, f, g) AGPACK_PP_SLOT_CC_7_D(a, b, c, d, e, f, g)
# define AGPACK_PP_SLOT_CC_8(a, b, c, d, e, f, g, h) AGPACK_PP_SLOT_CC_8_D(a, b, c, d, e, f, g, h)
# define AGPACK_PP_SLOT_CC_9(a, b, c, d, e, f, g, h, i) AGPACK_PP_SLOT_CC_9_D(a, b, c, d, e, f, g, h, i)
# define AGPACK_PP_SLOT_CC_10(a, b, c, d, e, f, g, h, i, j) AGPACK_PP_SLOT_CC_10_D(a, b, c, d, e, f, g, h, i, j)
#
# define AGPACK_PP_SLOT_CC_2_D(a, b) a ## b
# define AGPACK_PP_SLOT_CC_3_D(a, b, c) a ## b ## c
# define AGPACK_PP_SLOT_CC_4_D(a, b, c, d) a ## b ## c ## d
# define AGPACK_PP_SLOT_CC_5_D(a, b, c, d, e) a ## b ## c ## d ## e
# define AGPACK_PP_SLOT_CC_6_D(a, b, c, d, e, f) a ## b ## c ## d ## e ## f
# define AGPACK_PP_SLOT_CC_7_D(a, b, c, d, e, f, g) a ## b ## c ## d ## e ## f ## g
# define AGPACK_PP_SLOT_CC_8_D(a, b, c, d, e, f, g, h) a ## b ## c ## d ## e ## f ## g ## h
# define AGPACK_PP_SLOT_CC_9_D(a, b, c, d, e, f, g, h, i) a ## b ## c ## d ## e ## f ## g ## h ## i
# define AGPACK_PP_SLOT_CC_10_D(a, b, c, d, e, f, g, h, i, j) a ## b ## c ## d ## e ## f ## g ## h ## i ## j
#
# endif
