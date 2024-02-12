// token.h

#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

// Define enum for token types
typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD
} token_type_t;

// Define struct for token
typedef struct {
    token_type_t type;
    char *text;
} token_t;

// Function declarations
token_t *create_token(token_type_t type, char *text);
token_t *get_next_token(FILE *input_stream);
void classify_token(token_t *token);

#endif /* TOKEN_H */
