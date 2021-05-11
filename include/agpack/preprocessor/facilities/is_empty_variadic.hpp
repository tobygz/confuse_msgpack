# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
# define AGPACK_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if AGPACK_PP_VARIADICS
#
# include <agpack/preprocessor/punctuation/is_begin_parens.hpp>
# include <agpack/preprocessor/facilities/detail/is_empty.hpp>
#
#if AGPACK_PP_VARIADICS_MSVC && _MSC_VER <= 1400
#
#define AGPACK_PP_IS_EMPTY(param) \
    AGPACK_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      AGPACK_PP_IS_BEGIN_PARENS \
        ( \
        param \
        ) \
      ) \
      ( \
      AGPACK_PP_IS_EMPTY_ZERO, \
      AGPACK_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (param) \
/**/
#define AGPACK_PP_IS_EMPTY_ZERO(param) 0
# else
#define AGPACK_PP_IS_EMPTY(...) \
    AGPACK_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      AGPACK_PP_IS_BEGIN_PARENS \
        ( \
        __VA_ARGS__ \
        ) \
      ) \
      ( \
      AGPACK_PP_IS_EMPTY_ZERO, \
      AGPACK_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (__VA_ARGS__) \
/**/
#define AGPACK_PP_IS_EMPTY_ZERO(...) 0
# endif /* AGPACK_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
# endif /* AGPACK_PP_VARIADICS */
# endif /* AGPACK_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP */
