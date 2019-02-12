#ifndef KLIB_VECTOR_H
#define KLIB_VECTOR_H

#define VECTOR_BLOCK_SIZE 20

#include <stdint.h>
#include <stddef.h>

// This is the basic vector structure
// The methods are also documented.
typedef struct {
    // It stores the elements text of the vector.
    void **data;

    // It stores the length of the vector.
    size_t length;

    // Stores the capacity of the vector (the allocated pointer bytes of space).
    size_t capacity;
} Vector;

// Creates a new vector.
Vector *vector_create();

// Pushes an element into the vector.
void vector_push(Vector *dest, void *element);

// Pops an element from the vector and returns it.
void *vector_pop(Vector *dest);

// Prints the vector information in the stdout.
void vector_info(Vector *src);

// Print the vector to the screen.
void vector_print(Vector *src);

// Deletes the vector's allocated data and the vector itself.
void vector_delete(Vector *dest);

#endif
