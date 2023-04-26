#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *str, const char *delim, int *num_words) {
    char **words = NULL;
    char *token;
    int i = 0;

    // Use strtok to split the string into individual words
    token = strtok(str, delim);

    while (token != NULL) {
        // Allocate memory for the next word pointer
        words = realloc(words, (i + 1) * sizeof(char *));
        if (words == NULL) {
            // If realloc fails, free all allocated memory and return NULL
            for (int j = 0; j < i; j++) {
                free(words[j]);
            }
            free(words);
            return NULL;
        }

        // Allocate memory for the word itself and copy it into the new memory
        words[i] = malloc(strlen(token) + 1);
        if (words[i] == NULL) {
            // If malloc fails, free all allocated memory and return NULL
            for (int j = 0; j < i; j++) {
                free(words[j]);
            }
            free(words);
            return NULL;
        }
        strcpy(words[i], token);

        // Move to the next word
        token = strtok(NULL, delim);
        i++;
    }

    // Set the number of words and return the array of pointers
    *num_words = i;
    return words;
}

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog";
    char **words;
    int num_words;

    words = split_string(str, " ", &num_words);

    if (words != NULL) {
        for (int i = 0; i < num_words; i++) {
            printf("%s\n", words[i]);
        }

        // Free all allocated memory
        for (int i = 0; i < num_words; i++) {
            free(words[i]);
        }
        free(words);
    } else {
        printf("Failed to split string\n");
    }

    return (0);
}
