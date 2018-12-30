#include "vector.h"
#include <stdlib.h>

static void reallocate_if_needed(Vector *vector, size_t capacity)
{
    if (vector->capacity < capacity) {
        // Increment the size of the capacity to a multiple of VECTOR_BLOCK_SIZE.
        do vector->capacity += VECTOR_BLOCK_SIZE;
        while (vector->capacity < capacity);
        // Reallocate the needed space.
        vector->data = (void **) realloc(vector->data, sizeof(void *) * vector->capacity);
    } else if (vector->capacity > capacity) {
        // Decrement till it fits the minimun required space.
        while (vector->capacity > capacity + VECTOR_BLOCK_SIZE) vector->capacity -= VECTOR_BLOCK_SIZE;
        // Reallocate the needed space.
        vector->data = (void **) realloc(vector->data, sizeof(void *) * vector->capacity);
    }
}

Vector *vector_create()
{
    // Allocate memory for the string.
    Vector *vector = (Vector *) malloc(sizeof(Vector));

    // Set the default data.
    vector->length = 0;
    vector->capacity = VECTOR_BLOCK_SIZE;

    // Reserve the capacity memory.
    vector->data = (void **) malloc(sizeof(void *) * vector->capacity);

    return vector;
}

void vector_push(Vector *dest, void *element)
{
    // Reallocate the capacity of the string if needed.
    reallocate_if_needed(dest, ++dest->length);

    // Push the extra character
    dest->data[dest->length - 1] = element;
}

void *vector_pop(Vector *dest)
{
    // Get the value to pop.
    void *pop = dest->data[dest->length - 1];

    // Reallocate the capacity of the string if needed.
    reallocate_if_needed(dest, --dest->length);

    return pop;
}

void vector_delete(Vector *dest)
{
    // Free the memory used by the data storage.
    free(dest->data);

    // Free the vector memory.
    free(dest);
}
