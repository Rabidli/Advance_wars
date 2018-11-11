#ifndef UNITES_H
#define UNITES_H
#include <QGraphicsPixmapItem>
#include <QMap>
#include "case_terrain.h"


class Unites: public QGraphicsPixmapItem
{
private:
    int points_depl;
    int cost;
    int lifepoints;
    //QMap<QString,int> points_depl;
public:
    Unites(QByteArray,int, int);

    void set_dep(QByteArray);

    void set_cost(QByteArray);

    int get_dep();

    int get_cost();

    int get_lifepoints();

    int move(Unites &unite, int dep);

    void wait();

    bool attack(Unites &attaquant, Unites &cible, case_terrain &terrain);

    int getdamage(Unites &attaquant, Unites &cible, case_terrain &terrain);

    void capture();

    void fusion();
};

#endif // UNITES_H
