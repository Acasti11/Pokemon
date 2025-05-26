#include "colision.h"
#include <stdio.h>

POSIZIOA talka(MAPAK *mapak, int mapaAukera, int x, int y, int x1, int y1, POSIZIOA pos, MUGIMENDU mugitu,
               JOKO_ELEMENTUA *fondoa, JOKO_ELEMENTUA *jokalaria)
{
    switch (mapak[mapaAukera].mapa[mapak[mapaAukera].y][mapak[mapaAukera].x])
    {
    case 1:
        mapak[mapaAukera].x = x;
        mapak[mapaAukera].y = y;
        pos.x = x1;
        pos.y = y1;
        break;
    case 2:

        if (mugitu.noranzkoa == 4)
        {
            mapak[mapaAukera].y = mapak[mapaAukera].y + 1;
            jumpAnimation(4, &fondoa, &jokalaria);
            pos.x = fondoa->pos.x;
            pos.y = fondoa->pos.y;
        }
        else
        {
            mapak[mapaAukera].x = x;
            mapak[mapaAukera].y = y;
            printf("colision");
            pos.x = x1;
            pos.y = y1;
        }
        break;
    case 6:
        if (mugitu.yes == 1)
        {

            if (1 == random(1, 10))
            {
                fondoa->id = spawnPokemon(*jokalaria, *fondoa);
            }
            break;
        }
    default:
        break;
    }
    return pos;
}
