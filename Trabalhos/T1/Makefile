all: poligono.o
	gcc cg.c poligono.o -I/usr/X11R6/include -L/usr/X11R6/lib -lGL -lGLEW -lglut `pkg-config --cflags --libs gtk+-3.0`
poligono.o:
	gcc -c poligono.c -o poligono.o

clear:
	rm poligono.o
	rm teste

