
typedef struct Vertice {
	int x;
	int y;
	struct Vertice *p ;
} vertice ;

typedef struct {
	vertice *inicio ;
	vertice *fim ;
	int qnt ;
} poligono ;


void initPoligono(poligono *p) ;

void addVertice(poligono *p, int x, int y) ;

void clearPoligono(poligono *p) ;

void initPoligono(poligono *p) ;

void clearPoligono(poligono *p) ;
