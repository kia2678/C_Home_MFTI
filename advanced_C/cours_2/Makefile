all: cours_2

cours_2: main.o mi_functions.o
	gcc main.o mi_functions.o -o cours_2

main.o: main.c 
	gcc -c main.c -o main.o

mi_functions.o: mi_functions.c
	gcc -c mi_functions.c -o mi_functions.o

clean:
	del -rf *.o
	del -rf cours_2.exe