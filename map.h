#ifndef MAP_H
#define MAP_H
#include <QGraphicsScene>
#include "case_terrain.h"



class map : public QGraphicsScene
{
private:
    Q_OBJECT
    case_terrain* tableau[21][17];
    //joueur* player1, player2 ;


public:
    explicit map();

    case_terrain* get_case(int i , int j);


signals:

public slots:

};

#endif // MAP_H
