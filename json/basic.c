// #include <stdio.h>
// #include <json-c/json.h>

// int main() {
//     char *json_string = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
//     struct json_object *json = json_tokener_parse(json_string);
//     if (json != NULL) {
//         struct json_object *name, *age, *city;
//         if (json_object_object_get_ex(json, "name", &name) && json_object_object_get_ex(json, "age", &age) && json_object_object_get_ex(json, "city", &city)) {
//             printf("Name: %s\n", json_object_get_string(name));
//             printf("Age: %d\n", json_object_get_int(age));
//             printf("City: %s\n", json_object_get_string(city));
//         }
//         json_object_put(json);
//     }
//     return 0;
// }


#include <stdio.h>
#include <json-c/json.h>

int main() {
    json_object *jobj = json_object_new_object();
    json_object_object_add(jobj, "key", json_object_new_string("value"));
    printf("%s\n", json_object_to_json_string(jobj));
    json_object_put(jobj);
    return 0;
}
