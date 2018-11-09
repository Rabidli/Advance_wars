#ifndef CASE_TERRAIN_H
#define CASE_TERRAIN_H
#include <QGraphicsPixmapItem>
#include <QMap>


class case_terrain: public QGraphicsPixmapItem
{
private:
    int point_def;
    QMap<QString,int> point_dep;
public:
    case_terrain(QByteArray,int,int);

    void set_def(QByteArray);

    void set_dep(QByteArray);

    int get_def();

    int get_dep(QString);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CASE_TERRAIN_H
