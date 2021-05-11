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
# ifndef AGPACK_PREPROCESSOR_DETAIL_CHECK_HPP
# define AGPACK_PREPROCESSOR_DETAIL_CHECK_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_CHECK */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_CHECK(x, type) AGPACK_PP_CHECK_D(x, type)
# else
#    define AGPACK_PP_CHECK(x, type) AGPACK_PP_CHECK_OO((x, type))
#    define AGPACK_PP_CHECK_OO(par) AGPACK_PP_CHECK_D ## par
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC() && ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_DMC()
#    define AGPACK_PP_CHECK_D(x, type) AGPACK_PP_CHECK_1(AGPACK_PP_CAT(AGPACK_PP_CHECK_RESULT_, type x))
#    define AGPACK_PP_CHECK_1(chk) AGPACK_PP_CHECK_2(chk)
#    define AGPACK_PP_CHECK_2(res, _) res
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_CHECK_D(x, type) AGPACK_PP_CHECK_1(type x)
#    define AGPACK_PP_CHECK_1(chk) AGPACK_PP_CHECK_2(chk)
#    define AGPACK_PP_CHECK_2(chk) AGPACK_PP_CHECK_3((AGPACK_PP_CHECK_RESULT_ ## chk))
#    define AGPACK_PP_CHECK_3(im) AGPACK_PP_CHECK_5(AGPACK_PP_CHECK_4 im)
#    define AGPACK_PP_CHECK_4(res, _) res
#    define AGPACK_PP_CHECK_5(res) res
# else /* DMC */
#    define AGPACK_PP_CHECK_D(x, type) AGPACK_PP_CHECK_OO((type x))
#    define AGPACK_PP_CHECK_OO(par) AGPACK_PP_CHECK_0 ## par
#    define AGPACK_PP_CHECK_0(chk) AGPACK_PP_CHECK_1(AGPACK_PP_CAT(AGPACK_PP_CHECK_RESULT_, chk))
#    define AGPACK_PP_CHECK_1(chk) AGPACK_PP_CHECK_2(chk)
#    define AGPACK_PP_CHECK_2(res, _) res
# endif
#
# define AGPACK_PP_CHECK_RESULT_1 1, AGPACK_PP_NIL
#
# endif
