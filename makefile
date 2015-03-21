

listmake : main.o file.o
	gcc -o listmake main.o file.o

main.o : main.c list.c list.h
	gcc -c main.c list.c

list.o : list.c list.h
	gcc -c list.c

clean : 
	rm -f listmake main.o file.o	
