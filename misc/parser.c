#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100

// Struct to hold the current token
typedef struct {
    char type[MAX_TOKEN_LENGTH];
    char value[MAX_TOKEN_LENGTH];
} Token;

// Function to tokenize the input string
Token nextToken(char *input) {
    Token token;
    int i = 0;

    // Skip whitespace
    while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
        i++;
    }

    // Handle numbers
    if (input[i] >= '0' && input[i] <= '9') {
        token.type[0] = 'n';
        token.type[1] = '\0';
        int j = 0;
        while (input[i] >= '0' && input[i] <= '9') {
            token.value[j] = input[i];
            i++;
            j++;
        }
        token.value[j] = '\0';
        return token;
    }

    // Handle strings
    if (input[i] == '"') {
        token.type[0] = 's';
        token.type[1] = '\0';
        int j = 0;
        i++;
        while (input[i] != '"') {
            token.value[j] = input[i];
            i++;
            j++;
        }
        token.value[j] = '\0';
        return token;
    }

    // Handle keywords
    if (input[i] == 't' || input[i] == 'f' || input[i] == 'n') {
        int j = 0;
        while (input[i] >= 'a' && input[i] <= 'z') {
            token.value[j] = input[i];
            i++;
            j++;
        }
        token.type[0] = 'k';
        token.type[1] = '\0';
        token.value[j] = '\0';
        return token;
    }

    // Handle punctuation
    token.type[0] = input[i];
    token.type[1] = '\0';
    token.value[0] = input[i];
    token.value[1] = '\0';
    i++;
    return token;
}

// Function to parse the input string
void parse(char *input) {
    Token token;
    do {
        token = nextToken(input);
        if (strcmp(token.type, "n") == 0) {
            printf("Number: %s\n", token.value);
        } else if (strcmp(token.type, "s") == 0) {
            printf("String: %s\n", token.value);
        } else if (strcmp(token.type, "k") == 0) {
            printf("Keyword: %s\n", token.value);
        } else {
            printf("Punctuation: %s\n", token.value);
        }
        input += strlen(token.value);
    } while (token.value[0] != '\0');
}

int main() {
    char input[] = "{ \"name\": \"John\", \"age\": 30, \"isMarried\": true, \"hobbies\": [\"reading\", \"music\", { \"type\": \"sport\", \"name\": \"football\"}]}";
    parse(input);
    return 0;
}
