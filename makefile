todo:main.o
	gcc main.o -o todo
	gcc -c main.c
	
	@mv main.o /tmp
	@mv todo /usr/bin/
