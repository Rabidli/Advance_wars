#include "map.h"
#include "case_terrain.h"
#include <QFile>
#include <QtDebug>

map::map()
{
    //cree un tableau de case_terrain,initialise leur Pixmap à partir d'un fichier et les ajoute à la scene

    QFile map_text(":/terrain/map_text.txt");
    map_text.open(QFile::ReadOnly);

    case_terrain* tableau[21][17];
    QByteArray s;

    for(int j=0 ; j<17 ; j++)
    {
        for(int i=0 ; i<21; i++)
        {
            s = map_text.readLine(4);
            if (s=="\n")
                s = map_text.readLine(4);
            tableau[i][j]  = new case_terrain(s,i,j);
            addItem(tableau[i][j]);
            tableau[i][j]->setFlags(case_terrain::ItemIsSelectable);
            //tableau[i][j]->setFlags(case_terrain::ItemIsFocusable);


            /*if(tableau[i][j]->isSelected())
                tableau[i][j]->setOpacity(0.3);*/
        }
    }
    map_text.close();
    //////////////////////////////////////////////////////////////////////////////////

}


case_terrain *map::get_case(int i, int j)
{
    //retourne un pointeur case_terrain de coordonnées i,j
    if (i<22 & j<18)
       return (tableau[i][j]);
    else
        return (nullptr);

}
