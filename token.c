// token.c

#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to create a new token
token_t *create_token(token_type_t type, char *text) {
    token_t *token = (token_t *)malloc(sizeof(token_t));
    if (token != NULL) {
        token->type = type;
        token->text = strdup(text);  // Duplicate the text to ensure it's not modified externally
    }
    return token;
}

// Function to extract the next token from the input stream
token_t *get_next_token(FILE *input_stream) {
    char buffer[256];  // Assuming a maximum token length of 255 characters
    if (fscanf(input_stream, "%255s", buffer) == 1) {
        // Assuming tokens are separated by whitespace
        return create_token(WORD, buffer);  // Assume all tokens are words for now
    } else {
        return NULL;  // Return NULL if no more tokens can be extracted
    }
}

// Function to classify a token based on its text
void classify_token(token_t *token) {
    if (token == NULL || token->text == NULL) {
        // Handle invalid token or text
        return;
    }
    // Simple classification logic based on text content
    if (strcmp(token->text, "+") == 0 || strcmp(token->text, "-") == 0 ||
        strcmp(token->text, "*") == 0 || strcmp(token->text, "/") == 0) {
        token->type = OPERATOR;
    } else if (strcmp(token->text, ":") == 0 || strcmp(token->text, ";") == 0) {
        token->type = SYMBOL;
    } else {
        // If not an operator or symbol, classify as a word by default
        token->type = WORD;
    }
}
