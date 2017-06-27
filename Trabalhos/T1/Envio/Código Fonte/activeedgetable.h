#ifndef ACTIVEEDGETABLE_H
#define ACTIVEEDGETABLE_H

#include <QList>
#include "edge.h"
#include "edgetable.h"

class ActiveEdgeTable
{
public:
    ActiveEdgeTable(EdgeTable et);
    ActiveEdgeTable(QPolygon p) ;

    //Começa a preencher a estrutura com o menor y
    //Retorna o menor y
    int start() ;

    //Pula para o próximo y fazendo as alterações necessárias na estrutura
    //Retorna 0 se não há mais linhas a serem varridas
    int incY() ;

    QVector<int> intersections() ;

    void print() ;
protected:
    EdgeTable et ;
    QList<Edge> lst ;

    int currY ;
};

#endif // ACTIVEEDGETABLE_H
