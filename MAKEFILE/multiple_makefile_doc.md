
suppose you have a large project that consists of several subdirectories, each with its own set of source files and Makefile. You can create a Makefile for each subdirectory and include them in the main Makefile using the include directive:

```
SUBDIRS = subdir1 subdir2 subdir3

all:
    for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir; \
    done

clean:
    for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir clean; \
    done

include subdir1/Makefile
include subdir2/Makefile
include subdir3/Makefile
```

In this example, the all target and clean target are defined in the main Makefile to recursively call make in each of the subdirectories listed in the SUBDIRS variable.

Each subdirectory has its own Makefile, which defines the rules for building the targets in that directory. By using the include directive, the rules defined in the subdirectory Makefiles are included in the main Makefile.

Splitting the Makefile into smaller, modular Makefiles can make it easier to manage and maintain large projects. Each subdirectory can have its own Makefile that is responsible for building the targets in that directory, and the main Makefile can simply call make recursively in each subdirectory.