# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2016.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_SEQ_DETAIL_TO_LIST_MSVC_HPP
# define AGPACK_PREPROCESSOR_SEQ_DETAIL_TO_LIST_MSVC_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# define AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_STATE_RESULT(state) \
    AGPACK_PP_TUPLE_ELEM(2, 0, state) \
/**/
# define AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_STATE_SIZE(state) \
    AGPACK_PP_TUPLE_ELEM(2, 1, state) \
/**/
# define AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_PRED(d,state) \
    AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_STATE_SIZE(state) \
/**/
# define AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_OP(d,state) \
    ( \
    AGPACK_PP_CAT(AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_STATE_RESULT(state),), \
    AGPACK_PP_DEC(AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_STATE_SIZE(state)) \
    ) \
/**/
#
# /* AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC */
#
# define AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC(result,seqsize) \
    AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_STATE_RESULT \
        ( \
        AGPACK_PP_WHILE \
            ( \
            AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_PRED, \
            AGPACK_PP_SEQ_DETAIL_TO_LIST_MSVC_OP, \
            (result,seqsize) \
            ) \
        ) \
/**/
# endif // AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#
# endif // AGPACK_PREPROCESSOR_SEQ_DETAIL_TO_LIST_MSVC_HPP
