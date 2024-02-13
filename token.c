#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

// Function to get the next token from the input stream
token_t* get_next_token(char **input) {
    // Split tokens on whitespace
    char *token_str = strtok(*input, " \t\n");

    // Move input pointer forward
    *input += strlen(token_str) + 1;

    // Consider the end of the string/token
    if (token_str == NULL) {
        // Handle the end of the string/token with grace and create a token for its conclusion
        token_t* end_token = (token_t*)malloc(sizeof(token_t));
        if (end_token == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for end of file token.\n");
            exit(EXIT_FAILURE);
        }
        end_token->type = END_OF_FILE;
        end_token->text = NULL;
        return end_token;
    }

    // Create token
    token_t* token = (token_t*)malloc(sizeof(token_t));
    if (token == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for token.\n");
        exit(EXIT_FAILURE);
    }

    // Determine token type based on its text
    if (isdigit(token_str[0])) {
        token->type = NUMBER;
    } else if (strcmp(token_str, "+") == 0 || strcmp(token_str, "-") == 0 ||
               strcmp(token_str, "*") == 0 || strcmp(token_str, "/") == 0) {
        token->type = OPERATOR;
    } else if (strcmp(token_str, ";") == 0 || strcmp(token_str, ":") == 0) {
        token->type = SYMBOL;
    } else {
        token->type = WORD;
    }

    // Duplicate token text
    token->text = strdup(token_str);
    if (token->text == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for token text.\n");
        free(token);  // Free token memory
        exit(EXIT_FAILURE);
    }

    return token;
}

// Function to convert token type to string
const char *token_type_to_string(enum token_type_t type) {
    switch (type) {
        case NUMBER:
            return "Number";
        case OPERATOR:
            return "Operator";
        case SYMBOL:
            return "Symbol";
        case WORD:
            return "Word";
        case END_OF_FILE:
            return "EndOfFile";
        default:
            return "Unknown";
    }
}
