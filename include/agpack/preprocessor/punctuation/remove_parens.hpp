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
#ifndef AGPACK_PREPROCESSOR_REMOVE_PARENS_HPP
#define AGPACK_PREPROCESSOR_REMOVE_PARENS_HPP

#include <agpack/preprocessor/config/config.hpp>

#if AGPACK_PP_VARIADICS

#include <agpack/preprocessor/control/iif.hpp>
#include <agpack/preprocessor/facilities/identity.hpp>
#include <agpack/preprocessor/punctuation/is_begin_parens.hpp>
#include <agpack/preprocessor/tuple/enum.hpp>

#define AGPACK_PP_REMOVE_PARENS(param) \
    AGPACK_PP_IIF \
      ( \
      AGPACK_PP_IS_BEGIN_PARENS(param), \
      AGPACK_PP_REMOVE_PARENS_DO, \
      AGPACK_PP_IDENTITY \
      ) \
    (param)() \
/**/

#define AGPACK_PP_REMOVE_PARENS_DO(param) \
  AGPACK_PP_IDENTITY(AGPACK_PP_TUPLE_ENUM(param)) \
/**/

#endif /* AGPACK_PP_VARIADICS */
#endif /* AGPACK_PREPROCESSOR_REMOVE_PARENS_HPP */
