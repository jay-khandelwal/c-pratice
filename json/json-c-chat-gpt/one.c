#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json-c-chatgpt.c"

int main() {
    const char *json = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    struct json_object *obj = parse_object(json);
    if (obj == NULL) {
        printf("Error parsing JSON object\n");
        return 1;
    }
    // printf("Name: %s\n", json_object_get_string(json_object_object_get(obj, "name")));
    // printf("Age: %d\n", json_object_get_int(json_object_object_get(obj, "age")));
    // printf("City: %s\n", json_object_get_string(json_object_object_get(obj, "city")));
    // json_object_put(obj);
    return 0;
}
