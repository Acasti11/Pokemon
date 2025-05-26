#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 100

typedef struct Img
{
    int id;
    SDL_Surface *imagen;
    SDL_Texture *texture;
    SDL_Rect dest;
} IMG;

int irudiaKargatu(char *fileName);
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
void irudiaKendu(int id);
int irudiaKargatuhp();

#endif
