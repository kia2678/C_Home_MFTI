all: temp_st

temp_st: main.o temp_functions.o
	gcc main.o temp_functions.o -o temp_st

main.o: main.c 
	gcc -c main.c -o main.o

temp_functions.o: temp_functions.c 
	gcc -c temp_functions.c -o temp_functions.o

clean:
	del -rf *.o
	del -rf temp_st.exe