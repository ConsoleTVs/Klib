#define __USE_MINGW_ANSI_STDIO 1

#include "string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void reallocate_if_needed(String *string, size_t capacity)
{
    if (string->capacity < capacity) {
        // Increment the size of the capacity to a multiple of STRING_BLOCK_SIZE.
        do string->capacity += STRING_BLOCK_SIZE;
        while (string->capacity < capacity);
        // Reallocate the needed space. +1 for the null termination.
        string->text = (char *) realloc(string->text, sizeof(char) * string->capacity + 1);
    } else if (string->capacity > capacity) {
        // Decrement till it fits the minimun required space.
        while (string->capacity > capacity + STRING_BLOCK_SIZE) string->capacity -= STRING_BLOCK_SIZE;
        // Reallocate the needed space. +1 for the null termination.
        string->text = (char *) realloc(string->text, sizeof(char) * string->capacity + 1);
    }
}

void string_init(String *const dest, const char *const text)
{
    // Set the length of the string.
    dest->length = strlen(text);
    // Set the capacity of the string.
    dest->capacity = 0;
    while (dest->capacity < dest->length) dest->capacity += STRING_BLOCK_SIZE;
    dest->text = (char *) malloc(sizeof(char) * dest->capacity + 1);
    // Set the text of the string.
    strcpy(dest->text, text);
}

void string_push(String *const dest, char character)
{
    // Reallocate the capacity of the string if needed.
    reallocate_if_needed(dest, ++dest->length);
    // Push the extra character and add the null termination
    dest->text[dest->length - 1] = character;
    dest->text[dest->length] = '\0';
}

char string_pop(String *const dest)
{
    // Get the char to be poped.
    char pop = dest->text[--dest->length];
    // Reallocate the capacity of the string if needed.
    reallocate_if_needed(dest, dest->length);
    // Set the null termination.
    dest->text[dest->length] = '\0';
    return pop;
}

void string_add(String *const dest, const char *const text)
{
    // Update the length of the string.
    dest->length += strlen(text);
    // Reallocate the capacity of the string if needed.
    reallocate_if_needed(dest, dest->length);
    // Append the given text to the string.
    strcat(dest->text, text);
}

void string_concat(String *const dest, const String *const src)
{
    // Update the length of the string.
    dest->length += src->length;
    // Reallocate the capacity of the string if needed.
    reallocate_if_needed(dest, dest->length);
    // Append the given text to the string.
    strcat(dest->text, src->text);
}

void string_substring(String *const dest, const size_t start, const size_t finish)
{
    // Calculate the result length of the substring.
    dest->length = finish - start + 1;
    // Allocate memory for the capacity +1 for null termination.
    char *substring = (char *) malloc(dest->length + 1);
    // Copy the string from the original to the substring.
    strncpy(substring, dest->text + start, dest->length);
    // Set the null termination.
    substring[dest->length] = '\0';
    // Reallocate the capacity of the string if needed.
    reallocate_if_needed(dest, dest->length);
    // Set the result to the string
    strcpy(dest->text, substring);
    // Delete the substring memory
    free(substring);
}

String string_new_substring(const String *const dest, const size_t start, const size_t finish)
{
    String result;
    // Allocate memory for the capacity +1 for null termination.
    char *substring = (char *) malloc(finish - start + 2);
    // Copy the string from the original to the substring.
    strncpy(substring, dest->text + start, dest->length);
    // Initiate the string.
    string_init(&result, substring);
    // Free the allocated memory.
    free(substring);
    return result;
}

void string_info(const String *const src)
{
    printf("{length: %zu, capacity: %zu}\n", src->length, src->capacity);
}

void string_print(const String *const src)
{
    printf("%s\n", src->text);
}

void string_delete(String *dest)
{
    // Remove the text from the heap.
    free(dest->text);
}
