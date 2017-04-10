#include "poligono.h"

#include <stdlib.h>

void initPoligono(poligono *p) {
	p->qnt = 0 ;
	p->inicio = NULL ;
	p->fim = NULL ;
}

void addVertice(poligono *p, int x, int y) {
	vertice *v = (vertice *) malloc(sizeof(vertice)) ;
	if (!p->inicio) {
		p->inicio = v ;
	}
	v->p = p->fim ;
	v->x = x ;
	v->y = y ;
	p->fim = v ;
	p->qnt++ ;
	
}

void clearPoligono(poligono *p) {
	vertice *v = p->inicio ;
	vertice *aux = NULL ;
	while (v) {
		aux = v ;
		v = v->p ;
		free(aux) ;
	}
	initPoligono(p) ;
}

