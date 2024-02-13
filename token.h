#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

// Enum to represent different token types
typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD
} token_type_t;

// Struct to represent a token
typedef struct {
    token_type_t type;
    char* text;
} token_t;

// Function prototypes
token_t* get_next_token(FILE *input_stream);
void classify_token(token_t *token);

#endif // TOKEN_H
