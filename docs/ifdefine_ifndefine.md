

#ifdef and #ifndef are preprocessor directives in C and C++ that are used for conditional compilation. They are followed by a macro name and a block of code, which is included in the program if the macro is defined (#ifdef) or not defined (#ifndef).

#ifndef stands for "if not defined", and is the opposite of #ifdef.

It's important to note that #ifdef and #ifndef only affect the preprocessor stage of compilation, and do not affect the behavior of the compiled program at runtime.

ifdef syntax :-

```
#ifdef macro_name
  // code to be compiled if macro_name is defined
#endif
```

The #ifdef directive checks whether the macro named macro_name is defined in the program or not. If the macro is defined, the code block following the #ifdef directive is compiled; otherwise, the code block is skipped.

For example, the following code uses #ifdef to include a debug message in the program only if the DEBUG macro is defined:

```
#ifdef DEBUG
  printf("Debug message\n");
#endif
```


syntax of #ifndef is similar:

```
#ifndef macro_name
  // code to be compiled if macro_name is NOT defined
#endif

```


#ifdef and #ifndef can also be combined with #else and #elif directives to create more complex conditional compilation logic :-

```
#ifdef DEBUG
  printf("Debug message\n");
#elif defined(RELEASE)
  printf("Warning: release mode\n");
#else
  printf("Default message\n");
#endif
```