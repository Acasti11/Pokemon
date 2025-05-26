#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "colision.h"
#include "ourTypes.h"
#include "pokemon.h"
#include <stdio.h>
typedef struct S_Jugador
{
  int dinero;
  int propiedades[50];
}S_Jugador ;


typedef struct S_MUGIMENDUA
{
    int noranzkoa;
    int spritepos;
    int velocidad;
    int yes;
} MUGIMENDU;

typedef struct s_MAPA_METRIKAK
{
    int mapa[23][35];
    int altueramax;
    int luzeramax;

} MAPA_METRIKAK;

typedef struct s_MAPAK
{
    MAPA_METRIKAK;
    int x;
    int y;
} MAPAK;
typedef struct s_time
{
    int sprite01;
    int sprite02;
    int general;
    int kont;
} TIME;
void timeSprite(int ebentu, TIME *time, MUGIMENDU *mugitua);
POSIZIOA Mugimendua(int ebentu, POSIZIOA pos, MUGIMENDU *mugitu, MAPAK *mapak, int mapaAukera, JOKO_ELEMENTUA *fondoa,
                    JOKO_ELEMENTUA *jokalaria);
int matrizInitf(MAPAK *mapak, int mapaAukera);
void matrizeaInit(MAPAK *mapak, int mapaAukera);
#endif