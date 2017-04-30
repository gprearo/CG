#include "edge.h"

Edge::Edge(QPoint p1, QPoint p2)
{
    if (p1.y() > p2.y()) {
        QPoint tmp = p2 ;
        p2 = p1 ;
        p1 = tmp ;
    }

    this->ymin = p1.y() ;
    this->xmin = p1.x() ;
    this->ymax = p2.y() ;

    this->numerador = p2.x() - p1.x() ;
    this->denominador = p2.y() - p1.y() ;

    this->incremento = 0 ;
}
