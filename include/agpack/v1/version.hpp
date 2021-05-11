/*
 * MessagePack for C++ version information
 *
 * Copyright (C) 2008-2013 FURUHASHI Sadayuki and Takatoshi Kondo
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_VERSION_HPP
#define AGPACK_VERSION_HPP

#include "version_master.h"

#define AGPACK_STR(v) #v
#define AGPACK_VERSION_I(maj, min, rev) AGPACK_STR(maj) "." AGPACK_STR(min) "." AGPACK_STR(rev)

#define AGPACK_VERSION AGPACK_VERSION_I(AGPACK_VERSION_MAJOR, AGPACK_VERSION_MINOR, AGPACK_VERSION_REVISION)

inline const char* agpack_version(void) {
    return AGPACK_VERSION;
}

inline int agpack_version_major(void) {
    return AGPACK_VERSION_MAJOR;
}

inline int agpack_version_minor(void) {
    return AGPACK_VERSION_MINOR;
}

inline int agpack_version_revision(void) {
    return AGPACK_VERSION_REVISION;
}

#endif /* agpack/version.hpp */
