# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* Revised by Paul Mensonides (2011) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_LIST_TO_SEQ_HPP
# define AGPACK_PREPROCESSOR_LIST_TO_SEQ_HPP
#
# include <agpack/preprocessor/list/for_each.hpp>
#
# /* AGPACK_PP_LIST_TO_SEQ */
#
# define AGPACK_PP_LIST_TO_SEQ(list) \
    AGPACK_PP_LIST_FOR_EACH(AGPACK_PP_LIST_TO_SEQ_MACRO, ~, list) \
    /**/
# define AGPACK_PP_LIST_TO_SEQ_MACRO(r, data, elem) (elem)
#
# /* AGPACK_PP_LIST_TO_SEQ_R */
#
# define AGPACK_PP_LIST_TO_SEQ_R(r, list) \
    AGPACK_PP_LIST_FOR_EACH_R(r, AGPACK_PP_LIST_TO_SEQ_MACRO, ~, list) \
    /**/
#
# endif /* AGPACK_PREPROCESSOR_LIST_TO_SEQ_HPP */
