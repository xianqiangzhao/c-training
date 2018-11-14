 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
#include <string.h>

typedef unsigned long  uint64_t;
#ifndef RAND_MAX
#define RAND_MAX   2147483647
#endif

static char characters[] =
{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
        'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
        't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', };

void swoole_random_string(char *buf, size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        int r = swoole_rand(0, sizeof(characters) - 1);
       
        buf[i] = characters[r];
    }
    buf[i] = '\0';
}


uint64_t swoole_hash_key(char *str, int str_len)
{
    uint64_t hash = 5381;
    int c, i = 0;
    for (c = *str++; i < str_len; i++)
    {
        hash = (*((hash * 33) + str)) & 0x7fffffff;
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

void swoole_dump_ascii(char *data, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", (unsigned) data[i]);
    }
    printf("\n");
}

int swoole_rand(int min, int max)
{
    static int _seed = 0;
    if (_seed == 0)
    {
        _seed = time(NULL);
        srand(_seed);
    }

    int _rand = rand();

    _rand = min + (int) ((double) ((double) (max) - (min) + 1.0) * ((_rand) / ((RAND_MAX) + 1.0)));
    return _rand;
}

int main(int argc, char const *argv[])
{
    char random_string [100];
    swoole_random_string(random_string, 100);
    random_string[10] = 0;
    printf("%s\n", random_string);
    mkstemp(random_string);
    while(1) {}


    return 0;
}