/*
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef AGPACK_GCC_ATOMIC_H
#define AGPACK_GCC_ATOMIC_H

#if defined(__cplusplus)
extern "C" {
#endif

typedef int _agpack_atomic_counter_t;

int _agpack_sync_decr_and_fetch(volatile _agpack_atomic_counter_t* ptr);
int _agpack_sync_incr_and_fetch(volatile _agpack_atomic_counter_t* ptr);


#if defined(__cplusplus)
}
#endif


#endif // AGPACK_GCC_ATOMIC_H
