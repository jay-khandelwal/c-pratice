


```
makefile_test: main.o way1.o way2.o
	gcc -o makefile_test main.o way1.o way2.o

main.o: main.c
	gcc -c main.c

way1.o: way1.c
	gcc -c way1.c

way2.o: way2.c
	gcc -c way2.c

clean:
	rm -f makefile_test main.o way1.o way2.o
```

In this above Makefile example, makefile_test is the target, while main.o, way1.o and way2.o are the dependencies. The first rule specifies that `makefile_test` depends on main.o, way1.o and way2.o
.
When make is executed, it checks the timestamps of the files to determine whether  main.o, way1.o and way2.o need to be built or not. If they do, it executes the rules to build them before building myprogram.

The other two rules specify that main.o depends on main.c and way1.o depends on way1.c, etc. These rules specify how to build the object files main.o and util.o from their corresponding source files main.c, way1.c and way2.c

The clean target is useful because it allows you to easily remove all generated files and start the build process from scratch.