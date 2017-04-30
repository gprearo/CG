#ifndef EDGE_H
#define EDGE_H

#include <QPoint>

class Edge
{
public:
    Edge(QPoint p1, QPoint p2);

    int ymin, xmin, ymax, xmax;

    //inclinação inversa (dx/dy)
    int numerador ;
    int denominador ;

    //Será usado na hora de preencher o poligono
    int incremento ;
};

#endif // EDGE_H
