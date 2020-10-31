#ifndef __ARRAY_H__
#define __ARRAY_H__

typedef void* array_t;

// Creates an array with `sz` elements where each element's size is `type_sz`.
array_t __array_create(size_t type_sz, size_t sz);

// Creates an array of type `__type` with `__sz` elements.
#define array_create(__type, __sz) ((__type*) __array_create(sizeof(__type), __sz))

// Destroys `array`.
// Note: undefined behavior when `array` is was not created via `array_create` or `__array_create`.
void array_free(array_t array);

// Returns the size of the array.
// Note: undefined behavior when `array` is was not created via `array_create` or `__array_create`.
size_t array_size(array_t array);

#endif /* __ARRAY_H__ */
