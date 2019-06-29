#if defined(TYPE) && defined(NAME) && defined(BLOCK)

#define TP3(a, b, c) a ## b ## c
#define TP4(a, b, c, d) a ## b ## c ## d
#define GENERATEVEC_T(N) TP3(vector_, N, _t)
#define VEC_T GENERATEVEC_T(NAME)
#define GENFUNNAME(N, suf) TP4(vector_, N, _, suf)
#define FUNNAME(N) GENFUNNAME(NAME, N)

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

typedef struct {
    // It stores the elements text of the vector.
    TYPE *data;
    // It stores the length of the vector.
    size_t length;
    // Stores the capacity of the vector (the allocated pointer bytes of space).
    size_t capacity;
} VEC_T;

void FUNNAME(reallocate)(VEC_T *const vector, const size_t capacity)
{
    if (vector->capacity < capacity) {
        // Increment the size of the capacity to a multiple of BLOCK.
        do vector->capacity += BLOCK;
        while (vector->capacity < capacity);
        // Reallocate the needed space.
        vector->data = (TYPE *) realloc(vector->data, sizeof(TYPE) * vector->capacity);
    } else if (vector->capacity > capacity) {
        // Decrement till it fits the minimun required space.
        while (vector->capacity > capacity + BLOCK) vector->capacity -= BLOCK;
        // Reallocate the needed space.
        vector->data = (TYPE *) realloc(vector->data, sizeof(TYPE) * vector->capacity);
    }
}

// Creates a new vector.
void FUNNAME(init)(VEC_T *const dest)
{
    // Set the default data.
    dest->length = 0;
    dest->capacity = BLOCK;
    // Reserve the capacity memory.
    dest->data = (TYPE *) malloc(sizeof(TYPE) * dest->capacity);
}

// Pushes an element into the vector.
void FUNNAME(push)(VEC_T *const dest, TYPE element)
{
    // Reallocate the capacity of the vector if needed.
    FUNNAME(reallocate)(dest, ++dest->length);
    // Push the extra data to the vector
    dest->data[dest->length - 1] = element;
}
// Pops an element from the vector and returns it.
TYPE FUNNAME(pop)(VEC_T *const dest)
{
    // Get the value to pop.
    TYPE pop = dest->data[dest->length - 1];
    // Reallocate the capacity of the vector if needed.
    FUNNAME(reallocate)(dest, --dest->length);
    return pop;
}
// Prints the vector information in the stdout.
void FUNNAME(info)(const VEC_T *const src)
{
    printf("{length: %zu, capacity: %zu}\n", src->length, src->capacity);
}

// Deletes the vector's allocated data and the vector itself.
void FUNNAME(delete)(VEC_T *dest)
{
    // Free the memory used by the data storage.
    free(dest->data);
}

#undef TP3
#undef TP4
#undef GENERATEVEC_T
#undef VEC_T
#undef GENFUNNAME
#undef FUNNAME

#endif
