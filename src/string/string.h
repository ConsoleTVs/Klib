#ifndef KLIB_STRING_H
#define KLIB_STRING_H

#define STRING_BLOCK_SIZE 20

#include <stdint.h>
#include <stddef.h>

// This is the basic string structure
// The methods are also documented.
typedef struct {
    // It stores the basic text of the string.
    char *text;

    // It stores the length of the string.
    size_t length;

    // Stores the capacity of the string (the allocated char bytes of space).
    size_t capacity;
} String;

// Creates a new string given a text.
String *string_create(char *text);

// Pushes a character into the string.
void string_push(String *dest, char character);

// Pushes a character into the string.
char string_pop(String *dest);

// Adds a text to the string
void string_add(String *dest, char *text);

// Adds two strings together.
void string_concat(String *dest, String *src);

// Transforms the string into a substring. start and finish
// are the indexes, both beeing inclusive.
void string_substring(String *dest, size_t start, size_t finish);

// Prints the string information to the string.
void string_info(String *src);

// Prints the string to the stdout.
void string_print(String *src);

// Deletes the string and the text memory from the heap.
void string_delete(String *dest);

#endif
