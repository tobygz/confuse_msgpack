#include "include/agpack.h"
#include <stdio.h>

int main(void)
{
    /* agpack::sbuffer is a simple buffer implementation. */
    agpack_sbuffer sbuf;
    agpack_sbuffer_init(&sbuf);

    /* serialize values into the buffer using agpack_sbuffer_write callback function. */
    agpack_packer pk;
    agpack_packer_init(&pk, &sbuf, agpack_sbuffer_write);

    agpack_pack_array(&pk, 3);
    agpack_pack_int(&pk, 1);
    agpack_pack_true(&pk);
    agpack_pack_str(&pk, 7);
    agpack_pack_str_body(&pk, "example", 7);

    /* deserialize the buffer into agpack_object instance. */
    /* deserialized object is valid during the agpack_zone instance alive. */
    agpack_zone mempool;
    agpack_zone_init(&mempool, 2048);

    agpack_object deserialized;
    agpack_unpack(sbuf.data, sbuf.size, NULL, &mempool, &deserialized);

    /* print the deserialized object. */
    agpack_object_print(stdout, deserialized);
    puts("");

    agpack_zone_destroy(&mempool);
    agpack_sbuffer_destroy(&sbuf);

    return 0;
}
