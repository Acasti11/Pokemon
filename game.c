#include "game.h"
#include "clock.h"
#include "colision.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "movement.h"
#include "pokemon.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define JOKOA_SOUND "./sound/132TRANCE_02.wav"
#define JOKOA_PLAYER_IMAGE_Front "./img/sprite_bmp/3.bmp"
#define JOKOA_PLAYER_IMAGE_Front01 "./img/sprite_bmp/2.bmp"
#define JOKOA_PLAYER_IMAGE_Front02 "./img/front02.bmp"
#define JOKOA_PLAYER_IMAGE_BACK "./img/back.bmp"
#define JOKOA_PLAYER_IMAGE_BACK01 "./img/back01.bmp"
#define JOKOA_PLAYER_IMAGE_BACK02 "./img/back02.bmp"
#define JOKOA_PLAYER_IMAGE_LEFT "./img/left03.bmp"
#define JOKOA_PLAYER_IMAGE_LEFT03 "./img/left.bmp"
#define JOKOA_PLAYER_IMAGE_LEFT01 "./img/left01.bmp"
#define JOKOA_PLAYER_IMAGE_LEFT02 "./img/left02.bmp"
#define JOKOA_PLAYER_IMAGE_RIGHT "./img/right.bmp"
#define JOKOA_PLAYER_IMAGE_RIGHT01 "./img/right01.bmp"
#define JOKOA_PLAYER_IMAGE_RIGHT02 "./img/right02.bmp"
#define F_ROUTE_1 "./img/fondos_bmp/Route_1_c.bmp"
#define JOKOA_SOUND_WIN "./sound/BugleCall.wav"
#define JOKOA_SOUND_LOOSE "./sound/terminator.wav"
#define BUKAERA_SOUND_1 "./sound/128NIGHT_01.wav"
#define BUKAERA_IMAGE "./img/gameOver_1.bmp"

void sarreraMezuaIdatzi();
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
int BUKAERA_irudiaBistaratu();
JOKOA_jokalariaIrudiaSortu(MUGIMENDU *mugitua, int *noranzkoa);

void jokoaAurkeztu(void)
{
    int ebentu = 0;

    sarreraMezuaIdatzi();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
    pantailaGarbitu();
    pantailaBerriztu();
}
void sarreraMezuaIdatzi()
{
    pantailaGarbitu();
    textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);
    pantailaBerriztu();
}
EGOERA jokatu(void)
{    

    S_Jugador jugador1;
    jugador1.
    int mugitu = 0; // boolean
    EGOERA egoera = JOLASTEN;
    int ebentu = 0;
    int noranzkoa = 0;
    int mapaAukera = 0;
    JOKO_ELEMENTUA jokalaria, fondoa;
    MAPAK mapak[10];
    POSIZIOA aux;
    MUGIMENDU mugitua;
    TIME time;
    Initialize(&jokalaria, &fondoa, mapak, &mugitua, &time, mapaAukera);
    do
    {
        SDL_Delay(mugitua.velocidad);
        pantailaGarbitu();
        irudiaKendu(jokalaria.id);
        timeSprite(ebentu, &time, &mugitua);
        irudiaKendu(fondoa.id);
        arkatzKoloreaEzarri(0, 0, 0xFF);
        fondoa.id = irudiaKargatu(F_ROUTE_1);
        aux = Mugimendua(ebentu, fondoa.pos, &mugitua, mapak, mapaAukera, &fondoa, &jokalaria);
        fondoa.pos.x = aux.x;
        fondoa.pos.y = aux.y;
        jokalaria.id = JOKOA_jokalariaIrudiaSortu(&mugitua, &noranzkoa);

        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        irudiaMugitu(fondoa.id, fondoa.pos.x, fondoa.pos.y);
        irudiakMarraztu();
        pantailaBerriztu();
        ebentu = ebentuaJasoGertatuBada();
        egoera = JOKOA_egoera(jokalaria);
    } while (egoera == JOLASTEN);
    irudiaKendu(jokalaria.id);
    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();
    return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria)
{
    int ret = 0;
    return ret;
}

int JOKOA_jokalariaIrudiaSortu(MUGIMENDU *mugitua, int *noranzkoa)
{
    int Id = -1;
    char image_PATH[250] = JOKOA_PLAYER_IMAGE_Front;
    int Direction = 0, Dmax = 3;

    switch (mugitua->noranzkoa)
    {
    case 1:
        Direction = 7;  // es la direccion al numero de imagen
        *noranzkoa = 1; // solo vale para comprobar si ya esta mirando y que no vuelva a entrar y avance de sprite
        break;
    case 2:
        Direction = 10;
        *noranzkoa = 2;
        break;
    case 3:
        Direction = 4;
        *noranzkoa = 3;
        break;
    case 4:
        Direction = 1;
        *noranzkoa = 4;
        break;
    default:
        break;
    }

    if (mugitua->spritepos >= Dmax || mugitua->yes == 0)
    {
        mugitua->spritepos = 0;
    }

    mugitua->spritepos = mugitua->spritepos + Direction;
    snprintf(image_PATH, sizeof(image_PATH), ".\\img\\sprite_bmp\\%d.bmp", mugitua->spritepos);
    Id = irudiaKargatu(image_PATH);
    mugitua->spritepos = mugitua->spritepos - Direction;
    return Id;
}
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa)
{
    posizioa.y = posizioa.y + 1;
    posizioa.x = posizioa.x + 1;
    return posizioa;
}

int jokoAmaierakoa(EGOERA egoera)
{
    int ebentu = 0, id;
    int idAudioGame;

    loadTheMusic(BUKAERA_SOUND_1);
    if (egoera == IRABAZI)
    {
        idAudioGame = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame);
    }
    else
    {
        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
    }
    id = BUKAERA_irudiaBistaratu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while ((ebentu != TECLA_RETURN) && (ebentu != SAGU_BOTOIA_ESKUMA));
    audioTerminate();
    irudiaKendu(id);
    return (ebentu != TECLA_RETURN) ? 1 : 0;
}

int BUKAERA_irudiaBistaratu()
{
    int id = -1;
    id = irudiaKargatu(BUKAERA_IMAGE);
    irudiaMugitu(id, 200, 200);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return id;
}
void Initialize(JOKO_ELEMENTUA *jokalaria, JOKO_ELEMENTUA *fondoa, MAPAK *mapak, MUGIMENDU *mugitua, TIME *time,
                int mapaAukera)
{

    mapak[0].x = 16;
    mapak[0].y = 8;
    mugitua->velocidad = 30;
    mugitua->spritepos = 0;
    mapak[mapaAukera].x = 14;
    mapak[mapaAukera].y = 7;
    mapak[mapaAukera].luzeramax = 36;
    mapak[mapaAukera].altueramax = 23;
    jokalaria->pos.x = 500;
    jokalaria->pos.y = 350;
    fondoa->pos.x = 15;
    fondoa->pos.y = 225;
    jokalaria->id = 0;
    time->sprite01 = 0;
    time->sprite02 = 0;
    time->kont = 0;
    audioInit();
    initializetime();
    loadTheMusic(JOKOA_SOUND);
    playMusic();
    mugitua->noranzkoa = 2;
    jokalaria->id = irudiaKargatu(JOKOA_PLAYER_IMAGE_Front01);
    fondoa->id = irudiaKargatu(F_ROUTE_1);
    (void)matrizInitf(mapak, mapaAukera);
}