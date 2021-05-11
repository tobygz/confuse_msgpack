/*
 * MessagePack for C version information
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_VERSION_H
#define AGPACK_VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

AGPACK_DLLEXPORT
const char* agpack_version(void);
AGPACK_DLLEXPORT
int agpack_version_major(void);
AGPACK_DLLEXPORT
int agpack_version_minor(void);
AGPACK_DLLEXPORT
int agpack_version_revision(void);

#include "version_master.h"

#define AGPACK_STR(v) #v
#define AGPACK_VERSION_I(maj, min, rev) AGPACK_STR(maj) "." AGPACK_STR(min) "." AGPACK_STR(rev)

#define AGPACK_VERSION AGPACK_VERSION_I(AGPACK_VERSION_MAJOR, AGPACK_VERSION_MINOR, AGPACK_VERSION_REVISION)

#ifdef __cplusplus
}
#endif

#endif /* agpack/version.h */


