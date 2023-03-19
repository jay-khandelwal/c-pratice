
`static` keyword can be used with variable or function


static variable :

- When used with a variable declared at file scope (i.e., outside of any function), the static keyword gives that variable internal linkage. This means that the variable is only visible within the current source file and cannot be accessed from other files in the same program. 

- When a variable is declared as static inside a function, it becomes a local static variable. The scope of the variable is still limited to the function, but its lifetime is extended to the entire program. This means that the variable retains its value between function calls, and is available only within that file.

- static variables are initialized only once, when the program is loaded into memory. When the program is loaded into memory, the static variables are initialized with their initial values defined at compile time. If no initial value is provided, they are set to 0 by default.


static function :

- a static function is a function that can only be called from within the same file where it is defined. This means that the function is not accessible from outside the file, even if the file is included in other source files.

- If another file attempts to call this function, the compiler will generate an error.

- One advantage of using static functions is that they cannot be accidentally called from other parts of the program, which can help to prevent bugs and make the code easier to maintain. 

- Additionally, static functions can be optimized by the compiler, which can lead to improved performance.