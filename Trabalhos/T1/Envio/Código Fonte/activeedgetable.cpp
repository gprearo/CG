#include "activeedgetable.h"
#include <iostream>

ActiveEdgeTable::ActiveEdgeTable(EdgeTable et)
{
    this->et = et ;
}


ActiveEdgeTable::ActiveEdgeTable(QPolygon p) {
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

    std::cout << et.y.size() << ", i: " << i << std::endl;
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
        // Retira da lista de varredura quando y = ymax
        if (currY >= e.ymax) {
            lst.removeAt(i); // Remove o item da lista
            i--; // Corrige a contagem após a remoção do item
            continue ;
        }

        e.incremento += e.numerador ;
        while (e.incremento > e.denominador) {
            e.xmin+=e.sinal ;
            e.incremento -= e.denominador ;
        }

        lst.replace(i, e);
    }

    QList<Edge> newEdges = et.y.at(currY) ;
    for (int i = 0; i < newEdges.size(); i++) {
        bool flag = 1 ;
        for (int j = 0; j < lst.size(); j++) {
            if (newEdges.at(i).xmin < lst.at(j).xmin) {
                flag = 0 ;
                lst.insert(j, newEdges.at(i));
                break ;
            }
        }
        if (flag) {
            lst.append(newEdges.at(i));
        }
    }

    return currY ;
}


QVector<int> ActiveEdgeTable::intersections() {
    QVector<int> v = QVector<int>() ;

    for (int i = 0; i < lst.size(); i++) {
            v.append(lst.at(i).xmin);
    }

    qSort(v.begin(), v.end()) ;

    return v ;
}

void ActiveEdgeTable::print() {
    et.print();
}
