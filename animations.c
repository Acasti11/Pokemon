#include "animations.h"
void jumpAnimation(int i, JOKO_ELEMENTUA **fondoa, JOKO_ELEMENTUA **jokalaria)
{
    (*jokalaria)->id = irudiaKargatu(".\\img\\sprite_bmp\\2.bmp");
    for (int z = 0; z < 5; z++)
    {
        SDL_Delay(30);
        pantailaGarbitu();
        irudiaKendu((*jokalaria)->id);
        arkatzKoloreaEzarri(0, 0, 0xFF);
        (*jokalaria)->id = irudiaKargatu(".\\img\\sprite_bmp\\2.bmp");
        (*fondoa)->pos.y = (*fondoa)->pos.y - 5;
        (*fondoa)->pos.x = (*fondoa)->pos.x - 1;
        irudiaMugitu((*jokalaria)->id, (*jokalaria)->pos.x, (*jokalaria)->pos.y);
        irudiaMugitu((*fondoa)->id, (*fondoa)->pos.x, (*fondoa)->pos.y);
        irudiakMarraztu();
        pantailaBerriztu();
    }
    for (int z = 0; z < 5; z++)
    {
        SDL_Delay(30);
        pantailaGarbitu();
        arkatzKoloreaEzarri(0, 0, 0xFF);
        irudiaKendu((*jokalaria)->id);
        (*jokalaria)->id = irudiaKargatu(".\\img\\sprite_bmp\\2.bmp");
        (*fondoa)->pos.y = (*fondoa)->pos.y - 5;
        (*fondoa)->pos.x = (*fondoa)->pos.x + 1;
        irudiaMugitu((*jokalaria)->id, (*jokalaria)->pos.x, (*jokalaria)->pos.y);
        irudiaMugitu((*fondoa)->id, (*fondoa)->pos.x, (*fondoa)->pos.y);
        irudiakMarraztu();
        pantailaBerriztu();
    }
    SDL_Delay(30);
    pantailaGarbitu();
    irudiaKendu((*jokalaria)->id);
    arkatzKoloreaEzarri(0, 0, 0xFF);
    (*fondoa)->pos.y = (*fondoa)->pos.y - 15;
    (*jokalaria)->id = irudiaKargatu(".\\img\\sprite_bmp\\2.bmp");
    irudiaMugitu((*jokalaria)->id, (*jokalaria)->pos.x, (*jokalaria)->pos.y);
    irudiaMugitu((*fondoa)->id, (*fondoa)->pos.x, (*fondoa)->pos.y);
    irudiakMarraztu();
    pantailaBerriztu();
    SDL_Delay(30);
    pantailaGarbitu();
    irudiaKendu((*jokalaria)->id);
    arkatzKoloreaEzarri(0, 0, 0xFF);
    (*jokalaria)->id = irudiaKargatu(".\\img\\sprite_bmp\\3.bmp");
    (*fondoa)->pos.y = (*fondoa)->pos.y - 15;
    irudiaMugitu((*jokalaria)->id, (*jokalaria)->pos.x, (*jokalaria)->pos.y);
    irudiaMugitu((*fondoa)->id, (*fondoa)->pos.x, (*fondoa)->pos.y);
    irudiakMarraztu();
    pantailaBerriztu();
    irudiaKendu((*jokalaria)->id);
}