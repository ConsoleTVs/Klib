#define __USE_MINGW_ANSI_STDIO 1

#include "string/string.h"
#include "vector/vector.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

// Use generic vector
vector_create_type(string_t, string_vector_t);

static void string_test()
{
    printf("Testing string...\n");
    // Create the string.
    string_t string;
    string_init(&string, "Hello world");
    string_info(&string);
    string_print(&string);
    // Add another text to the string.
    string_add(&string, ", this is a nice example of dynamic strings");
    string_info(&string);
    string_print(&string);
    // Pop the last value of the string.
    char pop = string_pop(&string);
    string_info(&string);
    string_print(&string);
    // Push a new value at the end of the string.
    string_push(&string, pop);
    string_info(&string);
    string_print(&string);
    // Add anothe string toghether.
    string_t string2;
    string_init(&string2, " yey!!!");
    string_concat(&string, &string2);
    string_info(&string);
    string_print(&string);
    // Get a substring
    string_substring(&string, 13, 34);
    string_info(&string);
    string_print(&string);
    // Delete the string memory.
    string_delete(&string);
}

static void vector_test()
{
    printf("Testing vector...\n");
    // Create a vector.
    string_vector_t vector = vector_create(20);
    vector_info(&vector);
    // Add an element to the vector.
    string_t string;
    string_init(&string, "Hello");
    vector_push(&vector, string);
    vector_info(&vector);
    // Pop an element from the vector.
    string_t string_pop;
    vector_pop(&vector, string_pop);
    vector_info(&vector);
    printf("Popped element: "); string_print(&string_pop);
    // Add the popped element back to the vector.
    vector_push(&vector, string_pop);
    vector_info(&vector);
    // Add an additional element to the vector.
    string_t string2;
    string_init(&string2, "World");
    vector_push(&vector, string2);
    vector_info(&vector);
    // Delete the vector.
    vector_delete(&vector);
}

void utils_test()
{
    printf("Testing utils...\n");
    red_printf("Some red text\n");
    size_t rows, cols;
    get_window_size(&rows, &cols);
    printf("Terminal size: %zu  x %zu", rows, cols);
}

int main()
{
    string_test();
    vector_test();
    utils_test();

    return EXIT_SUCCESS;
}
