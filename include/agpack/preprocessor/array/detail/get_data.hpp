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
# ifndef AGPACK_PREPROCESSOR_ARRAY_DETAIL_GET_DATA_HPP
# define AGPACK_PREPROCESSOR_ARRAY_DETAIL_GET_DATA_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/facilities/is_1.hpp>
#
# /* AGPACK_PP_ARRAY_DETAIL_GET_DATA */
#
# define AGPACK_PP_ARRAY_DETAIL_GET_DATA_NONE(size, data)

# if AGPACK_PP_VARIADICS && !(AGPACK_PP_VARIADICS_MSVC && _MSC_VER <= 1400)
# 	 if AGPACK_PP_VARIADICS_MSVC
# 		define AGPACK_PP_ARRAY_DETAIL_GET_DATA_ANY_VC_DEFAULT(size, data) AGPACK_PP_TUPLE_REM(size) data
# 		define AGPACK_PP_ARRAY_DETAIL_GET_DATA_ANY_VC_CAT(size, data) AGPACK_PP_TUPLE_REM_CAT(size) data
# 		define AGPACK_PP_ARRAY_DETAIL_GET_DATA_ANY(size, data) \
			AGPACK_PP_IIF \
				( \
				AGPACK_PP_IS_1(size), \
				AGPACK_PP_ARRAY_DETAIL_GET_DATA_ANY_VC_CAT, \
				AGPACK_PP_ARRAY_DETAIL_GET_DATA_ANY_VC_DEFAULT \
				) \
			(size,data) \
/**/
#    else
# 		define AGPACK_PP_ARRAY_DETAIL_GET_DATA_ANY(size, data) AGPACK_PP_TUPLE_REM(size) data
#    endif
# else
# 	 define AGPACK_PP_ARRAY_DETAIL_GET_DATA_ANY(size, data) AGPACK_PP_TUPLE_REM(size) data
# endif

# define AGPACK_PP_ARRAY_DETAIL_GET_DATA(size, data) \
	AGPACK_PP_IF \
		( \
		size, \
		AGPACK_PP_ARRAY_DETAIL_GET_DATA_ANY, \
		AGPACK_PP_ARRAY_DETAIL_GET_DATA_NONE \
		) \
	(size,data) \
/**/
#
# endif /* AGPACK_PREPROCESSOR_ARRAY_DETAIL_GET_DATA_HPP */
