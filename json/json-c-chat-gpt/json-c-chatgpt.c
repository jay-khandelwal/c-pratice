#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>

enum json_type {
    JSON_TYPE_STRING,
    JSON_TYPE_NUMBER,
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NULL
};

struct json_value {
    enum json_type type;
    union {
        char *string;
        double number;
        struct json_object *object;
        struct json_array *array;
        int boolean;
    } data;
};

struct json_object {
    struct json_pair *pairs;
    int num_pairs;
};

struct json_pair {
    char *key;
    struct json_value *value;
};

struct json_array {
    struct json_value **values;
    int num_values;
};

struct json_value *parse_value(const char *json);
struct json_object *parse_object(const char *json);
struct json_array *parse_array(const char *json);

struct json_value *parse_value(const char *json) {
    // Determine the type of the JSON value and parse accordingly
    if (json[0] == '{') {
        return (struct json_value *) parse_object(json);
    } else if (json[0] == '[') {
        return (struct json_value *) parse_array(json);
    } else if (json[0] == '"') {
        // Parse a string value
        char *end = strchr(json + 1, '"');
        if (end == NULL) {
            return NULL;
        }
        int len = end - (json + 1);
        char *string = malloc(len + 1);
        memcpy(string, json + 1, len);
        string[len] = '\0';
        struct json_value *value = malloc(sizeof(struct json_value));
        value->type = JSON_TYPE_STRING;
        value->data.string = string;
        return value;
    } else if (isdigit(json[0])) {
        // Parse a number value
        double number = strtod(json, NULL);
        struct json_value *value = malloc(sizeof(struct json_value));
        value->type = JSON_TYPE_NUMBER;
        value->data.number = number;
        return value;
    } else if (strcmp(json, "true") == 0 || strcmp(json, "false") == 0) {
        // Parse a boolean value
        struct json_value *value = malloc(sizeof(struct json_value));
        value->type = JSON_TYPE_BOOLEAN;
        value->data.boolean = (strcmp(json, "true") == 0);
        return value;
    } else if (strcmp(json, "null") == 0) {
        // Parse a null value
        struct json_value *value = malloc(sizeof(struct json_value));
        value->type = JSON_TYPE_NULL;
        value->data.string = NULL;
        return value;
    } else {
        return NULL;
    }
}

struct json_object *parse_object(const char *json) {
    // Parse a JSON object
    if (json[0] != '{' || json[strlen(json) - 1] != '}') {
        return NULL;
    }
    struct json_object *object = malloc(sizeof(struct json_object));
    object->num_pairs = 0;
    object->pairs = NULL;
    const char *ptr = json + 1;
    while (*ptr != '\0' && *ptr != '}') {
        char *key_end = strchr(ptr, ':');
        if (key_end == NULL) {
            return NULL;
        }
        int key_len = key_end - ptr;
        
        // Parse the key
        char *key = malloc((key_len + 1) * sizeof(char));
        strncpy(key, ptr, key_len);
        key[key_len] = '\0';
        ptr = key_end + 1;
        // Skip whitespace characters
        while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r') {
            ptr++;
        }
        // Parse the value
        struct json_object *value = parse_value(ptr);
        if (value == NULL) {
            free(key);
            return NULL;
        }
        // Add the key-value pair to the object
        object->num_pairs++;
        object->pairs = realloc(object->pairs, object->num_pairs * sizeof(struct json_pair));
        object->pairs[object->num_pairs - 1].key = key;
        object->pairs[object->num_pairs - 1].value = value;
        // Move the pointer to the next character after the value
        ptr = skip_value(ptr);
        // Skip whitespace characters
        while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r') {
            ptr++;
        }
        // If the next character is a comma, skip it
        if (*ptr == ',') {
            ptr++;
        }
    }
    return object;
}



struct json_array *parse_array(const char *json) {
    // Parse a JSON array
    if (json[0] != '[' || json[strlen(json) - 1] != ']') {
        return NULL;
    }
    struct json_array *array = malloc(sizeof(struct json_array));
    array->num_values = 0;
    // array->length = 0;
    array->values = NULL;
    const char *ptr = json + 1;
    while (*ptr != '\0' && *ptr != ']') {
        struct json_object *value = parse_value(ptr);
        if (value == NULL) {
            return NULL;
        }
        add_value_to_array(array, value);
        ptr = skip_value(ptr);
        if (*ptr == ',') {
            ptr++;
        }
    }
    return array;
}
