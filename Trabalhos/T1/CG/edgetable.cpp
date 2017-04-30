#include "edgetable.h"
#include <iostream>

EdgeTable::EdgeTable()
{

}


void EdgeTable::addEdge(Edge e) {
    if (this->y.size() < e.ymax) {
        this->y.resize(e.ymax + 1);
    }

    //Insere a aresta na primeira posição da lista

    QList<Edge>  l = y.at(e.ymin) ;
    l.prepend(e);

    //Ordena a inserção
    for (int i = 0; i < l.size() - 1; i++) {
        if (l.at(i).xmin > l.at(i+1).xmin) {
            l.swap(i, i+1);
        }
    }

    y.replace(e.ymin, l);
}

void EdgeTable::addEdges(QPolygon p) {
    for (int i= 0; i < p.size() - 1; i++) {
        this->addEdge(Edge(p.at(i), p.at(i+1)));
    }

    if(p.size() > 2) {
        this->addEdge(Edge(p.at(p.size()-1), p.at(0)));
    }
}

void EdgeTable::print() {
    std::cout << "EdgeTable\n" ;
    for (int i = 0; i < this->y.size(); i++) {
        if (y.at(i).isEmpty()) {
            continue ;
        }
        std::cout << "\nLinha " << i << ":" ;
        if (!y.at(i).isEmpty()) {
            for (int j = 0; j < y.at(i).size(); j++) {
                std::cout << " ymin: " << y.at(i).at(j).ymin << "\n" ;
                std::cout << " xmin: " << y.at(i).at(j).xmin << "\n" ;
                std::cout << " ymax: " << y.at(i).at(j).ymax << "\n" ;
                std::cout << " xmax: " << y.at(i).at(j).xmax << "\n" ;
            }
        }
    }
}
