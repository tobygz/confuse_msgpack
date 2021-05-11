# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP
# define AGPACK_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# /* AGPACK_PP_TUPLE_IS_SINGLE_RETURN */
#
# if AGPACK_PP_VARIADICS && AGPACK_PP_VARIADICS_MSVC
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/facilities/is_1.hpp>
# include <agpack/preprocessor/tuple/size.hpp>
# define AGPACK_PP_TUPLE_IS_SINGLE_RETURN(sr,nsr,tuple)	\
	AGPACK_PP_IIF(AGPACK_PP_IS_1(AGPACK_PP_TUPLE_SIZE(tuple)),sr,nsr) \
	/**/
# endif /* AGPACK_PP_VARIADICS && AGPACK_PP_VARIADICS_MSVC */
#
# endif /* AGPACK_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP */
