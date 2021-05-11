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
# ifndef AGPACK_PREPROCESSOR_ITERATION_ITERATE_HPP
# define AGPACK_PREPROCESSOR_ITERATION_ITERATE_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/array/elem.hpp>
# include <agpack/preprocessor/array/size.hpp>
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/slot/slot.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_ITERATION_DEPTH */
#
# define AGPACK_PP_ITERATION_DEPTH() 0
#
# /* AGPACK_PP_ITERATION */
#
# define AGPACK_PP_ITERATION() AGPACK_PP_CAT(AGPACK_PP_ITERATION_, AGPACK_PP_ITERATION_DEPTH())
#
# /* AGPACK_PP_ITERATION_START && AGPACK_PP_ITERATION_FINISH */
#
# define AGPACK_PP_ITERATION_START() AGPACK_PP_CAT(AGPACK_PP_ITERATION_START_, AGPACK_PP_ITERATION_DEPTH())
# define AGPACK_PP_ITERATION_FINISH() AGPACK_PP_CAT(AGPACK_PP_ITERATION_FINISH_, AGPACK_PP_ITERATION_DEPTH())
#
# /* AGPACK_PP_ITERATION_FLAGS */
#
# define AGPACK_PP_ITERATION_FLAGS() (AGPACK_PP_CAT(AGPACK_PP_ITERATION_FLAGS_, AGPACK_PP_ITERATION_DEPTH())())
#
# /* AGPACK_PP_FRAME_ITERATION */
#
# define AGPACK_PP_FRAME_ITERATION(i) AGPACK_PP_CAT(AGPACK_PP_ITERATION_, i)
#
# /* AGPACK_PP_FRAME_START && AGPACK_PP_FRAME_FINISH */
#
# define AGPACK_PP_FRAME_START(i) AGPACK_PP_CAT(AGPACK_PP_ITERATION_START_, i)
# define AGPACK_PP_FRAME_FINISH(i) AGPACK_PP_CAT(AGPACK_PP_ITERATION_FINISH_, i)
#
# /* AGPACK_PP_FRAME_FLAGS */
#
# define AGPACK_PP_FRAME_FLAGS(i) (AGPACK_PP_CAT(AGPACK_PP_ITERATION_FLAGS_, i)())
#
# /* AGPACK_PP_RELATIVE_ITERATION */
#
# define AGPACK_PP_RELATIVE_ITERATION(i) AGPACK_PP_CAT(AGPACK_PP_RELATIVE_, i)(AGPACK_PP_ITERATION_)
#
# define AGPACK_PP_RELATIVE_0(m) AGPACK_PP_CAT(m, AGPACK_PP_ITERATION_DEPTH())
# define AGPACK_PP_RELATIVE_1(m) AGPACK_PP_CAT(m, AGPACK_PP_DEC(AGPACK_PP_ITERATION_DEPTH()))
# define AGPACK_PP_RELATIVE_2(m) AGPACK_PP_CAT(m, AGPACK_PP_DEC(AGPACK_PP_DEC(AGPACK_PP_ITERATION_DEPTH())))
# define AGPACK_PP_RELATIVE_3(m) AGPACK_PP_CAT(m, AGPACK_PP_DEC(AGPACK_PP_DEC(AGPACK_PP_DEC(AGPACK_PP_ITERATION_DEPTH()))))
# define AGPACK_PP_RELATIVE_4(m) AGPACK_PP_CAT(m, AGPACK_PP_DEC(AGPACK_PP_DEC(AGPACK_PP_DEC(AGPACK_PP_DEC(AGPACK_PP_ITERATION_DEPTH())))))
#
# /* AGPACK_PP_RELATIVE_START && AGPACK_PP_RELATIVE_FINISH */
#
# define AGPACK_PP_RELATIVE_START(i) AGPACK_PP_CAT(AGPACK_PP_RELATIVE_, i)(AGPACK_PP_ITERATION_START_)
# define AGPACK_PP_RELATIVE_FINISH(i) AGPACK_PP_CAT(AGPACK_PP_RELATIVE_, i)(AGPACK_PP_ITERATION_FINISH_)
#
# /* AGPACK_PP_RELATIVE_FLAGS */
#
# define AGPACK_PP_RELATIVE_FLAGS(i) (AGPACK_PP_CAT(AGPACK_PP_RELATIVE_, i)(AGPACK_PP_ITERATION_FLAGS_)())
#
# /* AGPACK_PP_ITERATE */
#
# define AGPACK_PP_ITERATE() AGPACK_PP_CAT(AGPACK_PP_ITERATE_, AGPACK_PP_INC(AGPACK_PP_ITERATION_DEPTH()))
#
# define AGPACK_PP_ITERATE_1 <agpack/preprocessor/iteration/detail/iter/forward1.hpp>
# define AGPACK_PP_ITERATE_2 <agpack/preprocessor/iteration/detail/iter/forward2.hpp>
# define AGPACK_PP_ITERATE_3 <agpack/preprocessor/iteration/detail/iter/forward3.hpp>
# define AGPACK_PP_ITERATE_4 <agpack/preprocessor/iteration/detail/iter/forward4.hpp>
# define AGPACK_PP_ITERATE_5 <agpack/preprocessor/iteration/detail/iter/forward5.hpp>
#
# endif
