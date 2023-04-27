#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef __LISTS__
#define __LISTS__


typedef struct list_s{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

/* Function Prototypes */
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
#endif /* __LISTS__ */