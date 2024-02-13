#include <stdio.h>
#include "token.h"

int main() {
    // Test creating and printing tokens

    // Create a token representing a number (123)
    token_t* num_token = create_token(NUMBER, "123");

    // Create a token representing an operator (+)
    token_t* op_token = create_token(OPERATOR, "+");

    // Create a token representing a symbol (;)
    token_t* sym_token = create_token(SYMBOL, ";");

    // Create a token representing a word ("HELLO")
    token_t* word_token = create_token(WORD, "HELLO");

    // Print the text of each token along with its type

    // Print the text of the number token
    printf("Number Token: %s\n", num_token->text);

    // Print the text of the operator token
    printf("Operator Token: %s\n", op_token->text);

    // Print the text of the symbol token
    printf("Symbol Token: %s\n", sym_token->text);

    // Print the text of the word token
    printf("Word Token: %s\n", word_token->text);

    // Free memory allocated for each token

    // Free memory allocated for the number token
    free_token(num_token);

    // Free memory allocated for the operator token
    free_token(op_token);

    // Free memory allocated for the symbol token
    free_token(sym_token);

    // Free memory allocated for the word token
    free_token(word_token);

    // Indicate successful execution by returning 0
    return 0;
}
