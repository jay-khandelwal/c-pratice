


strcpy: does not guarantee safe behavior when copying strings with different lengths, while strncpy is designed to be a safer version of strcpy.
```
char *strcpy(char *dest, const char *src);
```

strncpy: copies the entire source string to the destination string, while strncpy allows you to specify the maximum number of characters to copy.
```
char *strncpy(char *dest, const char *src, size_t n); // where size_t is the size of char to copy
```
