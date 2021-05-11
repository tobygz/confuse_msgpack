/*
 * MessagePack for C FILE* buffer adaptor
 *
 * Copyright (C) 2013 Vladimir Volodko
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_FBUFFER_H
#define AGPACK_FBUFFER_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup agpack_fbuffer FILE* buffer
 * @ingroup agpack_buffer
 * @{
 */

static inline int agpack_fbuffer_write(void* data, const char* buf, size_t len)
{
    return (1 == fwrite(buf, len, 1, (FILE *)data)) ? 0 : -1;
}

/** @} */


#ifdef __cplusplus
}
#endif

#endif /* agpack/fbuffer.h */
