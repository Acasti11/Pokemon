#define _CRT_SECURE_NO_WARNINGS
#include "movement.h"
#include "colision.h"

POSIZIOA Mugimendua(int ebentu, POSIZIOA pos, MUGIMENDU *mugitu, MAPAK *mapak, int mapaAukera, JOKO_ELEMENTUA *fondoa,
                    JOKO_ELEMENTUA *jokalaria)
{
    int distantzia = 40;
    int x, y, x1, y1;
    x = mapak[mapaAukera].x;
    y = mapak[mapaAukera].y;
    x1 = pos.x;
    y1 = pos.y;
    switch (ebentu) // detecta latecla que pulsas
    {
    case TECLA_LEFT:
        if (mugitu->noranzkoa == 1)
        {
            pos.x = pos.x + distantzia; // cambia las cordenadas dependiendo la tecla
            mugitu->noranzkoa = 1;      // hacia dnd mira
            mugitu->spritepos++;        // maneja los pies
            mugitu->yes = 1;
            mapak[mapaAukera].x--; // esto cambia las casillas de la matriz en x
        }
        else
        {
            mugitu->yes = 0;
            mugitu->noranzkoa = 1; // cambia hacia donde miras
            mugitu->spritepos = 0;
        }

        break;
    case TECLA_RIGHT:
        if (mugitu->noranzkoa == 2)
        {
            pos.x = pos.x - distantzia;
            mugitu->noranzkoa = 2;
            mugitu->spritepos++;
            mugitu->yes = 1;
            mapak[mapaAukera].x++;
        }
        else
        {
            mugitu->noranzkoa = 2;
            mugitu->spritepos = 0;
            mugitu->yes = 0;
        }

        break;
    case TECLA_UP:
        if (mugitu->noranzkoa == 3)
        {
            pos.y = pos.y + distantzia;
            mugitu->noranzkoa = 3;
            mugitu->spritepos++;
            mugitu->yes = 1;
            mapak[mapaAukera].y--;
        }
        else
        {
            mugitu->noranzkoa = 3;
            mugitu->spritepos = 0;
            mugitu->yes = 0;
        }

        break;

    case TECLA_DOWN:
        if (mugitu->noranzkoa == 4)
        {
            pos.y = pos.y - distantzia;
            mugitu->noranzkoa = 4;
            mugitu->spritepos++;
            mugitu->yes = 1;
            mapak[mapaAukera].y++;
        }
        else
        {
            mugitu->noranzkoa = 4;
            mugitu->spritepos = 0;
            mugitu->yes = 0;
        }

        break;
    case TECLA_b:
        if (mugitu->velocidad == 30)
        {
            mugitu->velocidad = 10;
        }
        else
        {
            mugitu->velocidad = 30;
        }
        break;
    }
    pos = talka(mapak, mapaAukera, x, y, x1, y1, pos, *mugitu, fondoa, jokalaria);
    return pos;
}
/*void matrizeaInit(MAPAK *mapak, int mapaAukera)
{
    mapak[0].mapa[8][6] = 1;
    mapak[0].mapa[8][7] = 1;
    mapak[0].mapa[8][8] = 1;
    mapak[0].mapa[8][9] = 1;
    mapak[0].mapa[9][6] = 1;
    mapak[0].mapa[9][10] = 1;
    mapak[0].mapa[9][11] = 1;
    mapak[0].mapa[9][12] = 1;
    mapak[0].mapa[9][13] = 1;
    mapak[0].mapa[9][14] = 1;
    mapak[0].mapa[9][15] = 1;
    mapak[0].mapa[9][16] = 1;
    mapak[0].mapa[9][17] = 1;
    mapak[0].mapa[9][18] = 1;
    mapak[0].mapa[9][19] = 1;
    mapak[0].mapa[9][20] = 1;
    mapak[0].mapa[9][21] = 1;
    mapak[0].mapa[10][6] = 1;
    mapak[0].mapa[10][10] = 1;
    mapak[0].mapa[10][11] = 1;
    mapak[0].mapa[10][12] = 1;
    mapak[0].mapa[10][13] = 1;
    mapak[0].mapa[10][14] = 1;
    mapak[0].mapa[10][15] = 1;
    mapak[0].mapa[10][21] = 1;
    mapak[0].mapa[11][7] = 1;
    mapak[0].mapa[11][15] = 1;
    mapak[0].mapa[11][10] = 1;
    mapak[0].mapa[11][21] = 1;
    mapak[0].mapa[12][7] = 1;
    mapak[0].mapa[12][21] = 1;
    mapak[0].mapa[13][7] = 1;
    mapak[0].mapa[13][21] = 1;
    mapak[0].mapa[14][7] = 1;
    mapak[0].mapa[14][10] = 1;
    mapak[0].mapa[14][21] = 1;
    mapak[0].mapa[15][7] = 1;
    mapak[0].mapa[15][10] = 1;
    mapak[0].mapa[15][11] = 6;
    mapak[0].mapa[15][15] = 1;
    mapak[0].mapa[15][21] = 1;
    mapak[0].mapa[16][5] = 1;
    mapak[0].mapa[16][6] = 1;
    mapak[0].mapa[16][7] = 1;
    mapak[0].mapa[16][8] = 1;
    mapak[0].mapa[16][9] = 1;
    mapak[0].mapa[16][10] = 1;
    mapak[0].mapa[16][11] = 6;
    mapak[0].mapa[16][12] = 6;
    mapak[0].mapa[16][15] = 1;
    mapak[0].mapa[16][21] = 1;
    mapak[0].mapa[17][5] = 6;
    mapak[0].mapa[17][6] = 6;
    mapak[0].mapa[17][7] = 6;
    mapak[0].mapa[17][8] = 6;
    mapak[0].mapa[17][9] = 6;
    mapak[0].mapa[17][10] = 6;
    mapak[0].mapa[17][11] = 6;
    mapak[0].mapa[17][12] = 6;
    mapak[0].mapa[17][13] = 6;
    mapak[0].mapa[17][15] = 1;
    mapak[0].mapa[17][16] = 1;
    mapak[0].mapa[17][17] = 1;
    mapak[0].mapa[17][18] = 1;
    mapak[0].mapa[17][19] = 1;
    mapak[0].mapa[17][20] = 1;
    mapak[0].mapa[17][21] = 1;
    mapak[0].mapa[18][5] = 6;
    mapak[0].mapa[18][6] = 6;
    mapak[0].mapa[18][7] = 6;
    mapak[0].mapa[18][8] = 6;
    mapak[0].mapa[18][9] = 6;
    mapak[0].mapa[18][10] = 6;
    mapak[0].mapa[18][11] = 6;
    mapak[0].mapa[18][12] = 6;
    mapak[0].mapa[18][13] = 6;
    mapak[0].mapa[18][21] = 1;
    mapak[0].mapa[18][22] = 1;
    mapak[0].mapa[18][23] = 1;
    mapak[0].mapa[18][24] = 1;
    mapak[0].mapa[19][10] = 6;
    mapak[0].mapa[19][11] = 6;
    mapak[0].mapa[19][12] = 6;
    mapak[0].mapa[19][13] = 6;
    mapak[0].mapa[19][25] = 1;
    mapak[0].mapa[20][10] = 6;
    mapak[0].mapa[20][11] = 1;
    mapak[0].mapa[20][12] = 1;
    mapak[0].mapa[20][13] = 6;
    mapak[0].mapa[20][25] = 1;
    mapak[0].mapa[21][10] = 6;
    mapak[0].mapa[21][11] = 1;
    mapak[0].mapa[21][12] = 1;
    mapak[0].mapa[22][10] = 6;
    mapak[0].mapa[22][11] = 1;
    mapak[0].mapa[22][12] = 1;
    mapak[0].mapa[23][10] = 6;
    mapak[0].mapa[23][11] = 1;
    mapak[0].mapa[23][12] = 1;
    mapak[0].mapa[24][11] = 2;
    mapak[0].mapa[25][11] = 2;
    mapak[0].mapa[26][11] = 2;
}*/
void timeSprite(int ebentu, TIME *time, MUGIMENDU *mugitua)
{

    if (ebentu == 0 && time->kont == 0)
    {
        time->sprite01 = SDL_GetTicks();
        time->kont = 1;
    }
    if (ebentu != 0)
    {
        time->sprite01 = 0;
        time->sprite02 = 0;
        time->kont = 0;
    }
    if (time->sprite01 != 0 && ebentu == 0)
    {
        time->sprite02 = SDL_GetTicks();
        if (time->sprite02 >= time->sprite01 + 300)
        {
            mugitua->yes = 0;
            time->sprite01 = 0;
            time->sprite02 = 0;
            time->kont = 0;
        }
    }
}
int matrizInitf(MAPAK *mapak, int mapaAukera)
{
    FILE *file;
    file = fopen("C:\\Users\\Andoni\\Desktop\\MU\\juegos\\pokemon\\simpleSdlWrapper\\route1.txt", "r");
    if (file == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    for (int y = 0; y < mapak[mapaAukera].altueramax; y++)
    {
        for (int x = 0; x < mapak[mapaAukera].luzeramax; x++)
        {
            int n = fgetc(file);
            if (n != '\n')
            {
                mapak[mapaAukera].mapa[y][x] = n - 48;
            }
        }
    }
    fclose(file);
    return 0;
}
