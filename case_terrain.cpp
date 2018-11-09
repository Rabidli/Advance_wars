#include "case_terrain.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

case_terrain::case_terrain(QByteArray s,int i,int j)
{
    QPixmap p= QPixmap(":/terrain/"+s+".gif");
    setPixmap(p);
    setPos(i*16,j*16-(p.size().rheight()-16));
    set_def(s);
    set_dep(s);

}

void case_terrain::set_def(QByteArray s)
{
    if(s.toShort()==001){//plaine
        point_def=1;
    }
    else if (s.toShort()==002){//mountain
       point_def=4;
    }
    else if (s.toShort()==003){//wood
        point_def=2;
    }
    else if (004>=s.toShort() && s.toShort()<=014){//river
        point_def=0;
    }
    else if (15>=s.toShort() && s.toShort()<=27){//road
        point_def=0;
    }
    else if (29>=s.toShort() && s.toShort()<=32){//shoal
       point_def=0;
    }

    else if (s.toShort()==28){//sea
       point_def=0;
    }
    else if (s.toShort()==33){//reef
       point_def=1;
    }
    else if ((101>=s.toShort() && s.toShort()<=110)||
             (113>=s.toShort() && s.toShort()<=116)){//pipe
        point_def=0;
    }

    else {//buildings
        point_def=3;
    }
}

void case_terrain::set_dep(QByteArray s)
{

    if(s.toShort()==001){//plaine
        point_dep.insert("F",1);
        point_dep.insert("T",1);
        point_dep.insert("W",2);
        point_dep.insert("A",1);
    }
    else if (s.toShort()==002){//mountain
        point_dep.insert("F",2);
        point_dep.insert("T",-1);
        point_dep.insert("W",-1);
        point_dep.insert("A",1);
    }
    else if (s.toShort()==003){//wood
        point_dep.insert("F",1);
        point_dep.insert("T",2);
        point_dep.insert("W",3);
        point_dep.insert("A",1);
    }
    else if (s.toShort()>=004 && s.toShort()<=014){//river
        point_dep.insert("F",2);
        point_dep.insert("T",-1);
        point_dep.insert("W",-1);
        point_dep.insert("A",1);
    }
    else if (s.toShort()>=015 && s.toShort()<=027){//road
        point_dep.insert("F",1);
        point_dep.insert("T",1);
        point_dep.insert("W",2);
        point_dep.insert("A",1);
    }
    else if (s.toShort()>=29 && s.toShort()<=32){//shoal
        point_dep.insert("F",2);
        point_dep.insert("T",-1);
        point_dep.insert("W",-1);
        point_dep.insert("A",1);
    }

    else if (s.toShort()==28 || s.toShort()==33){//sea & reef
        point_dep.insert("F",-1);
        point_dep.insert("T",-1);
        point_dep.insert("W",-1);
        point_dep.insert("A",1);
    }
    else if ((s.toShort()>=101 && s.toShort()<=110)||
             (s.toShort()>=113 && s.toShort()<=116)){//pipe
        point_dep.insert("F",-1);
        point_dep.insert("T",-1);
        point_dep.insert("W",-1);
        point_dep.insert("A",-1);
    }
    else {//buildings
        point_dep.insert("F",1);
        point_dep.insert("T",1);
        point_dep.insert("W",1);
        point_dep.insert("A",1);
    }


}

int case_terrain::get_def()
{
    return point_def;

}

int case_terrain::get_dep(QString s)
{
    return  point_dep.value(s,-1);

}

void case_terrain::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::RightButton )
        this->setOpacity(0.6);
    else if (event->button() ==Qt::LeftButton) {
        qDebug()<< (this->y()+((this->pixmap().size().rheight()-16)))/16<<","<<this->x()/16;//donne i,j de l'element cliqué
    }
}
