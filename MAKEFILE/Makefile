

makefile_test: main.o way1.o way2.o way3.o
	gcc -o makefile_test main.o way1.o way2.o

main.o: main.c
	gcc -c main.c

way1.o: way1.c
	gcc -c way1.c

way2.o: way2.c
	gcc -c way2.c

clean:
	rm -f makefile_test main.o way1.o way2.o