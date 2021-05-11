# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  *
#  * See http://www.boost.org for most recent version.
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# ifndef AGPACK_PREPROCESSOR_LIST_ADT_HPP
# define AGPACK_PREPROCESSOR_LIST_ADT_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/detail/is_binary.hpp>
# include <agpack/preprocessor/logical/compl.hpp>
# include <agpack/preprocessor/tuple/eat.hpp>
#
# /* AGPACK_PP_LIST_CONS */
#
# define AGPACK_PP_LIST_CONS(head, tail) (head, tail)
#
# /* AGPACK_PP_LIST_NIL */
#
# define AGPACK_PP_LIST_NIL AGPACK_PP_NIL
#
# /* AGPACK_PP_LIST_FIRST */
#
# define AGPACK_PP_LIST_FIRST(list) AGPACK_PP_LIST_FIRST_D(list)
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_LIST_FIRST_D(list) AGPACK_PP_LIST_FIRST_I list
# else
#    define AGPACK_PP_LIST_FIRST_D(list) AGPACK_PP_LIST_FIRST_I ## list
# endif
#
# define AGPACK_PP_LIST_FIRST_I(head, tail) head
#
# /* AGPACK_PP_LIST_REST */
#
# define AGPACK_PP_LIST_REST(list) AGPACK_PP_LIST_REST_D(list)
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_LIST_REST_D(list) AGPACK_PP_LIST_REST_I list
# else
#    define AGPACK_PP_LIST_REST_D(list) AGPACK_PP_LIST_REST_I ## list
# endif
#
# define AGPACK_PP_LIST_REST_I(head, tail) tail
#
# /* AGPACK_PP_LIST_IS_CONS */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_BCC()
#    define AGPACK_PP_LIST_IS_CONS(list) AGPACK_PP_LIST_IS_CONS_D(list)
#    define AGPACK_PP_LIST_IS_CONS_D(list) AGPACK_PP_LIST_IS_CONS_ ## list
#    define AGPACK_PP_LIST_IS_CONS_(head, tail) 1
#    define AGPACK_PP_LIST_IS_CONS_AGPACK_PP_NIL 0
# else
#    define AGPACK_PP_LIST_IS_CONS(list) AGPACK_PP_IS_BINARY(list)
# endif
#
# /* AGPACK_PP_LIST_IS_NIL */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_BCC()
#    define AGPACK_PP_LIST_IS_NIL(list) AGPACK_PP_COMPL(AGPACK_PP_IS_BINARY(list))
# else
#    define AGPACK_PP_LIST_IS_NIL(list) AGPACK_PP_COMPL(AGPACK_PP_LIST_IS_CONS(list))
# endif
#
# endif
