


```
makefile_test: main.o way1.o way2.o
	gcc -o makefile_test main.o way1.o way2.o

main.o: main.c way1.h
	gcc -c main.c

way1.o: way1.c
	gcc -c way1.c

way2.o: way2.c
	gcc -c way2.c

clean:
	rm -f makefile_test main.o way1.o way2.o
```

As `main.c` is dependent on `way1.h`. Therefore it is added as `main.o` dependency in `line 8`

When make is executed, it will check the timestamps of the files to determine which files need to be rebuilt. If the header file way1.h is modified, then make will rebuild main.o because it depend on util.h.