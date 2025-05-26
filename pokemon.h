#ifndef POKEMON_H
#define POKEMON_H
#include "graphics.h"
#include "imagen.h"
#include "ourTypes.h"
#include <stdio.h>
#define MAX_EVS_I 252
#define MAX_EVS_T 510
#define MAX_IVS_I 31
typedef struct s_OlO
{
    int a;
    int b;
} OlO;
typedef struct s_EST
{
    int Ps;
    int Atk;
    int Spa;
    int Def;
    int Sdef;
    int Spe;
} EST;
typedef struct s_ATAK
{
    int Id;
    char name[30];
    int Type;
    int class;
    int Power;
    OlO Precisión;
    int PP;
    int Blanco;
    int Effect2;
    int Pefec2;
} ATAK;
typedef struct s_pokemon
{
    int Id;
    int species;
    int name;
    int Lvl;
    int Ps;
    ATAK Atak[4];
    EST Est;
    EST EVS;
    EST IVS;
    int Hability;
    int Type1;
    int Type2;
    int Sex;
} POKEMON;
typedef struct s_player
{
    int me;
    int riv;
    int number00;
    int number01;
    int number02;
    char number0[250];
    char number1[250];
    char number2[250];
} PLAYER;
typedef struct s_boxfight
{
    int box[4];
    int select;
    int text;
} BOXFIGHT;
typedef struct s_combat_element
{
    int bar;
    BOXFIGHT box;
    PLAYER hp_max;
    PLAYER hp;
    PLAYER databox;
    int pokemon[2];
    int situacion;
} COMBAT_ELEMENT;
int spawnPokemon(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA fondoa);
int random(int num2, int num);
void HasieratuGrafioak(COMBAT_ELEMENT *element, POKEMON *pokemon);
int KargatuGrafikoak(COMBAT_ELEMENT *element, POKEMON *pokemon, int *atkSelection);
void kenduGrafikoak(COMBAT_ELEMENT *element, POKEMON *pokemon, int z);
void aukeratuBox(COMBAT_ELEMENT *element, POSIZIOA saguPos, int egoera, int *atkSelection);
void damageCalculator(POKEMON *pokemon1, POKEMON *pokemon2, int damage, int atak_selection);
#endif
