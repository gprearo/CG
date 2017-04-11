
//Struct de um vértice em 2D
//Com coordenadas x e y e um ponteiro para o
//próximo vertice da lista
typedef struct Vertice {
	int x;
	int y;
	struct Vertice *p ;
} vertice ;


//Struct de lista de vértices para a formação
//de um polígono
typedef struct {
	vertice *inicio ;
	vertice *fim ;
	int qnt ;
} poligono ;

//Inicializa a estrutura do polígono
void initPoligono(poligono *p) ;

//Adiciona um vétice no final da lista
void addVertice(poligono *p, int x, int y) ;

//Libera a memória alocada pelo polígono
void clearPoligono(poligono *p) ;

