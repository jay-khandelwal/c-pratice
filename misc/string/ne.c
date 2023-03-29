#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    START,
    DIGIT,
    DECIMAL,
    END
} State;

typedef struct {
    State state;
    char buffer[100];
    int buffer_pos;
} Tokenizer;

void init_tokenizer(Tokenizer *tokenizer) {
    tokenizer->state = START;
    tokenizer->buffer_pos = 0;
}

void process_input(Tokenizer *tokenizer, char input) {
    switch (tokenizer->state) {
        case START:
            if (isdigit(input)) {
                tokenizer->state = DIGIT;
                tokenizer->buffer[tokenizer->buffer_pos++] = input;
            }
            break;
        case DIGIT:
            if (isdigit(input)) {
                tokenizer->buffer[tokenizer->buffer_pos++] = input;
            } else if (input == '.') {
                tokenizer->state = DECIMAL;
                tokenizer->buffer[tokenizer->buffer_pos++] = input;
            } else {
                tokenizer->state = END;
            }
            break;
        case DECIMAL:
            if (isdigit(input)) {
                tokenizer->buffer[tokenizer->buffer_pos++] = input;
            } else {
                tokenizer->state = END;
            }
            break;
        case END:
            // Do nothing
            break;
    }
}

void print_token(Tokenizer *tokenizer) {
    tokenizer->buffer[tokenizer->buffer_pos] = '\0';
    printf("Found numeric value: %s\n", tokenizer->buffer);
}

int main() {
    char input[] = "{\"number\": 123.45, \"numbeer\": 123.45}";

    Tokenizer tokenizer;
    init_tokenizer(&tokenizer);

    for (int i = 0; i < strlen(input); i++) {
        process_input(&tokenizer, input[i]);

        if (tokenizer.state == END) {
            print_token(&tokenizer);
            init_tokenizer(&tokenizer);
        }
    }

    return 0;
}
