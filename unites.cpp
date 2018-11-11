#include "unites.h"
#include <QDebug>
#include<QGraphicsSceneMouseEvent>
#include "case_terrain.h"

Unites::Unites(QByteArray s, int i, int j)
{
    QPixmap p = QPixmap(":/unites/"+s+".gif");
    setPixmap(p);
    setPos(i*16,j*16-(p.size().rheight()-16));
    set_dep(s);
    set_cost(s);

}

void Unites::set_dep(QByteArray s)
{
    if(s.toShort()==1){//anti-air
        points_depl=6;
    }
    else if(s.toShort()==2){//b-copter
        points_depl=6;
    }
    else if(s.toShort()==3){//bazooka
        points_depl=2;
    }
    else if(s.toShort()==4){//bomber
        points_depl=7;
    }
    else if(s.toShort()==5){//fighter
        points_depl=9;
    }
    else if(s.toShort()==6){//infantry
        points_depl=3;
    }
    else if(s.toShort()==7){//md_tank
        points_depl=5;
    }
    else if(s.toShort()==8){//megatank
        points_depl=4;
    }
    else if(s.toShort()==9){//neotank
        points_depl=6;
    }
    else if(s.toShort()==10){//recon
        points_depl=8;
    }
    else if(s.toShort()==11){//tank
        points_depl=6;
    }
}


void Unites::set_cost(QByteArray s)
{
    if(s.toShort()==1){//anti-air
        cost=8000;
    }
    else if(s.toShort()==2){//b-copter
        cost=9000;
    }
    else if(s.toShort()==3){//bazooka
        cost=3000;
    }
    else if(s.toShort()==4){//bomber
        cost=22000;
    }
    else if(s.toShort()==5){//fighter
        cost=20000;
    }
    else if(s.toShort()==6){//infantry
        cost=1000;
    }
    else if(s.toShort()==7){//md_tank
        cost=16000;
    }
    else if(s.toShort()==8){//megatank
        cost=28000;
    }
    else if(s.toShort()==9){//neotank
        cost=22000;
    }
    else if(s.toShort()==10){//recon
        cost=4000;
    }
    else if(s.toShort()==11){//tank
        cost=7000;
    }
}



int Unites::get_dep()
{
    return points_depl;
}


int Unites::get_cost()
{
    return cost;
}

int Unites::get_lifepoints()
{
    return lifepoints;
}

int Unites::move(Unites &unite, int dep)
{
    points_depl = unite.get_dep() - dep ;

    return points_depl;
}


void Unites::wait(){ }


bool Unites::attack(Unites &attaquant, Unites &cible, case_terrain &terrain)
{
    int lp = cible.get_lifepoints();

    lifepoints = lp - cible.getdamage(attaquant, cible, terrain);

    if (lifepoints<=0){
        return false;
    }
    else
        return true;
}



int Unites::getdamage(Unites &attaquant, Unites &cible, case_terrain &terrain)
{

    int B ;//Matrice damage chart
    int D_TR = terrain.get_def();
    int ALifepoints = attaquant.get_lifepoints();
    int DLifepoints = cible.get_lifepoints();
    int damage;

    damage = B * ALifepoints/10*(100 - D_TR * DLifepoints)/100;
    return damage;
}



void Unites::capture()
{

}

void Unites::fusion()
{

}

