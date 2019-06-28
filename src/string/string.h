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

// Initiates a new string.
void string_init(String *const dest, const char *const text);
// Pushes a character into the string.
void string_push(String *const dest, char character);
// Pushes a character into the string.
char string_pop(String *const dest);
// Adds a text to the string
void string_add(String *const dest, const char *const text);
// Adds two strings together.
void string_concat(String *const dest, const String *const src);
// Transforms the string into a substring. start and finish
// are the indexes, both beeing inclusive.
void string_substring(String *const dest, const size_t start, const size_t finish);
// Creates a new string as a substring of another. start and finish
// are the indexes, both beeing inclusive.
String string_new_substring(const String *const dest, const size_t start, const size_t finish);
// Prints the string information to the string.
void string_info(const String *const src);
// Prints the string to the stdout.
void string_print(const String *const src);
// Deletes the string and the text memory from the heap.
void string_delete(String *dest);

#endif
