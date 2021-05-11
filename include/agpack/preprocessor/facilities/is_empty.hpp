# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
# define AGPACK_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if AGPACK_PP_VARIADICS
#
# include <agpack/preprocessor/facilities/is_empty_variadic.hpp>
#
# else
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC() && ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/facilities/identity.hpp>
# else
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/detail/split.hpp>
# endif
#
# /* AGPACK_PP_IS_EMPTY */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC() && ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_IS_EMPTY(x) AGPACK_PP_IS_EMPTY_I(x AGPACK_PP_IS_EMPTY_HELPER)
#    define AGPACK_PP_IS_EMPTY_I(contents) AGPACK_PP_TUPLE_ELEM(2, 1, (AGPACK_PP_IS_EMPTY_DEF_ ## contents()))
#    define AGPACK_PP_IS_EMPTY_DEF_AGPACK_PP_IS_EMPTY_HELPER 1, AGPACK_PP_IDENTITY(1)
#    define AGPACK_PP_IS_EMPTY_HELPER() , 0
# else
#    if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#        define AGPACK_PP_IS_EMPTY(x) AGPACK_PP_IS_EMPTY_I(AGPACK_PP_IS_EMPTY_HELPER x ())
#        define AGPACK_PP_IS_EMPTY_I(test) AGPACK_PP_IS_EMPTY_II(AGPACK_PP_SPLIT(0, AGPACK_PP_CAT(AGPACK_PP_IS_EMPTY_DEF_, test)))
#        define AGPACK_PP_IS_EMPTY_II(id) id
#    else
#        define AGPACK_PP_IS_EMPTY(x) AGPACK_PP_IS_EMPTY_I((AGPACK_PP_IS_EMPTY_HELPER x ()))
#        define AGPACK_PP_IS_EMPTY_I(par) AGPACK_PP_IS_EMPTY_II ## par
#        define AGPACK_PP_IS_EMPTY_II(test) AGPACK_PP_SPLIT(0, AGPACK_PP_CAT(AGPACK_PP_IS_EMPTY_DEF_, test))
#    endif
#    define AGPACK_PP_IS_EMPTY_HELPER() 1
#    define AGPACK_PP_IS_EMPTY_DEF_1 1, AGPACK_PP_NIL
#    define AGPACK_PP_IS_EMPTY_DEF_AGPACK_PP_IS_EMPTY_HELPER 0, AGPACK_PP_NIL
# endif
#
# endif /* AGPACK_PP_VARIADICS */
#
# endif /* AGPACK_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP */
