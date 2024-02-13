// main.c

#include <stdio.h>
#include "token.h"

int main() {
    // Test creating and printing tokens
    token_t* num_token = create_token(NUMBER, "123");
    token_t* op_token = create_token(OPERATOR, "+");
    token_t* sym_token = create_token(SYMBOL, ";");
    token_t* word_token = create_token(WORD, "HELLO");

    printf("Number Token: %s\n", num_token->text);
    printf("Operator Token: %s\n", op_token->text);
    printf("Symbol Token: %s\n", sym_token->text);
    printf("Word Token: %s\n", word_token->text);

    // Free memory allocated for tokens
    free_token(num_token);
    free_token(op_token);
    free_token(sym_token);
    free_token(word_token);

    return 0;
}
