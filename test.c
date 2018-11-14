#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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


char* swoole_string_format(size_t n, const char *format, ...)
{
    char *buf = malloc(n);
    if (buf == NULL)
    {
        return NULL;
    }

    va_list _va_list;
    va_start(_va_list, format);

    if (vsnprintf(buf, n, format, _va_list) < 0)
    {
        free(buf);
        return NULL;
    }

    return buf;
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

  //add by 2018/08/16
  char *mp = malloc(sizeof(char) * 10);
  free(mp);
  char *mp1 = malloc(sizeof(char) * 10);  
  free(mp1);
  int a = 10%5;
  printf("a= %d\n", a);

  typedef struct test
  {
    char *p;
    int *count;
    
  } st;
  st *sp = malloc(sizeof(st));
free(sp);

int modini = 0;
for (; modini <= SW_SPINLOCK_LOOP_N*2; ++modini)
{
 // printf("%d / %d = %d \n" , modini, SW_SPINLOCK_LOOP_N, modini%SW_SPINLOCK_LOOP_N);
}


printf("%s\n", swoole_string_format(60,"zxqis%s and %s","supperman", "good"));


  return 0;

}
