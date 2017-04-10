all: poligono.o
	gcc cg.c poligono.o -I/usr/X11R6/include -L/usr/X11R6/lib -lGL -lGLEW -lglut -o teste 
poligono.o:
	gcc -c poligono.c -o poligono.o

clear:
	rm poligono.o
	rm teste

