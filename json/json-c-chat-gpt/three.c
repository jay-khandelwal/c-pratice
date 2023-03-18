#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_BUF_SIZE 1024

int main() {
    // Define a sample JSON string
    const char* json_str = "{ \"name\": \"John\", \"age\": 30, \"isStudent\": false }";

    // Create a buffer to hold the JSON data
    char json_buf[JSON_BUF_SIZE];
    strncpy(json_buf, json_str, JSON_BUF_SIZE);

    // Find the value of the "name" key
    char* name_pos = strstr(json_buf, "\"name\":");
    printf("%s \n", name_pos);
    if (name_pos != NULL) {
        char* name_start = strchr(name_pos, '\"') + 1;
        char* name_end = strchr(name_start, '\"');
        printf("%s \n", name_start);
        printf("%s \n", name_end);
        char name[name_end - name_start + 1];
        strncpy(name, name_start, name_end - name_start);
        name[name_end - name_start] = '\0';
        printf("Name: %s\n", name);
    }

    // Find the value of the "age" key
    char* age_pos = strstr(json_buf, "\"age\":");
    if (age_pos != NULL) {
        char* age_start = strchr(age_pos, ':') + 1;
        char* age_end = age_start;
        while (*age_end >= '0' && *age_end <= '9') {
            age_end++;
        }
        char age[age_end - age_start + 1];
        strncpy(age, age_start, age_end - age_start);
        age[age_end - age_start] = '\0';
        printf("Age: %s\n", age);
    }

    // Find the value of the "isStudent" key
    char* is_student_pos = strstr(json_buf, "\"isStudent\":");
    if (is_student_pos != NULL) {
        char* is_student_start = strchr(is_student_pos, ':') + 1;
        char* is_student_end = is_student_start;
        while (*is_student_end == ' ' || *is_student_end == '\t' || *is_student_end == '\n') {
            is_student_end++;
        }
        int is_student = (*is_student_end == 't' || *is_student_end == 'T');
        printf("Is Student: %s\n", is_student ? "true" : "false");
    }

    return 0;
}
