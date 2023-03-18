#include <stdio.h>
#include <json-c/json.h>

int main() {
    // Open the JSON file
    FILE *fp = fopen("data.json", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Read the JSON data from the file
    char buffer[1024];
    fread(buffer, 1024, 1, fp);
    fclose(fp);
    // printf("%s\n", buffer);

    struct json_object *json;
    json = json_tokener_parse(buffer);
    
    // while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    //     json = json_tokener_parse(buffer);
    // }

    const char *json_str = json_object_to_json_string(json);
    printf("%s\n", json_str);

    // Get the array of employees
    struct json_object *employees_array;
    if (json_object_object_get_ex(json, "employees", &employees_array)) {
        // Iterate over each employee in the array
        int array_length = json_object_array_length(employees_array);
        for (int i = 0; i < array_length; i++) {
            struct json_object *employee = json_object_array_get_idx(employees_array, i);

            // Get the employee's name, age, and email
            struct json_object *name;
            struct json_object *age;
            struct json_object *email;
            json_object_object_get_ex(employee, "name", &name);
            json_object_object_get_ex(employee, "age", &age);
            json_object_object_get_ex(employee, "email", &email);

            // Print the employee's information
            printf("Employee %d:\n", i + 1);
            printf("Name: %s\n", json_object_get_string(name));
            printf("Age: %d\n", json_object_get_int(age));
            printf("Email: %s\n", json_object_get_string(email));
        }
    }

    // Free the JSON object
    json_object_put(json);

    return 0;
}
