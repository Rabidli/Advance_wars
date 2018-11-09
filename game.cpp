#include "game.h"
#include "map.h"
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QDebug>
#include <QPixmap>
#include <QMouseEvent>


game::game()
{
    setFixedSize(22*16,18*16);

    // add map (scene)
    map* New_map = new map();
    setScene(New_map);

}
