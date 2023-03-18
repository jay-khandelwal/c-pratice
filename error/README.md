
The errno variable is a global variable that is set by various library functions in the C standard library when an error occurs. The errno variable is defined in the <errno.h> header file and is set to an error code by library functions when they encounter an error condition.


For example, if the file does not exist, the errno variable is set to ENOENT, which stands for "No such file or directory". If the user does not have permission to access the file, the errno variable is set to EACCES, which stands for "Permission denied".

It is important to check the value of the errno variable after calling library functions that can set it to ensure that the function call was successful and to determine the cause of any errors that occurred.

You are correct that the errno.h file only defines error codes as integer constants, not the corresponding error messages. However, the standard C library provides the perror() function that can be used to print a descriptive error message corresponding to an error code.

Here's an example of how to use perror() to print the error message for ENOENT (No such file or directory):

#include <stdio.h>
#include <errno.h>

int main() {
    FILE* fp = fopen("nonexistent_file.txt", "r");
    if (fp == NULL) {
        perror("Error");
    }
    return 0;
}




question: mean the corrosponding error message is define inside perror?

Like, In the case of the ENOENT error code, the error message "No such file or directory" is defined in the system's error message database, and perror() uses the strerror() function to retrieve and print this message.
"No such file or directory", which is obtained using the strerror() function with the ENOENT error code.




when an error occurs in a C program, the errno variable is set to a specific error code that identifies the type of error that occurred. The errno.h header file defines integer constants for each possible error code.

To obtain a human-readable error message corresponding to an error code, you can use the perror() function provided by the standard C library. perror() prints a custom error message, followed by the system-generated error message corresponding to the error code.

The system-generated error messages are stored in the operating system's error message database, and the strerror() function is used to convert error codes to corresponding error messages.

I hope that clears up any confusion you had regarding errno and error handling in C programs!


#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE* fp = fopen("nonexistent_file.txt", "r");
    if (fp == NULL) {
        int errnum = errno;
        fprintf(stderr, "Failed to open file: %s\n", strerror(errnum));
    }
    return 0;
}