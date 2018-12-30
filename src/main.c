#include "string/string.h"
#include <stdio.h>
#include <stdlib.h>

int main()
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

    return EXIT_SUCCESS;
}
