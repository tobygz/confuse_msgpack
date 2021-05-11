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
# if !defined(AGPACK_PP_LOCAL_LIMITS)
#    error AGPACK_PP_ERROR:  local iteration boundaries are not defined
# elif !defined(AGPACK_PP_LOCAL_MACRO)
#    error AGPACK_PP_ERROR:  local iteration target macro is not defined
# else
#    if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#        define AGPACK_PP_LOCAL_S AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_LOCAL_LIMITS)
#        define AGPACK_PP_LOCAL_F AGPACK_PP_TUPLE_ELEM(2, 1, AGPACK_PP_LOCAL_LIMITS)
#    else
#        define AGPACK_PP_VALUE AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_LOCAL_LIMITS)
#        include <agpack/preprocessor/iteration/detail/start.hpp>
#        define AGPACK_PP_VALUE AGPACK_PP_TUPLE_ELEM(2, 1, AGPACK_PP_LOCAL_LIMITS)
#        include <agpack/preprocessor/iteration/detail/finish.hpp>
#        define AGPACK_PP_LOCAL_S AGPACK_PP_LOCAL_SE()
#        define AGPACK_PP_LOCAL_F AGPACK_PP_LOCAL_FE()
#    endif
# endif
#
# if (AGPACK_PP_LOCAL_S) > (AGPACK_PP_LOCAL_F)
#    include <agpack/preprocessor/iteration/detail/rlocal.hpp>
# else
#    if AGPACK_PP_LOCAL_C(0)
        AGPACK_PP_LOCAL_MACRO(0)
#    endif
#    if AGPACK_PP_LOCAL_C(1)
        AGPACK_PP_LOCAL_MACRO(1)
#    endif
#    if AGPACK_PP_LOCAL_C(2)
        AGPACK_PP_LOCAL_MACRO(2)
#    endif
#    if AGPACK_PP_LOCAL_C(3)
        AGPACK_PP_LOCAL_MACRO(3)
#    endif
#    if AGPACK_PP_LOCAL_C(4)
        AGPACK_PP_LOCAL_MACRO(4)
#    endif
#    if AGPACK_PP_LOCAL_C(5)
        AGPACK_PP_LOCAL_MACRO(5)
#    endif
#    if AGPACK_PP_LOCAL_C(6)
        AGPACK_PP_LOCAL_MACRO(6)
#    endif
#    if AGPACK_PP_LOCAL_C(7)
        AGPACK_PP_LOCAL_MACRO(7)
#    endif
#    if AGPACK_PP_LOCAL_C(8)
        AGPACK_PP_LOCAL_MACRO(8)
#    endif
#    if AGPACK_PP_LOCAL_C(9)
        AGPACK_PP_LOCAL_MACRO(9)
#    endif
#    if AGPACK_PP_LOCAL_C(10)
        AGPACK_PP_LOCAL_MACRO(10)
#    endif
#    if AGPACK_PP_LOCAL_C(11)
        AGPACK_PP_LOCAL_MACRO(11)
#    endif
#    if AGPACK_PP_LOCAL_C(12)
        AGPACK_PP_LOCAL_MACRO(12)
#    endif
#    if AGPACK_PP_LOCAL_C(13)
        AGPACK_PP_LOCAL_MACRO(13)
#    endif
#    if AGPACK_PP_LOCAL_C(14)
        AGPACK_PP_LOCAL_MACRO(14)
#    endif
#    if AGPACK_PP_LOCAL_C(15)
        AGPACK_PP_LOCAL_MACRO(15)
#    endif
#    if AGPACK_PP_LOCAL_C(16)
        AGPACK_PP_LOCAL_MACRO(16)
#    endif
#    if AGPACK_PP_LOCAL_C(17)
        AGPACK_PP_LOCAL_MACRO(17)
#    endif
#    if AGPACK_PP_LOCAL_C(18)
        AGPACK_PP_LOCAL_MACRO(18)
#    endif
#    if AGPACK_PP_LOCAL_C(19)
        AGPACK_PP_LOCAL_MACRO(19)
#    endif
#    if AGPACK_PP_LOCAL_C(20)
        AGPACK_PP_LOCAL_MACRO(20)
#    endif
#    if AGPACK_PP_LOCAL_C(21)
        AGPACK_PP_LOCAL_MACRO(21)
#    endif
#    if AGPACK_PP_LOCAL_C(22)
        AGPACK_PP_LOCAL_MACRO(22)
#    endif
#    if AGPACK_PP_LOCAL_C(23)
        AGPACK_PP_LOCAL_MACRO(23)
#    endif
#    if AGPACK_PP_LOCAL_C(24)
        AGPACK_PP_LOCAL_MACRO(24)
#    endif
#    if AGPACK_PP_LOCAL_C(25)
        AGPACK_PP_LOCAL_MACRO(25)
#    endif
#    if AGPACK_PP_LOCAL_C(26)
        AGPACK_PP_LOCAL_MACRO(26)
#    endif
#    if AGPACK_PP_LOCAL_C(27)
        AGPACK_PP_LOCAL_MACRO(27)
#    endif
#    if AGPACK_PP_LOCAL_C(28)
        AGPACK_PP_LOCAL_MACRO(28)
#    endif
#    if AGPACK_PP_LOCAL_C(29)
        AGPACK_PP_LOCAL_MACRO(29)
#    endif
#    if AGPACK_PP_LOCAL_C(30)
        AGPACK_PP_LOCAL_MACRO(30)
#    endif
#    if AGPACK_PP_LOCAL_C(31)
        AGPACK_PP_LOCAL_MACRO(31)
#    endif
#    if AGPACK_PP_LOCAL_C(32)
        AGPACK_PP_LOCAL_MACRO(32)
#    endif
#    if AGPACK_PP_LOCAL_C(33)
        AGPACK_PP_LOCAL_MACRO(33)
#    endif
#    if AGPACK_PP_LOCAL_C(34)
        AGPACK_PP_LOCAL_MACRO(34)
#    endif
#    if AGPACK_PP_LOCAL_C(35)
        AGPACK_PP_LOCAL_MACRO(35)
#    endif
#    if AGPACK_PP_LOCAL_C(36)
        AGPACK_PP_LOCAL_MACRO(36)
#    endif
#    if AGPACK_PP_LOCAL_C(37)
        AGPACK_PP_LOCAL_MACRO(37)
#    endif
#    if AGPACK_PP_LOCAL_C(38)
        AGPACK_PP_LOCAL_MACRO(38)
#    endif
#    if AGPACK_PP_LOCAL_C(39)
        AGPACK_PP_LOCAL_MACRO(39)
#    endif
#    if AGPACK_PP_LOCAL_C(40)
        AGPACK_PP_LOCAL_MACRO(40)
#    endif
#    if AGPACK_PP_LOCAL_C(41)
        AGPACK_PP_LOCAL_MACRO(41)
#    endif
#    if AGPACK_PP_LOCAL_C(42)
        AGPACK_PP_LOCAL_MACRO(42)
#    endif
#    if AGPACK_PP_LOCAL_C(43)
        AGPACK_PP_LOCAL_MACRO(43)
#    endif
#    if AGPACK_PP_LOCAL_C(44)
        AGPACK_PP_LOCAL_MACRO(44)
#    endif
#    if AGPACK_PP_LOCAL_C(45)
        AGPACK_PP_LOCAL_MACRO(45)
#    endif
#    if AGPACK_PP_LOCAL_C(46)
        AGPACK_PP_LOCAL_MACRO(46)
#    endif
#    if AGPACK_PP_LOCAL_C(47)
        AGPACK_PP_LOCAL_MACRO(47)
#    endif
#    if AGPACK_PP_LOCAL_C(48)
        AGPACK_PP_LOCAL_MACRO(48)
#    endif
#    if AGPACK_PP_LOCAL_C(49)
        AGPACK_PP_LOCAL_MACRO(49)
#    endif
#    if AGPACK_PP_LOCAL_C(50)
        AGPACK_PP_LOCAL_MACRO(50)
#    endif
#    if AGPACK_PP_LOCAL_C(51)
        AGPACK_PP_LOCAL_MACRO(51)
#    endif
#    if AGPACK_PP_LOCAL_C(52)
        AGPACK_PP_LOCAL_MACRO(52)
#    endif
#    if AGPACK_PP_LOCAL_C(53)
        AGPACK_PP_LOCAL_MACRO(53)
#    endif
#    if AGPACK_PP_LOCAL_C(54)
        AGPACK_PP_LOCAL_MACRO(54)
#    endif
#    if AGPACK_PP_LOCAL_C(55)
        AGPACK_PP_LOCAL_MACRO(55)
#    endif
#    if AGPACK_PP_LOCAL_C(56)
        AGPACK_PP_LOCAL_MACRO(56)
#    endif
#    if AGPACK_PP_LOCAL_C(57)
        AGPACK_PP_LOCAL_MACRO(57)
#    endif
#    if AGPACK_PP_LOCAL_C(58)
        AGPACK_PP_LOCAL_MACRO(58)
#    endif
#    if AGPACK_PP_LOCAL_C(59)
        AGPACK_PP_LOCAL_MACRO(59)
#    endif
#    if AGPACK_PP_LOCAL_C(60)
        AGPACK_PP_LOCAL_MACRO(60)
#    endif
#    if AGPACK_PP_LOCAL_C(61)
        AGPACK_PP_LOCAL_MACRO(61)
#    endif
#    if AGPACK_PP_LOCAL_C(62)
        AGPACK_PP_LOCAL_MACRO(62)
#    endif
#    if AGPACK_PP_LOCAL_C(63)
        AGPACK_PP_LOCAL_MACRO(63)
#    endif
#    if AGPACK_PP_LOCAL_C(64)
        AGPACK_PP_LOCAL_MACRO(64)
#    endif
#    if AGPACK_PP_LOCAL_C(65)
        AGPACK_PP_LOCAL_MACRO(65)
#    endif
#    if AGPACK_PP_LOCAL_C(66)
        AGPACK_PP_LOCAL_MACRO(66)
#    endif
#    if AGPACK_PP_LOCAL_C(67)
        AGPACK_PP_LOCAL_MACRO(67)
#    endif
#    if AGPACK_PP_LOCAL_C(68)
        AGPACK_PP_LOCAL_MACRO(68)
#    endif
#    if AGPACK_PP_LOCAL_C(69)
        AGPACK_PP_LOCAL_MACRO(69)
#    endif
#    if AGPACK_PP_LOCAL_C(70)
        AGPACK_PP_LOCAL_MACRO(70)
#    endif
#    if AGPACK_PP_LOCAL_C(71)
        AGPACK_PP_LOCAL_MACRO(71)
#    endif
#    if AGPACK_PP_LOCAL_C(72)
        AGPACK_PP_LOCAL_MACRO(72)
#    endif
#    if AGPACK_PP_LOCAL_C(73)
        AGPACK_PP_LOCAL_MACRO(73)
#    endif
#    if AGPACK_PP_LOCAL_C(74)
        AGPACK_PP_LOCAL_MACRO(74)
#    endif
#    if AGPACK_PP_LOCAL_C(75)
        AGPACK_PP_LOCAL_MACRO(75)
#    endif
#    if AGPACK_PP_LOCAL_C(76)
        AGPACK_PP_LOCAL_MACRO(76)
#    endif
#    if AGPACK_PP_LOCAL_C(77)
        AGPACK_PP_LOCAL_MACRO(77)
#    endif
#    if AGPACK_PP_LOCAL_C(78)
        AGPACK_PP_LOCAL_MACRO(78)
#    endif
#    if AGPACK_PP_LOCAL_C(79)
        AGPACK_PP_LOCAL_MACRO(79)
#    endif
#    if AGPACK_PP_LOCAL_C(80)
        AGPACK_PP_LOCAL_MACRO(80)
#    endif
#    if AGPACK_PP_LOCAL_C(81)
        AGPACK_PP_LOCAL_MACRO(81)
#    endif
#    if AGPACK_PP_LOCAL_C(82)
        AGPACK_PP_LOCAL_MACRO(82)
#    endif
#    if AGPACK_PP_LOCAL_C(83)
        AGPACK_PP_LOCAL_MACRO(83)
#    endif
#    if AGPACK_PP_LOCAL_C(84)
        AGPACK_PP_LOCAL_MACRO(84)
#    endif
#    if AGPACK_PP_LOCAL_C(85)
        AGPACK_PP_LOCAL_MACRO(85)
#    endif
#    if AGPACK_PP_LOCAL_C(86)
        AGPACK_PP_LOCAL_MACRO(86)
#    endif
#    if AGPACK_PP_LOCAL_C(87)
        AGPACK_PP_LOCAL_MACRO(87)
#    endif
#    if AGPACK_PP_LOCAL_C(88)
        AGPACK_PP_LOCAL_MACRO(88)
#    endif
#    if AGPACK_PP_LOCAL_C(89)
        AGPACK_PP_LOCAL_MACRO(89)
#    endif
#    if AGPACK_PP_LOCAL_C(90)
        AGPACK_PP_LOCAL_MACRO(90)
#    endif
#    if AGPACK_PP_LOCAL_C(91)
        AGPACK_PP_LOCAL_MACRO(91)
#    endif
#    if AGPACK_PP_LOCAL_C(92)
        AGPACK_PP_LOCAL_MACRO(92)
#    endif
#    if AGPACK_PP_LOCAL_C(93)
        AGPACK_PP_LOCAL_MACRO(93)
#    endif
#    if AGPACK_PP_LOCAL_C(94)
        AGPACK_PP_LOCAL_MACRO(94)
#    endif
#    if AGPACK_PP_LOCAL_C(95)
        AGPACK_PP_LOCAL_MACRO(95)
#    endif
#    if AGPACK_PP_LOCAL_C(96)
        AGPACK_PP_LOCAL_MACRO(96)
#    endif
#    if AGPACK_PP_LOCAL_C(97)
        AGPACK_PP_LOCAL_MACRO(97)
#    endif
#    if AGPACK_PP_LOCAL_C(98)
        AGPACK_PP_LOCAL_MACRO(98)
#    endif
#    if AGPACK_PP_LOCAL_C(99)
        AGPACK_PP_LOCAL_MACRO(99)
#    endif
#    if AGPACK_PP_LOCAL_C(100)
        AGPACK_PP_LOCAL_MACRO(100)
#    endif
#    if AGPACK_PP_LOCAL_C(101)
        AGPACK_PP_LOCAL_MACRO(101)
#    endif
#    if AGPACK_PP_LOCAL_C(102)
        AGPACK_PP_LOCAL_MACRO(102)
#    endif
#    if AGPACK_PP_LOCAL_C(103)
        AGPACK_PP_LOCAL_MACRO(103)
#    endif
#    if AGPACK_PP_LOCAL_C(104)
        AGPACK_PP_LOCAL_MACRO(104)
#    endif
#    if AGPACK_PP_LOCAL_C(105)
        AGPACK_PP_LOCAL_MACRO(105)
#    endif
#    if AGPACK_PP_LOCAL_C(106)
        AGPACK_PP_LOCAL_MACRO(106)
#    endif
#    if AGPACK_PP_LOCAL_C(107)
        AGPACK_PP_LOCAL_MACRO(107)
#    endif
#    if AGPACK_PP_LOCAL_C(108)
        AGPACK_PP_LOCAL_MACRO(108)
#    endif
#    if AGPACK_PP_LOCAL_C(109)
        AGPACK_PP_LOCAL_MACRO(109)
#    endif
#    if AGPACK_PP_LOCAL_C(110)
        AGPACK_PP_LOCAL_MACRO(110)
#    endif
#    if AGPACK_PP_LOCAL_C(111)
        AGPACK_PP_LOCAL_MACRO(111)
#    endif
#    if AGPACK_PP_LOCAL_C(112)
        AGPACK_PP_LOCAL_MACRO(112)
#    endif
#    if AGPACK_PP_LOCAL_C(113)
        AGPACK_PP_LOCAL_MACRO(113)
#    endif
#    if AGPACK_PP_LOCAL_C(114)
        AGPACK_PP_LOCAL_MACRO(114)
#    endif
#    if AGPACK_PP_LOCAL_C(115)
        AGPACK_PP_LOCAL_MACRO(115)
#    endif
#    if AGPACK_PP_LOCAL_C(116)
        AGPACK_PP_LOCAL_MACRO(116)
#    endif
#    if AGPACK_PP_LOCAL_C(117)
        AGPACK_PP_LOCAL_MACRO(117)
#    endif
#    if AGPACK_PP_LOCAL_C(118)
        AGPACK_PP_LOCAL_MACRO(118)
#    endif
#    if AGPACK_PP_LOCAL_C(119)
        AGPACK_PP_LOCAL_MACRO(119)
#    endif
#    if AGPACK_PP_LOCAL_C(120)
        AGPACK_PP_LOCAL_MACRO(120)
#    endif
#    if AGPACK_PP_LOCAL_C(121)
        AGPACK_PP_LOCAL_MACRO(121)
#    endif
#    if AGPACK_PP_LOCAL_C(122)
        AGPACK_PP_LOCAL_MACRO(122)
#    endif
#    if AGPACK_PP_LOCAL_C(123)
        AGPACK_PP_LOCAL_MACRO(123)
#    endif
#    if AGPACK_PP_LOCAL_C(124)
        AGPACK_PP_LOCAL_MACRO(124)
#    endif
#    if AGPACK_PP_LOCAL_C(125)
        AGPACK_PP_LOCAL_MACRO(125)
#    endif
#    if AGPACK_PP_LOCAL_C(126)
        AGPACK_PP_LOCAL_MACRO(126)
#    endif
#    if AGPACK_PP_LOCAL_C(127)
        AGPACK_PP_LOCAL_MACRO(127)
#    endif
#    if AGPACK_PP_LOCAL_C(128)
        AGPACK_PP_LOCAL_MACRO(128)
#    endif
#    if AGPACK_PP_LOCAL_C(129)
        AGPACK_PP_LOCAL_MACRO(129)
#    endif
#    if AGPACK_PP_LOCAL_C(130)
        AGPACK_PP_LOCAL_MACRO(130)
#    endif
#    if AGPACK_PP_LOCAL_C(131)
        AGPACK_PP_LOCAL_MACRO(131)
#    endif
#    if AGPACK_PP_LOCAL_C(132)
        AGPACK_PP_LOCAL_MACRO(132)
#    endif
#    if AGPACK_PP_LOCAL_C(133)
        AGPACK_PP_LOCAL_MACRO(133)
#    endif
#    if AGPACK_PP_LOCAL_C(134)
        AGPACK_PP_LOCAL_MACRO(134)
#    endif
#    if AGPACK_PP_LOCAL_C(135)
        AGPACK_PP_LOCAL_MACRO(135)
#    endif
#    if AGPACK_PP_LOCAL_C(136)
        AGPACK_PP_LOCAL_MACRO(136)
#    endif
#    if AGPACK_PP_LOCAL_C(137)
        AGPACK_PP_LOCAL_MACRO(137)
#    endif
#    if AGPACK_PP_LOCAL_C(138)
        AGPACK_PP_LOCAL_MACRO(138)
#    endif
#    if AGPACK_PP_LOCAL_C(139)
        AGPACK_PP_LOCAL_MACRO(139)
#    endif
#    if AGPACK_PP_LOCAL_C(140)
        AGPACK_PP_LOCAL_MACRO(140)
#    endif
#    if AGPACK_PP_LOCAL_C(141)
        AGPACK_PP_LOCAL_MACRO(141)
#    endif
#    if AGPACK_PP_LOCAL_C(142)
        AGPACK_PP_LOCAL_MACRO(142)
#    endif
#    if AGPACK_PP_LOCAL_C(143)
        AGPACK_PP_LOCAL_MACRO(143)
#    endif
#    if AGPACK_PP_LOCAL_C(144)
        AGPACK_PP_LOCAL_MACRO(144)
#    endif
#    if AGPACK_PP_LOCAL_C(145)
        AGPACK_PP_LOCAL_MACRO(145)
#    endif
#    if AGPACK_PP_LOCAL_C(146)
        AGPACK_PP_LOCAL_MACRO(146)
#    endif
#    if AGPACK_PP_LOCAL_C(147)
        AGPACK_PP_LOCAL_MACRO(147)
#    endif
#    if AGPACK_PP_LOCAL_C(148)
        AGPACK_PP_LOCAL_MACRO(148)
#    endif
#    if AGPACK_PP_LOCAL_C(149)
        AGPACK_PP_LOCAL_MACRO(149)
#    endif
#    if AGPACK_PP_LOCAL_C(150)
        AGPACK_PP_LOCAL_MACRO(150)
#    endif
#    if AGPACK_PP_LOCAL_C(151)
        AGPACK_PP_LOCAL_MACRO(151)
#    endif
#    if AGPACK_PP_LOCAL_C(152)
        AGPACK_PP_LOCAL_MACRO(152)
#    endif
#    if AGPACK_PP_LOCAL_C(153)
        AGPACK_PP_LOCAL_MACRO(153)
#    endif
#    if AGPACK_PP_LOCAL_C(154)
        AGPACK_PP_LOCAL_MACRO(154)
#    endif
#    if AGPACK_PP_LOCAL_C(155)
        AGPACK_PP_LOCAL_MACRO(155)
#    endif
#    if AGPACK_PP_LOCAL_C(156)
        AGPACK_PP_LOCAL_MACRO(156)
#    endif
#    if AGPACK_PP_LOCAL_C(157)
        AGPACK_PP_LOCAL_MACRO(157)
#    endif
#    if AGPACK_PP_LOCAL_C(158)
        AGPACK_PP_LOCAL_MACRO(158)
#    endif
#    if AGPACK_PP_LOCAL_C(159)
        AGPACK_PP_LOCAL_MACRO(159)
#    endif
#    if AGPACK_PP_LOCAL_C(160)
        AGPACK_PP_LOCAL_MACRO(160)
#    endif
#    if AGPACK_PP_LOCAL_C(161)
        AGPACK_PP_LOCAL_MACRO(161)
#    endif
#    if AGPACK_PP_LOCAL_C(162)
        AGPACK_PP_LOCAL_MACRO(162)
#    endif
#    if AGPACK_PP_LOCAL_C(163)
        AGPACK_PP_LOCAL_MACRO(163)
#    endif
#    if AGPACK_PP_LOCAL_C(164)
        AGPACK_PP_LOCAL_MACRO(164)
#    endif
#    if AGPACK_PP_LOCAL_C(165)
        AGPACK_PP_LOCAL_MACRO(165)
#    endif
#    if AGPACK_PP_LOCAL_C(166)
        AGPACK_PP_LOCAL_MACRO(166)
#    endif
#    if AGPACK_PP_LOCAL_C(167)
        AGPACK_PP_LOCAL_MACRO(167)
#    endif
#    if AGPACK_PP_LOCAL_C(168)
        AGPACK_PP_LOCAL_MACRO(168)
#    endif
#    if AGPACK_PP_LOCAL_C(169)
        AGPACK_PP_LOCAL_MACRO(169)
#    endif
#    if AGPACK_PP_LOCAL_C(170)
        AGPACK_PP_LOCAL_MACRO(170)
#    endif
#    if AGPACK_PP_LOCAL_C(171)
        AGPACK_PP_LOCAL_MACRO(171)
#    endif
#    if AGPACK_PP_LOCAL_C(172)
        AGPACK_PP_LOCAL_MACRO(172)
#    endif
#    if AGPACK_PP_LOCAL_C(173)
        AGPACK_PP_LOCAL_MACRO(173)
#    endif
#    if AGPACK_PP_LOCAL_C(174)
        AGPACK_PP_LOCAL_MACRO(174)
#    endif
#    if AGPACK_PP_LOCAL_C(175)
        AGPACK_PP_LOCAL_MACRO(175)
#    endif
#    if AGPACK_PP_LOCAL_C(176)
        AGPACK_PP_LOCAL_MACRO(176)
#    endif
#    if AGPACK_PP_LOCAL_C(177)
        AGPACK_PP_LOCAL_MACRO(177)
#    endif
#    if AGPACK_PP_LOCAL_C(178)
        AGPACK_PP_LOCAL_MACRO(178)
#    endif
#    if AGPACK_PP_LOCAL_C(179)
        AGPACK_PP_LOCAL_MACRO(179)
#    endif
#    if AGPACK_PP_LOCAL_C(180)
        AGPACK_PP_LOCAL_MACRO(180)
#    endif
#    if AGPACK_PP_LOCAL_C(181)
        AGPACK_PP_LOCAL_MACRO(181)
#    endif
#    if AGPACK_PP_LOCAL_C(182)
        AGPACK_PP_LOCAL_MACRO(182)
#    endif
#    if AGPACK_PP_LOCAL_C(183)
        AGPACK_PP_LOCAL_MACRO(183)
#    endif
#    if AGPACK_PP_LOCAL_C(184)
        AGPACK_PP_LOCAL_MACRO(184)
#    endif
#    if AGPACK_PP_LOCAL_C(185)
        AGPACK_PP_LOCAL_MACRO(185)
#    endif
#    if AGPACK_PP_LOCAL_C(186)
        AGPACK_PP_LOCAL_MACRO(186)
#    endif
#    if AGPACK_PP_LOCAL_C(187)
        AGPACK_PP_LOCAL_MACRO(187)
#    endif
#    if AGPACK_PP_LOCAL_C(188)
        AGPACK_PP_LOCAL_MACRO(188)
#    endif
#    if AGPACK_PP_LOCAL_C(189)
        AGPACK_PP_LOCAL_MACRO(189)
#    endif
#    if AGPACK_PP_LOCAL_C(190)
        AGPACK_PP_LOCAL_MACRO(190)
#    endif
#    if AGPACK_PP_LOCAL_C(191)
        AGPACK_PP_LOCAL_MACRO(191)
#    endif
#    if AGPACK_PP_LOCAL_C(192)
        AGPACK_PP_LOCAL_MACRO(192)
#    endif
#    if AGPACK_PP_LOCAL_C(193)
        AGPACK_PP_LOCAL_MACRO(193)
#    endif
#    if AGPACK_PP_LOCAL_C(194)
        AGPACK_PP_LOCAL_MACRO(194)
#    endif
#    if AGPACK_PP_LOCAL_C(195)
        AGPACK_PP_LOCAL_MACRO(195)
#    endif
#    if AGPACK_PP_LOCAL_C(196)
        AGPACK_PP_LOCAL_MACRO(196)
#    endif
#    if AGPACK_PP_LOCAL_C(197)
        AGPACK_PP_LOCAL_MACRO(197)
#    endif
#    if AGPACK_PP_LOCAL_C(198)
        AGPACK_PP_LOCAL_MACRO(198)
#    endif
#    if AGPACK_PP_LOCAL_C(199)
        AGPACK_PP_LOCAL_MACRO(199)
#    endif
#    if AGPACK_PP_LOCAL_C(200)
        AGPACK_PP_LOCAL_MACRO(200)
#    endif
#    if AGPACK_PP_LOCAL_C(201)
        AGPACK_PP_LOCAL_MACRO(201)
#    endif
#    if AGPACK_PP_LOCAL_C(202)
        AGPACK_PP_LOCAL_MACRO(202)
#    endif
#    if AGPACK_PP_LOCAL_C(203)
        AGPACK_PP_LOCAL_MACRO(203)
#    endif
#    if AGPACK_PP_LOCAL_C(204)
        AGPACK_PP_LOCAL_MACRO(204)
#    endif
#    if AGPACK_PP_LOCAL_C(205)
        AGPACK_PP_LOCAL_MACRO(205)
#    endif
#    if AGPACK_PP_LOCAL_C(206)
        AGPACK_PP_LOCAL_MACRO(206)
#    endif
#    if AGPACK_PP_LOCAL_C(207)
        AGPACK_PP_LOCAL_MACRO(207)
#    endif
#    if AGPACK_PP_LOCAL_C(208)
        AGPACK_PP_LOCAL_MACRO(208)
#    endif
#    if AGPACK_PP_LOCAL_C(209)
        AGPACK_PP_LOCAL_MACRO(209)
#    endif
#    if AGPACK_PP_LOCAL_C(210)
        AGPACK_PP_LOCAL_MACRO(210)
#    endif
#    if AGPACK_PP_LOCAL_C(211)
        AGPACK_PP_LOCAL_MACRO(211)
#    endif
#    if AGPACK_PP_LOCAL_C(212)
        AGPACK_PP_LOCAL_MACRO(212)
#    endif
#    if AGPACK_PP_LOCAL_C(213)
        AGPACK_PP_LOCAL_MACRO(213)
#    endif
#    if AGPACK_PP_LOCAL_C(214)
        AGPACK_PP_LOCAL_MACRO(214)
#    endif
#    if AGPACK_PP_LOCAL_C(215)
        AGPACK_PP_LOCAL_MACRO(215)
#    endif
#    if AGPACK_PP_LOCAL_C(216)
        AGPACK_PP_LOCAL_MACRO(216)
#    endif
#    if AGPACK_PP_LOCAL_C(217)
        AGPACK_PP_LOCAL_MACRO(217)
#    endif
#    if AGPACK_PP_LOCAL_C(218)
        AGPACK_PP_LOCAL_MACRO(218)
#    endif
#    if AGPACK_PP_LOCAL_C(219)
        AGPACK_PP_LOCAL_MACRO(219)
#    endif
#    if AGPACK_PP_LOCAL_C(220)
        AGPACK_PP_LOCAL_MACRO(220)
#    endif
#    if AGPACK_PP_LOCAL_C(221)
        AGPACK_PP_LOCAL_MACRO(221)
#    endif
#    if AGPACK_PP_LOCAL_C(222)
        AGPACK_PP_LOCAL_MACRO(222)
#    endif
#    if AGPACK_PP_LOCAL_C(223)
        AGPACK_PP_LOCAL_MACRO(223)
#    endif
#    if AGPACK_PP_LOCAL_C(224)
        AGPACK_PP_LOCAL_MACRO(224)
#    endif
#    if AGPACK_PP_LOCAL_C(225)
        AGPACK_PP_LOCAL_MACRO(225)
#    endif
#    if AGPACK_PP_LOCAL_C(226)
        AGPACK_PP_LOCAL_MACRO(226)
#    endif
#    if AGPACK_PP_LOCAL_C(227)
        AGPACK_PP_LOCAL_MACRO(227)
#    endif
#    if AGPACK_PP_LOCAL_C(228)
        AGPACK_PP_LOCAL_MACRO(228)
#    endif
#    if AGPACK_PP_LOCAL_C(229)
        AGPACK_PP_LOCAL_MACRO(229)
#    endif
#    if AGPACK_PP_LOCAL_C(230)
        AGPACK_PP_LOCAL_MACRO(230)
#    endif
#    if AGPACK_PP_LOCAL_C(231)
        AGPACK_PP_LOCAL_MACRO(231)
#    endif
#    if AGPACK_PP_LOCAL_C(232)
        AGPACK_PP_LOCAL_MACRO(232)
#    endif
#    if AGPACK_PP_LOCAL_C(233)
        AGPACK_PP_LOCAL_MACRO(233)
#    endif
#    if AGPACK_PP_LOCAL_C(234)
        AGPACK_PP_LOCAL_MACRO(234)
#    endif
#    if AGPACK_PP_LOCAL_C(235)
        AGPACK_PP_LOCAL_MACRO(235)
#    endif
#    if AGPACK_PP_LOCAL_C(236)
        AGPACK_PP_LOCAL_MACRO(236)
#    endif

#    if AGPACK_PP_LOCAL_C(237)
        AGPACK_PP_LOCAL_MACRO(237)
#    endif
#    if AGPACK_PP_LOCAL_C(238)
        AGPACK_PP_LOCAL_MACRO(238)
#    endif
#    if AGPACK_PP_LOCAL_C(239)
        AGPACK_PP_LOCAL_MACRO(239)
#    endif
#    if AGPACK_PP_LOCAL_C(240)
        AGPACK_PP_LOCAL_MACRO(240)
#    endif
#    if AGPACK_PP_LOCAL_C(241)
        AGPACK_PP_LOCAL_MACRO(241)
#    endif
#    if AGPACK_PP_LOCAL_C(242)
        AGPACK_PP_LOCAL_MACRO(242)
#    endif
#    if AGPACK_PP_LOCAL_C(243)
        AGPACK_PP_LOCAL_MACRO(243)
#    endif
#    if AGPACK_PP_LOCAL_C(244)
        AGPACK_PP_LOCAL_MACRO(244)
#    endif
#    if AGPACK_PP_LOCAL_C(245)
        AGPACK_PP_LOCAL_MACRO(245)
#    endif
#    if AGPACK_PP_LOCAL_C(246)
        AGPACK_PP_LOCAL_MACRO(246)
#    endif
#    if AGPACK_PP_LOCAL_C(247)
        AGPACK_PP_LOCAL_MACRO(247)
#    endif
#    if AGPACK_PP_LOCAL_C(248)
        AGPACK_PP_LOCAL_MACRO(248)
#    endif
#    if AGPACK_PP_LOCAL_C(249)
        AGPACK_PP_LOCAL_MACRO(249)
#    endif
#    if AGPACK_PP_LOCAL_C(250)
        AGPACK_PP_LOCAL_MACRO(250)
#    endif
#    if AGPACK_PP_LOCAL_C(251)
        AGPACK_PP_LOCAL_MACRO(251)
#    endif
#    if AGPACK_PP_LOCAL_C(252)
        AGPACK_PP_LOCAL_MACRO(252)
#    endif
#    if AGPACK_PP_LOCAL_C(253)
        AGPACK_PP_LOCAL_MACRO(253)
#    endif
#    if AGPACK_PP_LOCAL_C(254)
        AGPACK_PP_LOCAL_MACRO(254)
#    endif
#    if AGPACK_PP_LOCAL_C(255)
        AGPACK_PP_LOCAL_MACRO(255)
#    endif
#    if AGPACK_PP_LOCAL_C(256)
        AGPACK_PP_LOCAL_MACRO(256)
#    endif
# endif
#
# undef AGPACK_PP_LOCAL_LIMITS
#
# undef AGPACK_PP_LOCAL_S
# undef AGPACK_PP_LOCAL_F
#
# undef AGPACK_PP_LOCAL_MACRO
