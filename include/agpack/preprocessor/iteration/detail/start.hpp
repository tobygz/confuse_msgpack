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
# include <agpack/preprocessor/slot/detail/shared.hpp>
#
# undef AGPACK_PP_LOCAL_SE
#
# undef AGPACK_PP_LOCAL_SE_DIGIT_1
# undef AGPACK_PP_LOCAL_SE_DIGIT_2
# undef AGPACK_PP_LOCAL_SE_DIGIT_3
# undef AGPACK_PP_LOCAL_SE_DIGIT_4
# undef AGPACK_PP_LOCAL_SE_DIGIT_5
# undef AGPACK_PP_LOCAL_SE_DIGIT_6
# undef AGPACK_PP_LOCAL_SE_DIGIT_7
# undef AGPACK_PP_LOCAL_SE_DIGIT_8
# undef AGPACK_PP_LOCAL_SE_DIGIT_9
# undef AGPACK_PP_LOCAL_SE_DIGIT_10
#
# if AGPACK_PP_SLOT_TEMP_3 == 0
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 0
# elif AGPACK_PP_SLOT_TEMP_3 == 1
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 1
# elif AGPACK_PP_SLOT_TEMP_3 == 2
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 2
# elif AGPACK_PP_SLOT_TEMP_3 == 3
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 3
# elif AGPACK_PP_SLOT_TEMP_3 == 4
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 4
# elif AGPACK_PP_SLOT_TEMP_3 == 5
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 5
# elif AGPACK_PP_SLOT_TEMP_3 == 6
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 6
# elif AGPACK_PP_SLOT_TEMP_3 == 7
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 7
# elif AGPACK_PP_SLOT_TEMP_3 == 8
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 8
# elif AGPACK_PP_SLOT_TEMP_3 == 9
#    define AGPACK_PP_LOCAL_SE_DIGIT_3 9
# endif
#
# if AGPACK_PP_SLOT_TEMP_2 == 0
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 0
# elif AGPACK_PP_SLOT_TEMP_2 == 1
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 1
# elif AGPACK_PP_SLOT_TEMP_2 == 2
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 2
# elif AGPACK_PP_SLOT_TEMP_2 == 3
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 3
# elif AGPACK_PP_SLOT_TEMP_2 == 4
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 4
# elif AGPACK_PP_SLOT_TEMP_2 == 5
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 5
# elif AGPACK_PP_SLOT_TEMP_2 == 6
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 6
# elif AGPACK_PP_SLOT_TEMP_2 == 7
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 7
# elif AGPACK_PP_SLOT_TEMP_2 == 8
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 8
# elif AGPACK_PP_SLOT_TEMP_2 == 9
#    define AGPACK_PP_LOCAL_SE_DIGIT_2 9
# endif
#
# if AGPACK_PP_SLOT_TEMP_1 == 0
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 0
# elif AGPACK_PP_SLOT_TEMP_1 == 1
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 1
# elif AGPACK_PP_SLOT_TEMP_1 == 2
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 2
# elif AGPACK_PP_SLOT_TEMP_1 == 3
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 3
# elif AGPACK_PP_SLOT_TEMP_1 == 4
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 4
# elif AGPACK_PP_SLOT_TEMP_1 == 5
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 5
# elif AGPACK_PP_SLOT_TEMP_1 == 6
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 6
# elif AGPACK_PP_SLOT_TEMP_1 == 7
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 7
# elif AGPACK_PP_SLOT_TEMP_1 == 8
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 8
# elif AGPACK_PP_SLOT_TEMP_1 == 9
#    define AGPACK_PP_LOCAL_SE_DIGIT_1 9
# endif
#
# if AGPACK_PP_LOCAL_SE_DIGIT_3
#    define AGPACK_PP_LOCAL_SE() AGPACK_PP_SLOT_CC_3(AGPACK_PP_LOCAL_SE_DIGIT_3, AGPACK_PP_LOCAL_SE_DIGIT_2, AGPACK_PP_LOCAL_SE_DIGIT_1)
# elif AGPACK_PP_LOCAL_SE_DIGIT_2
#    define AGPACK_PP_LOCAL_SE() AGPACK_PP_SLOT_CC_2(AGPACK_PP_LOCAL_SE_DIGIT_2, AGPACK_PP_LOCAL_SE_DIGIT_1)
# else
#    define AGPACK_PP_LOCAL_SE() AGPACK_PP_LOCAL_SE_DIGIT_1
# endif
