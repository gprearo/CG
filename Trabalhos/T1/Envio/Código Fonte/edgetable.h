#ifndef EDGETABLE_H
#define EDGETABLE_H

#include "edge.h"
#include <QPolygon>
#include <QVector>

class EdgeTable {
public:
    EdgeTable();

    void addEdge(Edge e) ;
    void addEdges(QPolygon p);
    QVector<QList<Edge>> y = QVector<QList<Edge>>() ;

    void print() ;

protected:

};

#endif // EDGETABLE_H
