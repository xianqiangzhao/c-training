#include <stdio.h>
#include <stdlib.h>

#define sw_atomic_cmp_set(lock, old, set) __sync_bool_compare_and_swap(lock, old, set)
#define sw_atomic_fetch_add(value, add)   __sync_fetch_and_add(value, add)
#define sw_atomic_fetch_sub(value, sub)   __sync_fetch_and_sub(value, sub)
#define sw_atomic_memory_barrier()        __sync_synchronize()
#define sw_atomic_add_fetch(value, add)   __sync_add_and_fetch(value, add)
#define sw_atomic_sub_fetch(value, sub)   __sync_sub_and_fetch(value, sub)
#ifdef __arm__
#define sw_atomic_cpu_pause()             __asm__ __volatile__ ("NOP");
#elif defined(__x86_64__)
#define sw_atomic_cpu_pause()             __asm__ __volatile__ ("pause")
#else
#define sw_atomic_cpu_pause()
#endif
#define SW_SPINLOCK_LOOP_N               1024

/*
a point test
*/
static inline unsigned long swoole_hash_php(char *key, int len)
{
    register unsigned long hash = 5381;
    /* variant with the hash unrolled eight times */
    for (; len >= 8; len -= 8)
    {
        hash = ((hash << 5) + hash) + *key++;
        hash = ((hash << 5) + hash) + *key++;
        hash = ((hash << 5) + hash) + *key++;
        hash = ((hash << 5) + hash) + *key++;
        hash = ((hash << 5) + hash) + *key++;
        hash = ((hash << 5) + hash) + *key++;
        hash = ((hash << 5) + hash) + *key++;
        hash = ((hash << 5) + hash) + *key++;
    }

    switch (len)
    {
        case 7: hash = ((hash << 5) + hash) + *key++; /* fallthrough... */
        /* no break */
        case 6: hash = ((hash << 5) + hash) + *key++; /* fallthrough... */
        /* no break */
        case 5: hash = ((hash << 5) + hash) + *key++; /* fallthrough... */
        /* no break */
        case 4: hash = ((hash << 5) + hash) + *key++; /* fallthrough... */
        /* no break */
        case 3: hash = ((hash << 5) + hash) + *key++; /* fallthrough... */
        /* no break */
        case 2: hash = ((hash << 5) + hash) + *key++; /* fallthrough... */
        /* no break */
        case 1: hash = ((hash << 5) + hash) + *key++; break;
        case 0: break;
        default: break;
    }
    return hash;
}

int main(){
  
  typedef struct
  {
      int id;
      int fd :24;
      int reactor_id :32;
  } swSession;
  swSession aa;
  printf("%d \n", aa.reactor_id);
  int lock = 2, i;
  sw_atomic_cmp_set(&lock, 0 ,8);
  printf("%d\n", lock);
  for (i = 0; i < SW_SPINLOCK_LOOP_N; i++)
  {
      sw_atomic_cpu_pause();
  }
    printf("sw_atomic_cpu_pause ok  %d \n", i);
#ifdef __arm__
   printf("__arm__  \n");
#elif defined(__x86_64__)
   printf("__x86_64__  \n");
#endif 

  printf("swoole_hash_php = %d\n" , swoole_hash_php("abcde", 5));

  return 0;

}
