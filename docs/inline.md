An inline function is a function that is expanded in line at the point of the function call instead of executing a separate function call. In other words, the inline function code is directly inserted into the calling code at compile-time, which can result in faster code execution.


syntax :

```
inline int sum(int a, int b) {
    return a + b;
}
```

When a function is declared as inline, the compiler may choose to ignore the request if it determines that the function is too complex to inline or if it believes that inlining would result in worse performance.

Using inline functions can result in faster code execution, especially when the function is called frequently and the function body is small. However, it may also result in larger binary size, as each call site will contain a copy of the inlined code.