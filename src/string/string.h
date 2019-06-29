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
} string_t;

// Initiates a new string.
void string_init(string_t *const dest, const char *const text);
// Pushes a character into the string.
void string_push(string_t *const dest, const char character);
// Pushes a character into the string.
char string_pop(string_t *const dest);
// Adds a text to the string
void string_add(string_t *const dest, const char *const text);
// Adds two strings together.
void string_concat(string_t *const dest, const string_t *const src);
// Transforms the string into a substring. start and finish
// are the indexes, both beeing inclusive.
void string_substring(string_t *const dest, const size_t start, const size_t finish);
// Creates a new string as a substring of another. start and finish
// are the indexes, both beeing inclusive.
string_t string_new_substring(const string_t *const dest, const size_t start, const size_t finish);
// Prints the string information to the string.
void string_info(const string_t *const src);
// Prints the string to the stdout.
void string_print(const string_t *const src);
// Deletes the string and the text memory from the heap.
void string_delete(string_t *const dest);

#endif
