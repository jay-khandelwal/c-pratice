

The patsubst function in a Makefile is used to substitute one set of patterns in a list of strings with another set of patterns. It can be useful for transforming a list of source file names into a corresponding list of object file names, for example.

Here's an example of how you can use the patsubst function in a Makefile:

```
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
```

In this example, the patsubst function is used to transform the list of source file names in the SOURCES variable into a corresponding list of object file names in the OBJDIR directory. The $(SRCDIR)/%.c pattern matches all source file names in the $(SRCDIR) directory with the .c extension, and the $(OBJDIR)/%.o pattern substitutes the .c extension with the .o extension and prefixes the resulting file name with the $(OBJDIR) directory.

like if `SOURCES` contains [hello.c main.c] then this patsubst will convert it to [hello.o main.o] etc..


The patsubst function takes two arguments: a pattern to match against each string in a list, and a replacement pattern to substitute in each matching string. The pattern and replacement pattern can include % characters to represent variable parts of the strings. The patsubst function returns a list of transformed strings, with each transformed string separated by spaces.