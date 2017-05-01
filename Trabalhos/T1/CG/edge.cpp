#include "edge.h"

Edge::Edge(QPoint p1, QPoint p2) {
    if (p1.y() > p2.y()) {
        QPoint tmp = p2 ;
        p2 = p1 ;
        p1 = tmp ;
    }
//    if(p1.y() >= p2.y()) {
//        this->ymax = p1.y();
//        this->ymin = p2.y();
//    } else {
//        this->ymax = p2.y();
//        this->ymin = p1.y();
//    }

//    if(p1.x() >= p2.x()) {
//        this->xmax = p1.x();
//        this->xmin = p2.x();
//    } else {
//        this->xmax = p2.x();
//        this->xmin = p1.x();
//    }

    this->ymin = p1.y() ;
    this->xmin = p1.x() ;
    this->ymax = p2.y() ;
    this->xmax = p2.x() ;

    this->numerador = p2.x() - p1.x() ;
    this->denominador = p2.y() - p1.y() ;

    if (this->numerador < 0) {
        this->numerador *= -1 ;
        sinal = -1 ;
    } else {
        sinal = 1;
    }

    this->incremento = 0 ;
}
