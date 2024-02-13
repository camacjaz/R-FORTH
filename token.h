#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

// Enum to represent different token types
typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    END_OF_FILE // Define END_OF_FILE token type
} token_type_t;

// Struct to represent a token
typedef struct {
    token_type_t type;
    char* text;
} token_t;

// Function prototypes
token_t* get_next_token(char **input);
void classify_token(token_t *token);

// Function to convert token type to string
const char *token_type_to_string(enum token_type_t type);

#endif // TOKEN_H

