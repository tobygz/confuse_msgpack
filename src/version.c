#include "agpack.h"

#ifndef AGPACK_VERSION
#define AGPACK_VERSION 0
#endif

#ifndef AGPACK_VERSION_MAJOR
#define AGPACK_VERSION_MAJOR 0
#endif

#ifndef AGPACK_VERSION_MINOR
#define AGPACK_VERSION_MINOR 0
#endif

#ifndef AGPACK_VERSION_REVISION
#define AGPACK_VERSION_REVISION 0
#endif

const char* agpack_version(void)
{
    return AGPACK_VERSION;
}

int agpack_version_major(void)
{
    return AGPACK_VERSION_MAJOR;
}

int agpack_version_minor(void)
{
    return AGPACK_VERSION_MINOR;
}

int agpack_version_revision(void)
{
    return AGPACK_VERSION_REVISION;
}

