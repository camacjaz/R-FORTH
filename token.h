#include <stdio.h>
#include "token.h"

int main() {
    // Example input stream (replace this with your actual input source)
    FILE *input_stream = fopen("input.txt", "r");
    if (input_stream == NULL) {
        fprintf(stderr, "Error: Failed to open input file.\n");
        return 1;
    }

    // Tokenization loop
    token_t *token;
    while ((token = get_next_token(input_stream)) != NULL) {
        classify_token(token);
        // Print token type and text
        printf("Token Type: %d, Text: %s\n", token->type, token->text);
        free(token->text);  // Free dynamically allocated text
        free(token);        // Free token struct
    }

    // Close input stream
    fclose(input_stream);

    return 0;
}
