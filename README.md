# Introduction
Implementation of array data-structure which is compatible with C array operations, but one which also "knows" its size.

## Motivation
When you pass a C array to a function, you usually have to pass its size as well.
It would be nice to be able to write:
```C
void foo(int* array)
{
    for (size_t i = 0; i < array_size(array); ++i) {
        ...
    }
}
```
Instead of writing a code like this:
```C
void foo(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        ...
    }
}
```

It is also helpful when you need to iterate over an array. Yes, if it is a C array you can determine its size on runtime with `sizeof(array) / sizeof(*array)`. But this information is lost when you use the array via a pointer (which is what happens when it is passed as argument to a function).

This does not solve the issue for multi-dimensional arrays. But the size of a multi-dimensional array is hardly ever helpful anyway. You would need the size of each dimension.
A more robust API can solve this issue as well, but I'm not going to do it :smiley: (at least for now).

## Example
```C
int* a = array_create(/*element type =*/ int, /*size =*/ 5);
for (int i = 0; i < array_size(a); ++i) {
    a[i] = i;
}

array_free(a);
```
For more usage examples, see `array_test.c`.

## Run the Tests
Provided you have gcc and make installed, just type `make test` to run the tests.

## License
MIT