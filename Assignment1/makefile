
all:	x

x: 	main.o LIST.o
	gcc -o x Main.o LIST.o

main.o:	main.c
	gcc -c Main.c

LIST.o:	LIST.c
	gcc -c LIST.c LIST.h

clean:	
	rm -f *.o *.s x
