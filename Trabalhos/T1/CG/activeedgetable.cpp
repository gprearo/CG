#include "activeedgetable.h"

ActiveEdgeTable::ActiveEdgeTable(EdgeTable et)
{
    this->et = et ;
}


ActiveEdgeTable::ActiveEdgeTable(QPolygon p)
{
    this->et = EdgeTable() ;
    this->et.addEdges(p);
}

int ActiveEdgeTable::start() {
    int i ;
    for (i = 0; i < et.y.size(); i++) {
        if (!et.y.at(i).isEmpty()) {
            break ;
        }
    }

    currY = i ;

    lst = et.y.at(i) ;

    return currY ;
}

int ActiveEdgeTable::incY() {
    currY++ ;

    if (currY >= et.y.size()) {
        return 0 ;
    }

    for (int i = 0; i < lst.size(); i++) {
        Edge e = lst.at(i) ;
        if (currY > e.ymax) {
            lst.removeAt(i);
            continue ;
        }

        e.incremento += e.numerador ;
        while (e.incremento > e.denominador) {
            e.xmin++ ;
            e.incremento -= e.denominador ;
        }

        lst.replace(i, e);
    }

    return 1 ;
}


QVector<int> ActiveEdgeTable::intersections() {
    QVector<int> v = QVector<int>() ;

    for (int i = 0; i < lst.size(); i++) {
        v.append(lst.at(i).xmin);
    }

    return v ;
}

void ActiveEdgeTable::print() {
    et.print();
}