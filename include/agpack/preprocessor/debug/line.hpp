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
# ifndef AGPACK_PREPROCESSOR_DEBUG_LINE_HPP
# define AGPACK_PREPROCESSOR_DEBUG_LINE_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/iteration/iterate.hpp>
# include <agpack/preprocessor/stringize.hpp>
#
# /* AGPACK_PP_LINE */
#
# if AGPACK_PP_CONFIG_EXTENDED_LINE_INFO
#    define AGPACK_PP_LINE(line, file) line AGPACK_PP_CAT(AGPACK_PP_LINE_, AGPACK_PP_IS_ITERATING)(file)
#    define AGPACK_PP_LINE_AGPACK_PP_IS_ITERATING(file) #file
#    define AGPACK_PP_LINE_1(file) AGPACK_PP_STRINGIZE(file AGPACK_PP_CAT(AGPACK_PP_LINE_I_, AGPACK_PP_ITERATION_DEPTH())())
#    define AGPACK_PP_LINE_I_1() [AGPACK_PP_FRAME_ITERATION(1)]
#    define AGPACK_PP_LINE_I_2() AGPACK_PP_LINE_I_1()[AGPACK_PP_FRAME_ITERATION(2)]
#    define AGPACK_PP_LINE_I_3() AGPACK_PP_LINE_I_2()[AGPACK_PP_FRAME_ITERATION(3)]
#    define AGPACK_PP_LINE_I_4() AGPACK_PP_LINE_I_3()[AGPACK_PP_FRAME_ITERATION(4)]
#    define AGPACK_PP_LINE_I_5() AGPACK_PP_LINE_I_4()[AGPACK_PP_FRAME_ITERATION(5)]
# else
#    define AGPACK_PP_LINE(line, file) line __FILE__
# endif
#
# endif
