#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type_t;

typedef struct json_t {
    json_type_t type;
    void* value;
} json_t;

json_t* parse_json(char* json_str) {
    json_t* root = (json_t*) malloc(sizeof(json_t));
    root->type = JSON_OBJECT;
    root->value = NULL;

    // Implement your JSON parsing logic here

    return root;
}

int main() {
    char json_str[MAX_SIZE] = "{ \"name\": \"John\", \"age\": 30 }";
    json_t* root = parse_json(json_str);

    // Do something with the parsed JSON data

    return 0;
}
