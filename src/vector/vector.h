#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Creates the final vector type.
#define vector_create_type(data_type, type_name) typedef struct { \
    data_type *data; \
    size_t length; \
    size_t capacity; \
    const size_t block; \
} type_name;

/// Creates the final vector type.
#define vector_create_final_type(data_type, type_name) typedef struct { \
    data_type *data; \
    size_t length; \
} type_name;

/// Creates the final vector.
#define vector_to_final(vector) { \
    .data = (vector)->data, \
    .length = (vector)->length \
}

/// Sets the final vector to a given variable.
#define vector_to_final_on(vector, variable) { \
    (variable)->data = (vector)->data; \
    (variable)->length = (vector)->length; \
}

/// Reallocates a vector to fit a given capacity.
#define vector_realloc(vector, capacity) { \
    if ((vector)->data == NULL && ((vector)->capacity == 0 && capacity > 0)) { \
        do (vector)->capacity += (vector)->block; \
        while ((vector)->capacity < capacity); \
        (vector)->data = malloc(sizeof(*(vector)->data) * (vector)->capacity); \
    } else if ((vector)->capacity < capacity) { \
        do (vector)->capacity += (vector)->block; \
        while ((vector)->capacity < capacity); \
        (vector)->data = realloc((vector)->data, sizeof(*(vector)->data) * (vector)->capacity); \
    } else if ((vector)->capacity > capacity) { \
        while ((vector)->capacity > capacity + (vector)->block) \
            (vector)->capacity -= (vector)->block; \
        (vector)->data = realloc((vector)->data, sizeof(*(vector)->data) * (vector)->capacity); \
    } \
}

/// Creates a new vector.
#define vector_create(block_size) { \
    .data = NULL, \
    .length = 0, \
    .capacity = 0, \
    .block = block_size \
}

/// Pushes an element into the vector.
#define vector_push(vector, element) { \
    size_t capacity = ++(vector)->length; \
    vector_realloc(vector, capacity); \
    memcpy((vector)->data + ((vector)->length - 1), &element, sizeof(element)); \
}

/// Pops an element from the vector and returns it.
#define vector_pop(vector, element) { \
    element = (vector)->data[(vector)->length - 1]; \
    size_t capacity = --(vector)->length; \
    vector_realloc(vector, capacity); \
}

/// Prints the vector information in the stdout.
#define vector_info(vector) { \
    printf("{ length: %zu, capacity: %zu, block: %zu }\n", (vector)->length, (vector)->capacity, (vector)->block); \
}

/// Deletes the vector's allocated data and the vector itself.
#define vector_delete(vector) { \
    free((vector)->data); \
}

#endif
