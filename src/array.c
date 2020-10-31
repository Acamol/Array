#include <stdio.h>      // fprintf
#include <stdlib.h>     // malloc, free
#include "array.h"

struct array_metadata {
    size_t sz;
    size_t type_sz;
    void* magic;
};

static inline void assert_array_is_array_t(struct array_metadata* md, const char* caller)
{
    if (md->magic != md) {
        fprintf(stderr, "\npanic: (%p) is not an array_t in function '%s'.\n", (void*)(md + 1), caller);
        exit(1);
    }
}

array_t __array_create(size_t type_sz, size_t sz)
{
    struct array_metadata* ar = malloc(sizeof(struct array_metadata) +  sz * type_sz);
    ar->sz = sz;
    ar->type_sz = type_sz;
    ar->magic = ar;
    return (array_t)(ar + 1);
}

size_t array_size(array_t array)
{
    struct array_metadata* md = ((struct array_metadata*) array) - 1;
    assert_array_is_array_t(md, __func__);

    return md->sz;
}

void array_free(array_t array)
{
    struct array_metadata* md = ((struct array_metadata*) array) - 1;
    assert_array_is_array_t(md, __func__);

    free(md);
}
