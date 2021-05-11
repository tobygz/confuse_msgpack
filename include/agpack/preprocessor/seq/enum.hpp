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
# ifndef AGPACK_PREPROCESSOR_SEQ_ENUM_HPP
# define AGPACK_PREPROCESSOR_SEQ_ENUM_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/seq/size.hpp>
#
# /* AGPACK_PP_SEQ_ENUM */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SEQ_ENUM(seq) AGPACK_PP_SEQ_ENUM_I(seq)
#    define AGPACK_PP_SEQ_ENUM_I(seq) AGPACK_PP_CAT(AGPACK_PP_SEQ_ENUM_, AGPACK_PP_SEQ_SIZE(seq)) seq
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_SEQ_ENUM(seq) AGPACK_PP_SEQ_ENUM_I(AGPACK_PP_SEQ_SIZE(seq), seq)
#    define AGPACK_PP_SEQ_ENUM_I(size, seq) AGPACK_PP_CAT(AGPACK_PP_SEQ_ENUM_, size) seq
# else
#    define AGPACK_PP_SEQ_ENUM(seq) AGPACK_PP_CAT(AGPACK_PP_SEQ_ENUM_, AGPACK_PP_SEQ_SIZE(seq)) seq
# endif
#
# define AGPACK_PP_SEQ_ENUM_1(x) x
# define AGPACK_PP_SEQ_ENUM_2(x) x, AGPACK_PP_SEQ_ENUM_1
# define AGPACK_PP_SEQ_ENUM_3(x) x, AGPACK_PP_SEQ_ENUM_2
# define AGPACK_PP_SEQ_ENUM_4(x) x, AGPACK_PP_SEQ_ENUM_3
# define AGPACK_PP_SEQ_ENUM_5(x) x, AGPACK_PP_SEQ_ENUM_4
# define AGPACK_PP_SEQ_ENUM_6(x) x, AGPACK_PP_SEQ_ENUM_5
# define AGPACK_PP_SEQ_ENUM_7(x) x, AGPACK_PP_SEQ_ENUM_6
# define AGPACK_PP_SEQ_ENUM_8(x) x, AGPACK_PP_SEQ_ENUM_7
# define AGPACK_PP_SEQ_ENUM_9(x) x, AGPACK_PP_SEQ_ENUM_8
# define AGPACK_PP_SEQ_ENUM_10(x) x, AGPACK_PP_SEQ_ENUM_9
# define AGPACK_PP_SEQ_ENUM_11(x) x, AGPACK_PP_SEQ_ENUM_10
# define AGPACK_PP_SEQ_ENUM_12(x) x, AGPACK_PP_SEQ_ENUM_11
# define AGPACK_PP_SEQ_ENUM_13(x) x, AGPACK_PP_SEQ_ENUM_12
# define AGPACK_PP_SEQ_ENUM_14(x) x, AGPACK_PP_SEQ_ENUM_13
# define AGPACK_PP_SEQ_ENUM_15(x) x, AGPACK_PP_SEQ_ENUM_14
# define AGPACK_PP_SEQ_ENUM_16(x) x, AGPACK_PP_SEQ_ENUM_15
# define AGPACK_PP_SEQ_ENUM_17(x) x, AGPACK_PP_SEQ_ENUM_16
# define AGPACK_PP_SEQ_ENUM_18(x) x, AGPACK_PP_SEQ_ENUM_17
# define AGPACK_PP_SEQ_ENUM_19(x) x, AGPACK_PP_SEQ_ENUM_18
# define AGPACK_PP_SEQ_ENUM_20(x) x, AGPACK_PP_SEQ_ENUM_19
# define AGPACK_PP_SEQ_ENUM_21(x) x, AGPACK_PP_SEQ_ENUM_20
# define AGPACK_PP_SEQ_ENUM_22(x) x, AGPACK_PP_SEQ_ENUM_21
# define AGPACK_PP_SEQ_ENUM_23(x) x, AGPACK_PP_SEQ_ENUM_22
# define AGPACK_PP_SEQ_ENUM_24(x) x, AGPACK_PP_SEQ_ENUM_23
# define AGPACK_PP_SEQ_ENUM_25(x) x, AGPACK_PP_SEQ_ENUM_24
# define AGPACK_PP_SEQ_ENUM_26(x) x, AGPACK_PP_SEQ_ENUM_25
# define AGPACK_PP_SEQ_ENUM_27(x) x, AGPACK_PP_SEQ_ENUM_26
# define AGPACK_PP_SEQ_ENUM_28(x) x, AGPACK_PP_SEQ_ENUM_27
# define AGPACK_PP_SEQ_ENUM_29(x) x, AGPACK_PP_SEQ_ENUM_28
# define AGPACK_PP_SEQ_ENUM_30(x) x, AGPACK_PP_SEQ_ENUM_29
# define AGPACK_PP_SEQ_ENUM_31(x) x, AGPACK_PP_SEQ_ENUM_30
# define AGPACK_PP_SEQ_ENUM_32(x) x, AGPACK_PP_SEQ_ENUM_31
# define AGPACK_PP_SEQ_ENUM_33(x) x, AGPACK_PP_SEQ_ENUM_32
# define AGPACK_PP_SEQ_ENUM_34(x) x, AGPACK_PP_SEQ_ENUM_33
# define AGPACK_PP_SEQ_ENUM_35(x) x, AGPACK_PP_SEQ_ENUM_34
# define AGPACK_PP_SEQ_ENUM_36(x) x, AGPACK_PP_SEQ_ENUM_35
# define AGPACK_PP_SEQ_ENUM_37(x) x, AGPACK_PP_SEQ_ENUM_36
# define AGPACK_PP_SEQ_ENUM_38(x) x, AGPACK_PP_SEQ_ENUM_37
# define AGPACK_PP_SEQ_ENUM_39(x) x, AGPACK_PP_SEQ_ENUM_38
# define AGPACK_PP_SEQ_ENUM_40(x) x, AGPACK_PP_SEQ_ENUM_39
# define AGPACK_PP_SEQ_ENUM_41(x) x, AGPACK_PP_SEQ_ENUM_40
# define AGPACK_PP_SEQ_ENUM_42(x) x, AGPACK_PP_SEQ_ENUM_41
# define AGPACK_PP_SEQ_ENUM_43(x) x, AGPACK_PP_SEQ_ENUM_42
# define AGPACK_PP_SEQ_ENUM_44(x) x, AGPACK_PP_SEQ_ENUM_43
# define AGPACK_PP_SEQ_ENUM_45(x) x, AGPACK_PP_SEQ_ENUM_44
# define AGPACK_PP_SEQ_ENUM_46(x) x, AGPACK_PP_SEQ_ENUM_45
# define AGPACK_PP_SEQ_ENUM_47(x) x, AGPACK_PP_SEQ_ENUM_46
# define AGPACK_PP_SEQ_ENUM_48(x) x, AGPACK_PP_SEQ_ENUM_47
# define AGPACK_PP_SEQ_ENUM_49(x) x, AGPACK_PP_SEQ_ENUM_48
# define AGPACK_PP_SEQ_ENUM_50(x) x, AGPACK_PP_SEQ_ENUM_49
# define AGPACK_PP_SEQ_ENUM_51(x) x, AGPACK_PP_SEQ_ENUM_50
# define AGPACK_PP_SEQ_ENUM_52(x) x, AGPACK_PP_SEQ_ENUM_51
# define AGPACK_PP_SEQ_ENUM_53(x) x, AGPACK_PP_SEQ_ENUM_52
# define AGPACK_PP_SEQ_ENUM_54(x) x, AGPACK_PP_SEQ_ENUM_53
# define AGPACK_PP_SEQ_ENUM_55(x) x, AGPACK_PP_SEQ_ENUM_54
# define AGPACK_PP_SEQ_ENUM_56(x) x, AGPACK_PP_SEQ_ENUM_55
# define AGPACK_PP_SEQ_ENUM_57(x) x, AGPACK_PP_SEQ_ENUM_56
# define AGPACK_PP_SEQ_ENUM_58(x) x, AGPACK_PP_SEQ_ENUM_57
# define AGPACK_PP_SEQ_ENUM_59(x) x, AGPACK_PP_SEQ_ENUM_58
# define AGPACK_PP_SEQ_ENUM_60(x) x, AGPACK_PP_SEQ_ENUM_59
# define AGPACK_PP_SEQ_ENUM_61(x) x, AGPACK_PP_SEQ_ENUM_60
# define AGPACK_PP_SEQ_ENUM_62(x) x, AGPACK_PP_SEQ_ENUM_61
# define AGPACK_PP_SEQ_ENUM_63(x) x, AGPACK_PP_SEQ_ENUM_62
# define AGPACK_PP_SEQ_ENUM_64(x) x, AGPACK_PP_SEQ_ENUM_63
# define AGPACK_PP_SEQ_ENUM_65(x) x, AGPACK_PP_SEQ_ENUM_64
# define AGPACK_PP_SEQ_ENUM_66(x) x, AGPACK_PP_SEQ_ENUM_65
# define AGPACK_PP_SEQ_ENUM_67(x) x, AGPACK_PP_SEQ_ENUM_66
# define AGPACK_PP_SEQ_ENUM_68(x) x, AGPACK_PP_SEQ_ENUM_67
# define AGPACK_PP_SEQ_ENUM_69(x) x, AGPACK_PP_SEQ_ENUM_68
# define AGPACK_PP_SEQ_ENUM_70(x) x, AGPACK_PP_SEQ_ENUM_69
# define AGPACK_PP_SEQ_ENUM_71(x) x, AGPACK_PP_SEQ_ENUM_70
# define AGPACK_PP_SEQ_ENUM_72(x) x, AGPACK_PP_SEQ_ENUM_71
# define AGPACK_PP_SEQ_ENUM_73(x) x, AGPACK_PP_SEQ_ENUM_72
# define AGPACK_PP_SEQ_ENUM_74(x) x, AGPACK_PP_SEQ_ENUM_73
# define AGPACK_PP_SEQ_ENUM_75(x) x, AGPACK_PP_SEQ_ENUM_74
# define AGPACK_PP_SEQ_ENUM_76(x) x, AGPACK_PP_SEQ_ENUM_75
# define AGPACK_PP_SEQ_ENUM_77(x) x, AGPACK_PP_SEQ_ENUM_76
# define AGPACK_PP_SEQ_ENUM_78(x) x, AGPACK_PP_SEQ_ENUM_77
# define AGPACK_PP_SEQ_ENUM_79(x) x, AGPACK_PP_SEQ_ENUM_78
# define AGPACK_PP_SEQ_ENUM_80(x) x, AGPACK_PP_SEQ_ENUM_79
# define AGPACK_PP_SEQ_ENUM_81(x) x, AGPACK_PP_SEQ_ENUM_80
# define AGPACK_PP_SEQ_ENUM_82(x) x, AGPACK_PP_SEQ_ENUM_81
# define AGPACK_PP_SEQ_ENUM_83(x) x, AGPACK_PP_SEQ_ENUM_82
# define AGPACK_PP_SEQ_ENUM_84(x) x, AGPACK_PP_SEQ_ENUM_83
# define AGPACK_PP_SEQ_ENUM_85(x) x, AGPACK_PP_SEQ_ENUM_84
# define AGPACK_PP_SEQ_ENUM_86(x) x, AGPACK_PP_SEQ_ENUM_85
# define AGPACK_PP_SEQ_ENUM_87(x) x, AGPACK_PP_SEQ_ENUM_86
# define AGPACK_PP_SEQ_ENUM_88(x) x, AGPACK_PP_SEQ_ENUM_87
# define AGPACK_PP_SEQ_ENUM_89(x) x, AGPACK_PP_SEQ_ENUM_88
# define AGPACK_PP_SEQ_ENUM_90(x) x, AGPACK_PP_SEQ_ENUM_89
# define AGPACK_PP_SEQ_ENUM_91(x) x, AGPACK_PP_SEQ_ENUM_90
# define AGPACK_PP_SEQ_ENUM_92(x) x, AGPACK_PP_SEQ_ENUM_91
# define AGPACK_PP_SEQ_ENUM_93(x) x, AGPACK_PP_SEQ_ENUM_92
# define AGPACK_PP_SEQ_ENUM_94(x) x, AGPACK_PP_SEQ_ENUM_93
# define AGPACK_PP_SEQ_ENUM_95(x) x, AGPACK_PP_SEQ_ENUM_94
# define AGPACK_PP_SEQ_ENUM_96(x) x, AGPACK_PP_SEQ_ENUM_95
# define AGPACK_PP_SEQ_ENUM_97(x) x, AGPACK_PP_SEQ_ENUM_96
# define AGPACK_PP_SEQ_ENUM_98(x) x, AGPACK_PP_SEQ_ENUM_97
# define AGPACK_PP_SEQ_ENUM_99(x) x, AGPACK_PP_SEQ_ENUM_98
# define AGPACK_PP_SEQ_ENUM_100(x) x, AGPACK_PP_SEQ_ENUM_99
# define AGPACK_PP_SEQ_ENUM_101(x) x, AGPACK_PP_SEQ_ENUM_100
# define AGPACK_PP_SEQ_ENUM_102(x) x, AGPACK_PP_SEQ_ENUM_101
# define AGPACK_PP_SEQ_ENUM_103(x) x, AGPACK_PP_SEQ_ENUM_102
# define AGPACK_PP_SEQ_ENUM_104(x) x, AGPACK_PP_SEQ_ENUM_103
# define AGPACK_PP_SEQ_ENUM_105(x) x, AGPACK_PP_SEQ_ENUM_104
# define AGPACK_PP_SEQ_ENUM_106(x) x, AGPACK_PP_SEQ_ENUM_105
# define AGPACK_PP_SEQ_ENUM_107(x) x, AGPACK_PP_SEQ_ENUM_106
# define AGPACK_PP_SEQ_ENUM_108(x) x, AGPACK_PP_SEQ_ENUM_107
# define AGPACK_PP_SEQ_ENUM_109(x) x, AGPACK_PP_SEQ_ENUM_108
# define AGPACK_PP_SEQ_ENUM_110(x) x, AGPACK_PP_SEQ_ENUM_109
# define AGPACK_PP_SEQ_ENUM_111(x) x, AGPACK_PP_SEQ_ENUM_110
# define AGPACK_PP_SEQ_ENUM_112(x) x, AGPACK_PP_SEQ_ENUM_111
# define AGPACK_PP_SEQ_ENUM_113(x) x, AGPACK_PP_SEQ_ENUM_112
# define AGPACK_PP_SEQ_ENUM_114(x) x, AGPACK_PP_SEQ_ENUM_113
# define AGPACK_PP_SEQ_ENUM_115(x) x, AGPACK_PP_SEQ_ENUM_114
# define AGPACK_PP_SEQ_ENUM_116(x) x, AGPACK_PP_SEQ_ENUM_115
# define AGPACK_PP_SEQ_ENUM_117(x) x, AGPACK_PP_SEQ_ENUM_116
# define AGPACK_PP_SEQ_ENUM_118(x) x, AGPACK_PP_SEQ_ENUM_117
# define AGPACK_PP_SEQ_ENUM_119(x) x, AGPACK_PP_SEQ_ENUM_118
# define AGPACK_PP_SEQ_ENUM_120(x) x, AGPACK_PP_SEQ_ENUM_119
# define AGPACK_PP_SEQ_ENUM_121(x) x, AGPACK_PP_SEQ_ENUM_120
# define AGPACK_PP_SEQ_ENUM_122(x) x, AGPACK_PP_SEQ_ENUM_121
# define AGPACK_PP_SEQ_ENUM_123(x) x, AGPACK_PP_SEQ_ENUM_122
# define AGPACK_PP_SEQ_ENUM_124(x) x, AGPACK_PP_SEQ_ENUM_123
# define AGPACK_PP_SEQ_ENUM_125(x) x, AGPACK_PP_SEQ_ENUM_124
# define AGPACK_PP_SEQ_ENUM_126(x) x, AGPACK_PP_SEQ_ENUM_125
# define AGPACK_PP_SEQ_ENUM_127(x) x, AGPACK_PP_SEQ_ENUM_126
# define AGPACK_PP_SEQ_ENUM_128(x) x, AGPACK_PP_SEQ_ENUM_127
# define AGPACK_PP_SEQ_ENUM_129(x) x, AGPACK_PP_SEQ_ENUM_128
# define AGPACK_PP_SEQ_ENUM_130(x) x, AGPACK_PP_SEQ_ENUM_129
# define AGPACK_PP_SEQ_ENUM_131(x) x, AGPACK_PP_SEQ_ENUM_130
# define AGPACK_PP_SEQ_ENUM_132(x) x, AGPACK_PP_SEQ_ENUM_131
# define AGPACK_PP_SEQ_ENUM_133(x) x, AGPACK_PP_SEQ_ENUM_132
# define AGPACK_PP_SEQ_ENUM_134(x) x, AGPACK_PP_SEQ_ENUM_133
# define AGPACK_PP_SEQ_ENUM_135(x) x, AGPACK_PP_SEQ_ENUM_134
# define AGPACK_PP_SEQ_ENUM_136(x) x, AGPACK_PP_SEQ_ENUM_135
# define AGPACK_PP_SEQ_ENUM_137(x) x, AGPACK_PP_SEQ_ENUM_136
# define AGPACK_PP_SEQ_ENUM_138(x) x, AGPACK_PP_SEQ_ENUM_137
# define AGPACK_PP_SEQ_ENUM_139(x) x, AGPACK_PP_SEQ_ENUM_138
# define AGPACK_PP_SEQ_ENUM_140(x) x, AGPACK_PP_SEQ_ENUM_139
# define AGPACK_PP_SEQ_ENUM_141(x) x, AGPACK_PP_SEQ_ENUM_140
# define AGPACK_PP_SEQ_ENUM_142(x) x, AGPACK_PP_SEQ_ENUM_141
# define AGPACK_PP_SEQ_ENUM_143(x) x, AGPACK_PP_SEQ_ENUM_142
# define AGPACK_PP_SEQ_ENUM_144(x) x, AGPACK_PP_SEQ_ENUM_143
# define AGPACK_PP_SEQ_ENUM_145(x) x, AGPACK_PP_SEQ_ENUM_144
# define AGPACK_PP_SEQ_ENUM_146(x) x, AGPACK_PP_SEQ_ENUM_145
# define AGPACK_PP_SEQ_ENUM_147(x) x, AGPACK_PP_SEQ_ENUM_146
# define AGPACK_PP_SEQ_ENUM_148(x) x, AGPACK_PP_SEQ_ENUM_147
# define AGPACK_PP_SEQ_ENUM_149(x) x, AGPACK_PP_SEQ_ENUM_148
# define AGPACK_PP_SEQ_ENUM_150(x) x, AGPACK_PP_SEQ_ENUM_149
# define AGPACK_PP_SEQ_ENUM_151(x) x, AGPACK_PP_SEQ_ENUM_150
# define AGPACK_PP_SEQ_ENUM_152(x) x, AGPACK_PP_SEQ_ENUM_151
# define AGPACK_PP_SEQ_ENUM_153(x) x, AGPACK_PP_SEQ_ENUM_152
# define AGPACK_PP_SEQ_ENUM_154(x) x, AGPACK_PP_SEQ_ENUM_153
# define AGPACK_PP_SEQ_ENUM_155(x) x, AGPACK_PP_SEQ_ENUM_154
# define AGPACK_PP_SEQ_ENUM_156(x) x, AGPACK_PP_SEQ_ENUM_155
# define AGPACK_PP_SEQ_ENUM_157(x) x, AGPACK_PP_SEQ_ENUM_156
# define AGPACK_PP_SEQ_ENUM_158(x) x, AGPACK_PP_SEQ_ENUM_157
# define AGPACK_PP_SEQ_ENUM_159(x) x, AGPACK_PP_SEQ_ENUM_158
# define AGPACK_PP_SEQ_ENUM_160(x) x, AGPACK_PP_SEQ_ENUM_159
# define AGPACK_PP_SEQ_ENUM_161(x) x, AGPACK_PP_SEQ_ENUM_160
# define AGPACK_PP_SEQ_ENUM_162(x) x, AGPACK_PP_SEQ_ENUM_161
# define AGPACK_PP_SEQ_ENUM_163(x) x, AGPACK_PP_SEQ_ENUM_162
# define AGPACK_PP_SEQ_ENUM_164(x) x, AGPACK_PP_SEQ_ENUM_163
# define AGPACK_PP_SEQ_ENUM_165(x) x, AGPACK_PP_SEQ_ENUM_164
# define AGPACK_PP_SEQ_ENUM_166(x) x, AGPACK_PP_SEQ_ENUM_165
# define AGPACK_PP_SEQ_ENUM_167(x) x, AGPACK_PP_SEQ_ENUM_166
# define AGPACK_PP_SEQ_ENUM_168(x) x, AGPACK_PP_SEQ_ENUM_167
# define AGPACK_PP_SEQ_ENUM_169(x) x, AGPACK_PP_SEQ_ENUM_168
# define AGPACK_PP_SEQ_ENUM_170(x) x, AGPACK_PP_SEQ_ENUM_169
# define AGPACK_PP_SEQ_ENUM_171(x) x, AGPACK_PP_SEQ_ENUM_170
# define AGPACK_PP_SEQ_ENUM_172(x) x, AGPACK_PP_SEQ_ENUM_171
# define AGPACK_PP_SEQ_ENUM_173(x) x, AGPACK_PP_SEQ_ENUM_172
# define AGPACK_PP_SEQ_ENUM_174(x) x, AGPACK_PP_SEQ_ENUM_173
# define AGPACK_PP_SEQ_ENUM_175(x) x, AGPACK_PP_SEQ_ENUM_174
# define AGPACK_PP_SEQ_ENUM_176(x) x, AGPACK_PP_SEQ_ENUM_175
# define AGPACK_PP_SEQ_ENUM_177(x) x, AGPACK_PP_SEQ_ENUM_176
# define AGPACK_PP_SEQ_ENUM_178(x) x, AGPACK_PP_SEQ_ENUM_177
# define AGPACK_PP_SEQ_ENUM_179(x) x, AGPACK_PP_SEQ_ENUM_178
# define AGPACK_PP_SEQ_ENUM_180(x) x, AGPACK_PP_SEQ_ENUM_179
# define AGPACK_PP_SEQ_ENUM_181(x) x, AGPACK_PP_SEQ_ENUM_180
# define AGPACK_PP_SEQ_ENUM_182(x) x, AGPACK_PP_SEQ_ENUM_181
# define AGPACK_PP_SEQ_ENUM_183(x) x, AGPACK_PP_SEQ_ENUM_182
# define AGPACK_PP_SEQ_ENUM_184(x) x, AGPACK_PP_SEQ_ENUM_183
# define AGPACK_PP_SEQ_ENUM_185(x) x, AGPACK_PP_SEQ_ENUM_184
# define AGPACK_PP_SEQ_ENUM_186(x) x, AGPACK_PP_SEQ_ENUM_185
# define AGPACK_PP_SEQ_ENUM_187(x) x, AGPACK_PP_SEQ_ENUM_186
# define AGPACK_PP_SEQ_ENUM_188(x) x, AGPACK_PP_SEQ_ENUM_187
# define AGPACK_PP_SEQ_ENUM_189(x) x, AGPACK_PP_SEQ_ENUM_188
# define AGPACK_PP_SEQ_ENUM_190(x) x, AGPACK_PP_SEQ_ENUM_189
# define AGPACK_PP_SEQ_ENUM_191(x) x, AGPACK_PP_SEQ_ENUM_190
# define AGPACK_PP_SEQ_ENUM_192(x) x, AGPACK_PP_SEQ_ENUM_191
# define AGPACK_PP_SEQ_ENUM_193(x) x, AGPACK_PP_SEQ_ENUM_192
# define AGPACK_PP_SEQ_ENUM_194(x) x, AGPACK_PP_SEQ_ENUM_193
# define AGPACK_PP_SEQ_ENUM_195(x) x, AGPACK_PP_SEQ_ENUM_194
# define AGPACK_PP_SEQ_ENUM_196(x) x, AGPACK_PP_SEQ_ENUM_195
# define AGPACK_PP_SEQ_ENUM_197(x) x, AGPACK_PP_SEQ_ENUM_196
# define AGPACK_PP_SEQ_ENUM_198(x) x, AGPACK_PP_SEQ_ENUM_197
# define AGPACK_PP_SEQ_ENUM_199(x) x, AGPACK_PP_SEQ_ENUM_198
# define AGPACK_PP_SEQ_ENUM_200(x) x, AGPACK_PP_SEQ_ENUM_199
# define AGPACK_PP_SEQ_ENUM_201(x) x, AGPACK_PP_SEQ_ENUM_200
# define AGPACK_PP_SEQ_ENUM_202(x) x, AGPACK_PP_SEQ_ENUM_201
# define AGPACK_PP_SEQ_ENUM_203(x) x, AGPACK_PP_SEQ_ENUM_202
# define AGPACK_PP_SEQ_ENUM_204(x) x, AGPACK_PP_SEQ_ENUM_203
# define AGPACK_PP_SEQ_ENUM_205(x) x, AGPACK_PP_SEQ_ENUM_204
# define AGPACK_PP_SEQ_ENUM_206(x) x, AGPACK_PP_SEQ_ENUM_205
# define AGPACK_PP_SEQ_ENUM_207(x) x, AGPACK_PP_SEQ_ENUM_206
# define AGPACK_PP_SEQ_ENUM_208(x) x, AGPACK_PP_SEQ_ENUM_207
# define AGPACK_PP_SEQ_ENUM_209(x) x, AGPACK_PP_SEQ_ENUM_208
# define AGPACK_PP_SEQ_ENUM_210(x) x, AGPACK_PP_SEQ_ENUM_209
# define AGPACK_PP_SEQ_ENUM_211(x) x, AGPACK_PP_SEQ_ENUM_210
# define AGPACK_PP_SEQ_ENUM_212(x) x, AGPACK_PP_SEQ_ENUM_211
# define AGPACK_PP_SEQ_ENUM_213(x) x, AGPACK_PP_SEQ_ENUM_212
# define AGPACK_PP_SEQ_ENUM_214(x) x, AGPACK_PP_SEQ_ENUM_213
# define AGPACK_PP_SEQ_ENUM_215(x) x, AGPACK_PP_SEQ_ENUM_214
# define AGPACK_PP_SEQ_ENUM_216(x) x, AGPACK_PP_SEQ_ENUM_215
# define AGPACK_PP_SEQ_ENUM_217(x) x, AGPACK_PP_SEQ_ENUM_216
# define AGPACK_PP_SEQ_ENUM_218(x) x, AGPACK_PP_SEQ_ENUM_217
# define AGPACK_PP_SEQ_ENUM_219(x) x, AGPACK_PP_SEQ_ENUM_218
# define AGPACK_PP_SEQ_ENUM_220(x) x, AGPACK_PP_SEQ_ENUM_219
# define AGPACK_PP_SEQ_ENUM_221(x) x, AGPACK_PP_SEQ_ENUM_220
# define AGPACK_PP_SEQ_ENUM_222(x) x, AGPACK_PP_SEQ_ENUM_221
# define AGPACK_PP_SEQ_ENUM_223(x) x, AGPACK_PP_SEQ_ENUM_222
# define AGPACK_PP_SEQ_ENUM_224(x) x, AGPACK_PP_SEQ_ENUM_223
# define AGPACK_PP_SEQ_ENUM_225(x) x, AGPACK_PP_SEQ_ENUM_224
# define AGPACK_PP_SEQ_ENUM_226(x) x, AGPACK_PP_SEQ_ENUM_225
# define AGPACK_PP_SEQ_ENUM_227(x) x, AGPACK_PP_SEQ_ENUM_226
# define AGPACK_PP_SEQ_ENUM_228(x) x, AGPACK_PP_SEQ_ENUM_227
# define AGPACK_PP_SEQ_ENUM_229(x) x, AGPACK_PP_SEQ_ENUM_228
# define AGPACK_PP_SEQ_ENUM_230(x) x, AGPACK_PP_SEQ_ENUM_229
# define AGPACK_PP_SEQ_ENUM_231(x) x, AGPACK_PP_SEQ_ENUM_230
# define AGPACK_PP_SEQ_ENUM_232(x) x, AGPACK_PP_SEQ_ENUM_231
# define AGPACK_PP_SEQ_ENUM_233(x) x, AGPACK_PP_SEQ_ENUM_232
# define AGPACK_PP_SEQ_ENUM_234(x) x, AGPACK_PP_SEQ_ENUM_233
# define AGPACK_PP_SEQ_ENUM_235(x) x, AGPACK_PP_SEQ_ENUM_234
# define AGPACK_PP_SEQ_ENUM_236(x) x, AGPACK_PP_SEQ_ENUM_235
# define AGPACK_PP_SEQ_ENUM_237(x) x, AGPACK_PP_SEQ_ENUM_236
# define AGPACK_PP_SEQ_ENUM_238(x) x, AGPACK_PP_SEQ_ENUM_237
# define AGPACK_PP_SEQ_ENUM_239(x) x, AGPACK_PP_SEQ_ENUM_238
# define AGPACK_PP_SEQ_ENUM_240(x) x, AGPACK_PP_SEQ_ENUM_239
# define AGPACK_PP_SEQ_ENUM_241(x) x, AGPACK_PP_SEQ_ENUM_240
# define AGPACK_PP_SEQ_ENUM_242(x) x, AGPACK_PP_SEQ_ENUM_241
# define AGPACK_PP_SEQ_ENUM_243(x) x, AGPACK_PP_SEQ_ENUM_242
# define AGPACK_PP_SEQ_ENUM_244(x) x, AGPACK_PP_SEQ_ENUM_243
# define AGPACK_PP_SEQ_ENUM_245(x) x, AGPACK_PP_SEQ_ENUM_244
# define AGPACK_PP_SEQ_ENUM_246(x) x, AGPACK_PP_SEQ_ENUM_245
# define AGPACK_PP_SEQ_ENUM_247(x) x, AGPACK_PP_SEQ_ENUM_246
# define AGPACK_PP_SEQ_ENUM_248(x) x, AGPACK_PP_SEQ_ENUM_247
# define AGPACK_PP_SEQ_ENUM_249(x) x, AGPACK_PP_SEQ_ENUM_248
# define AGPACK_PP_SEQ_ENUM_250(x) x, AGPACK_PP_SEQ_ENUM_249
# define AGPACK_PP_SEQ_ENUM_251(x) x, AGPACK_PP_SEQ_ENUM_250
# define AGPACK_PP_SEQ_ENUM_252(x) x, AGPACK_PP_SEQ_ENUM_251
# define AGPACK_PP_SEQ_ENUM_253(x) x, AGPACK_PP_SEQ_ENUM_252
# define AGPACK_PP_SEQ_ENUM_254(x) x, AGPACK_PP_SEQ_ENUM_253
# define AGPACK_PP_SEQ_ENUM_255(x) x, AGPACK_PP_SEQ_ENUM_254
# define AGPACK_PP_SEQ_ENUM_256(x) x, AGPACK_PP_SEQ_ENUM_255
#
# endif
