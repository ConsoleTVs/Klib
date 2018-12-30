#include "string/string.h"
#include "vector/vector.h"
#include <stdio.h>
#include <stdlib.h>

static void string_test()
{
    // Create the string.
    String *string = string_create("Hello world");
    printf("[Length: %d, Capacity: %d]:\n%s\n\n", string->length, string->capacity, string->text);

    // Add another text to the string.
    string_add(string, ", this is a nice example of dynamic strings");
    printf("[Length: %d, Capacity: %d]:\n%s\n\n", string->length, string->capacity, string->text);

    // Pop the last value of the string.
    char pop = string_pop(string);
    printf("[Length: %d, Capacity: %d]:\n%s\n\n", string->length, string->capacity, string->text);

    // Push a new value at the end of the string.
    string_push(string, pop);
    printf("[Length: %d, Capacity: %d]:\n%s\n\n", string->length, string->capacity, string->text);

    // Add anothe string toghether.
    String *string2 = string_create(" yey!!!");
    string_concat(string, string2);
    printf("[Length: %d, Capacity: %d]:\n%s\n\n", string->length, string->capacity, string->text);

    // Get a substring
    string_substring(string, 13, 34);
    printf("[Length: %d, Capacity: %d]:\n%s\n\n", string->length, string->capacity, string->text);

    // Delete the string memory.
    string_delete(string);
}

static void vector_test()
{
    Vector *vector = vector_create();
    printf("[Length: %d, Capacity: %d]\n\n", vector->length, vector->capacity);

    String *string = string_create("Hello");
    vector_push(vector, string);
    printf("[Length: %d, Capacity: %d, Pushed: %s]\n\n", vector->length, vector->capacity, string->text);

    String *string_pop = vector_pop(vector);
    printf("[Length: %d, Capacity: %d, Poped: %s]\n\n", vector->length, vector->capacity, string_pop->text);

    string_delete(string);
}

int main()
{
    // string_test();
    vector_test();

    return EXIT_SUCCESS;
}
