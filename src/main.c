#include "string/string.h"
#include "vector/vector.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

static void string_test()
{
    // Create the string.
    String *string = string_create("Hello world");
    string_info(string);
    string_print(string);

    // Add another text to the string.
    string_add(string, ", this is a nice example of dynamic strings");
    string_info(string);
    string_print(string);

    // Pop the last value of the string.
    char pop = string_pop(string);
    string_info(string);
    string_print(string);

    // Push a new value at the end of the string.
    string_push(string, pop);
    string_info(string);
    string_print(string);

    // Add anothe string toghether.
    String *string2 = string_create(" yey!!!");
    string_concat(string, string2);
    string_info(string);
    string_print(string);

    // Get a substring
    string_substring(string, 13, 34);
    string_info(string);
    string_print(string);

    // Delete the string memory.
    string_delete(string);
}

static void vector_test()
{
    // Create a vector.
    Vector *vector = vector_create();
    vector_info(vector);
    vector_print(vector);

    // Add an element to the vector.
    String *string = string_create("Hello");
    vector_push(vector, string);
    vector_info(vector);
    vector_print(vector);

    // Pop an element from the vector.
    String *string_pop = vector_pop(vector);
    vector_info(vector);
    vector_print(vector);

    // Add the popped element back to the vector.
    vector_push(vector, string_pop);
    vector_info(vector);
    vector_print(vector);

    // Add an additional element to the vector.
    String *string2 = string_create("World");
    vector_push(vector, string2);
    vector_info(vector);
    vector_print(vector);

    // Delete the vector.
    string_delete(string);
}

void utils_test()
{
    const char *var1 = "World", *var2 = "World";
    red_printf(" -- %s %s --\n", var1, var2);
    size_t rows, cols;
    get_window_size(&rows, &cols);
    printf("Terminal size: %d x %d", rows, cols);
}

int main()
{
    string_test();
    vector_test();
    utils_test();

    return EXIT_SUCCESS;
}
