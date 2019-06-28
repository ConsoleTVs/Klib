#define __USE_MINGW_ANSI_STDIO 1

#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

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

void vector_init(Vector *const dest)
{
    // Set the default data.
    dest->length = 0;
    dest->capacity = VECTOR_BLOCK_SIZE;
    // Reserve the capacity memory.
    dest->data = (void **) malloc(sizeof(void *) * dest->capacity);
}

void vector_push(Vector *const dest, void *const element)
{
    // Reallocate the capacity of the vector if needed.
    reallocate_if_needed(dest, ++dest->length);
    // Push the extra data to the vector
    dest->data[dest->length - 1] = element;
}

void *vector_pop(Vector *const dest)
{
    // Get the value to pop.
    void *pop = dest->data[dest->length - 1];
    // Reallocate the capacity of the vector if needed.
    reallocate_if_needed(dest, --dest->length);
    return pop;
}

void vector_info(const Vector *const src)
{
    printf("{length: %zu, capacity: %zu}\n", src->length, src->capacity);
}

void vector_print(const Vector *const src)
{
    // Print an empty vector if length == 0.
    if (src->length == 0) {
        printf("[]\n");
        return;
    }
    // Print the initial [.
    printf("[");
    // Print the pointer a comma and a space for each item in the vector - 1.
    for (size_t i = 0; i < src->length - 1; i++) printf("0x%"PRIXPTR", ", (uintptr_t) src->data[i]);
    // Print the last item in the vector without the comma and the space.
    printf("0x%"PRIXPTR"]\n", (uintptr_t) src->data[src->length - 1]);
}

void vector_delete(Vector *dest)
{
    // Free the memory used by the data storage.
    free(dest->data);
}
