#include "pokemon.h"
#include "clock.h"
#include "imagen.h"
int spawnPokemon(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA fondoa)
{
    JOKO_ELEMENTUA base0, base1;
    COMBAT_ELEMENT element;
    POKEMON pokemon[3];
    int z = 0, damage = 0, atkSelection = 0;
    pokemon[0].Ps = 200;
    pokemon[1].Ps = 250;
    pokemon[0].Est.Ps = 200;
    pokemon[1].Est.Ps = 250;
    irudiaKendu(jokalaria.id);
    fondoa.id = irudiaKargatu("./img/fondos_bmp/forest_bg.bmp");
    base0.id = irudiaKargatu("./img/fondos_bmp/grass_base0.bmp");
    base1.id = irudiaKargatu("./img/fondos_bmp/grass_base1.bmp");
    HasieratuGrafioak(&element, pokemon);
    irudiaMugitu(fondoa.id, 0, 100);
    irudiaMugitu(base1.id, 600, 300);
    irudiaMugitu(base0.id, 20, 597);

    while (ebentuaJasoGertatuBada() != 13)
    {
        SDL_Delay(30);
        pantailaGarbitu();
        kenduGrafikoak(&element, pokemon, z);

        if (pokemon[0].Ps && pokemon[1].Ps && atkSelection)
        {
            if (random(pokemon[0].Atak[atkSelection].Precisión.a, pokemon[0].Atak[atkSelection].Precisión.b) == 1)
            {
                damageCalculator(&pokemon[0], &pokemon[1], damage, atkSelection);
            }
        }

        z = KargatuGrafikoak(&element, pokemon, &atkSelection);
        arkatzKoloreaEzarri(0, 0, 0xFF);
        irudiakMarraztu();
        pantailaBerriztu();
    }
    kenduGrafikoak(&element, pokemon, z);
    irudiaKendu(fondoa.id);
    irudiaKendu(base0.id);
    irudiaKendu(base1.id);
    fondoa.id = irudiaKargatu("./img/fondos_bmp/route_1_c.bmp");
    return fondoa.id;
};
int random(int num2, int num)
{
    long tiempo_transcurrido;
    long long randomnum = 0;
    tiempo_transcurrido = gettime();
    randomnum = (tiempo_transcurrido * 389838483040303) % num + 1;
    if (randomnum <= num2)
    {
        randomnum = 1;
    }
    return randomnum;
}
void kenduGrafikoak(COMBAT_ELEMENT *element, POKEMON *pokemon, int z)
{
    int numb0 = pokemon[1].Ps / 100;
    int numb1 = (pokemon[1].Ps / 10) % 10;
    irudiaKendu(element->databox.me);
    irudiaKendu(element->databox.riv);
    irudiaKendu(element->hp.me);
    irudiaKendu(element->hp.riv);
    irudiaKendu(element->bar);
    irudiaKendu(element->box.select);
    irudiaKendu(element->box.text);
    irudiaKendu(element->box.box[0]);
    irudiaKendu(element->box.box[1]);
    irudiaKendu(element->box.box[2]);
    irudiaKendu(element->box.box[3]);
    irudiaKendu(element->pokemon[0]);
    irudiaKendu(element->pokemon[1]);
    irudiaKendu(element->hp_max.number00);
    irudiaKendu(element->hp_max.number01);
    irudiaKendu(element->hp_max.number02);
    switch (z)
    {
    case 0:
        irudiaKendu(element->hp.number00);
        irudiaKendu(element->hp.number01);
        irudiaKendu(element->hp.number02);
        break;
    case 1:
        irudiaKendu(element->hp.number01);
        irudiaKendu(element->hp.number02);
        break;
    case 2:
        irudiaKendu(element->hp.number02);
        break;
    }
}
int KargatuGrafikoak(COMBAT_ELEMENT *element, POKEMON *pokemon, int *atkSelection)
{
    POSIZIOA saguPos;
    saguPos = saguarenPosizioa();
    int egoera = ebentuaJasoGertatuBada();
    int numb0 = pokemon[1].Ps / 100;
    int numb1 = (pokemon[1].Ps / 10) % 10;
    int numb2 = pokemon[1].Ps % 10;
    int numb_max0 = pokemon[1].Est.Ps / 100;
    int numb_max1 = (pokemon[1].Est.Ps / 10) % 10;
    int numb_max2 = pokemon[1].Est.Ps % 10;
    int emaitza = 0;
    element->databox.me = irudiaKargatu("./img/combat/mi_databox.bmp");
    element->databox.riv = irudiaKargatu("./img/combat/rival_databox.bmp");
    element->hp.me = irudiaKargatuhp(pokemon, 1);
    element->hp.riv = irudiaKargatuhp(pokemon, 0);
    element->bar = irudiaKargatu(".\\img\\combat\\HP_number_bmp\\bar.bmp");
    element->box.select = irudiaKargatu(".\\img\\combat\\Fight\\boxes.bmp");
    element->box.text = irudiaKargatu(".\\img\\combat\\Fight\\text.bmp");

    element->pokemon[1] = irudiaKargatu("./img/combat/pokemon/DARKRAI.bmp");
    element->pokemon[0] = irudiaKargatu("./img/combat/pokemon/MEW.bmp");

    snprintf(element->hp_max.number0, sizeof(element->hp_max.number0), ".\\img\\combat\\HP_number_bmp\\%d.bmp",
             numb_max0);
    element->hp_max.number00 = irudiaKargatu(element->hp_max.number0);
    irudiaMugitu(element->hp_max.number00, 840, 623);
    snprintf(element->hp_max.number1, sizeof(element->hp_max.number1), ".\\img\\combat\\HP_number_bmp\\%d.bmp",
             numb_max1);
    element->hp_max.number01 = irudiaKargatu(element->hp_max.number1);
    irudiaMugitu(element->hp_max.number01, 855, 623);
    snprintf(element->hp_max.number2, sizeof(element->hp_max.number2), ".\\img\\combat\\HP_number_bmp\\%d.bmp",
             numb_max2);
    element->hp_max.number02 = irudiaKargatu(element->hp_max.number2);
    irudiaMugitu(element->hp_max.number02, 870, 623);
    aukeratuBox(element, saguPos, egoera, atkSelection);

    if (numb0 != 0)
    {
        snprintf(element->hp.number0, sizeof(element->hp.number0), ".\\img\\combat\\HP_number_bmp\\%d.bmp", numb0);
        element->hp.number00 = irudiaKargatu(element->hp.number0);
        irudiaMugitu(element->hp.number00, 780, 623);
    }
    else
    {
        emaitza = 1;
    }
    if (numb1 != 0 || numb0 != 0)
    {
        snprintf(element->hp.number1, sizeof(element->hp.number1), ".\\img\\combat\\HP_number_bmp\\%d.bmp", numb1);
        element->hp.number01 = irudiaKargatu(element->hp.number1);
        irudiaMugitu(element->hp.number01, 795, 623);
    }
    else
    {
        emaitza = 2;
    }
    snprintf(element->hp.number2, sizeof(element->hp.number2), ".\\img\\combat\\HP_number_bmp\\%d.bmp", numb2);
    element->hp.number02 = irudiaKargatu(element->hp.number2);
    irudiaMugitu(element->hp.number02, 810, 623);

    irudiaMugitu(element->databox.me, 740, 570);
    irudiaMugitu(element->databox.riv, 0, 100);
    irudiaMugitu(element->pokemon[0], 630, 180);
    irudiaMugitu(element->pokemon[1], 150, 501);
    irudiaMugitu(element->hp.me, 876, 604);
    irudiaMugitu(element->hp.riv, 118, 134);
    irudiaMugitu(element->bar, 825, 623);
    irudiaMugitu(element->box.select, -220, 660);
    irudiaMugitu(element->box.text, 480, 660);
    irudiaMugitu(element->box.box[0], -120, 250);
    irudiaMugitu(element->box.box[1], 160, 250);
    irudiaMugitu(element->box.box[2], -120, 342);
    irudiaMugitu(element->box.box[3], 160, 342);

    return emaitza;
}
void HasieratuGrafioak(COMBAT_ELEMENT *element, POKEMON *pokemon)
{
    int numb0 = pokemon[1].Ps / 100;
    int numb1 = (pokemon[1].Ps / 10) % 10;
    int numb2 = pokemon[1].Ps % 10;
    int numb_max0 = pokemon[1].Est.Ps / 100;
    int numb_max1 = (pokemon[1].Est.Ps / 10) % 10;
    int numb_max2 = pokemon[1].Est.Ps % 10;
    element->situacion = 0;
    element->databox.me = irudiaKargatu("./img/combat/mi_databox.bmp");
    element->databox.riv = irudiaKargatu("./img/combat/rival_databox.bmp");
    element->hp.me = irudiaKargatuhp(pokemon, 0);
    element->hp.riv = irudiaKargatuhp(pokemon, 1);
    element->bar = irudiaKargatu(".\\img\\combat\\HP_number_bmp\\bar.bmp");
    element->box.select = irudiaKargatu(".\\img\\combat\\Fight\\boxes.bmp");
    element->box.text = irudiaKargatu(".\\img\\combat\\Fight\\boxes.bmp");
    element->box.box[0] = irudiaKargatu(".\\img\\combat\\Fight\\fight.bmp");
    element->box.box[1] = irudiaKargatu(".\\img\\combat\\Fight\\pokemon.bmp");
    element->box.box[2] = irudiaKargatu(".\\img\\combat\\Fight\\fight.bmp");
    element->box.box[3] = irudiaKargatu(".\\img\\combat\\Fight\\pokemon.bmp");
    element->pokemon[1] = irudiaKargatu("./img/combat/pokemon/DARKRAI.bmp");
    element->pokemon[0] = irudiaKargatu("./img/combat/pokemon/MEW.bmp");

    snprintf(element->hp.number0, sizeof(element->hp.number0), ".\\img\\combat\\HP_number_bmp\\%d.bmp", numb0);
    snprintf(element->hp.number1, sizeof(element->hp.number1), ".\\img\\combat\\HP_number_bmp\\%d.bmp", numb1);
    snprintf(element->hp.number2, sizeof(element->hp.number2), ".\\img\\combat\\HP_number_bmp\\%d.bmp", numb2);
    element->hp.number00 = irudiaKargatu(element->hp.number0);
    element->hp.number01 = irudiaKargatu(element->hp.number1);
    element->hp.number02 = irudiaKargatu(element->hp.number2);

    snprintf(element->hp_max.number0, sizeof(element->hp_max.number0), ".\\img\\combat\\HP_number_bmp\\%d.bmp",
             numb_max0);
    element->hp_max.number00 = irudiaKargatu(element->hp_max.number0);
    snprintf(element->hp_max.number1, sizeof(element->hp_max.number1), ".\\img\\combat\\HP_number_bmp\\%d.bmp",
             numb_max1);
    element->hp_max.number01 = irudiaKargatu(element->hp_max.number1);
    snprintf(element->hp_max.number2, sizeof(element->hp_max.number2), ".\\img\\combat\\HP_number_bmp\\%d.bmp",
             numb_max2);
    element->hp_max.number02 = irudiaKargatu(element->hp_max.number2);
}
void aukeratuBox(COMBAT_ELEMENT *element, POSIZIOA saguPos, int egoera, int *atkSelection)
{
    switch (element->situacion)
    {
    case 0: {

        if ((0 < saguPos.x) && (saguPos.x < 290) && (650 < saguPos.y) && (saguPos.y < 750))
        {
            element->box.box[0] = irudiaKargatu(".\\img\\combat\\Fight\\fight_2.bmp");
            if (egoera == SAGU_BOTOIA_EZKERRA)
            {
                element->situacion = 1;
            }
        }
        else
        {
            element->box.box[0] = irudiaKargatu(".\\img\\combat\\Fight\\fight.bmp");
        }

        if ((290 < saguPos.x) && (saguPos.x < 600) && (650 < saguPos.y) && (saguPos.y < 750))
        {
            element->box.box[1] = irudiaKargatu(".\\img\\combat\\Fight\\pokemon_2.bmp");
            if (egoera == SAGU_BOTOIA_EZKERRA)
            {
                element->situacion = 2;
            }
        }
        else
        {
            element->box.box[1] = irudiaKargatu(".\\img\\combat\\Fight\\pokemon.bmp");
        }

        if ((0 < saguPos.x) && (saguPos.x < 290) && (750 < saguPos.y) && (saguPos.y < 850))
        {
            element->box.box[2] = irudiaKargatu(".\\img\\combat\\Fight\\mochila_2.bmp");
            if (egoera == SAGU_BOTOIA_EZKERRA)
            {
                element->situacion = 3;
            }
        }
        else
        {
            element->box.box[2] = irudiaKargatu(".\\img\\combat\\Fight\\mochila.bmp");
        }
        if ((290 < saguPos.x) && (saguPos.x < 600) && (750 < saguPos.y) && (saguPos.y < 850))
        {
            element->box.box[3] = irudiaKargatu(".\\img\\combat\\Fight\\huir_2.bmp");
            if (egoera == SAGU_BOTOIA_EZKERRA)
            {
                element->situacion = 4;
            }
        }
        else
        {
            element->box.box[3] = irudiaKargatu(".\\img\\combat\\Fight\\huir.bmp");
        }
        break;
    }
    case 1: {
        if ((0 < saguPos.x) && (saguPos.x < 290) && (650 < saguPos.y) && (saguPos.y < 750))
        {
            element->box.box[0] = irudiaKargatu(".\\img\\combat\\Fight\\fight_2.bmp");
            if (egoera == SAGU_BOTOIA_EZKERRA)
            {
                element->situacion = 1;
                *atkSelection = 1;
            }
        }
        else
        {
            element->box.box[0] = irudiaKargatu(".\\img\\combat\\Fight\\fight.bmp");
        }

        if ((290 < saguPos.x) && (saguPos.x < 600) && (650 < saguPos.y) && (saguPos.y < 750))
        {
            element->box.box[1] = irudiaKargatu(".\\img\\combat\\Fight\\pokemon_2.bmp");
            if (egoera == SAGU_BOTOIA_EZKERRA)
            {
                element->situacion = 0;
                *atkSelection = 2;
            }
        }
        else
        {
            element->box.box[1] = irudiaKargatu(".\\img\\combat\\Fight\\fight_2.bmp");
        }
        if ((0 < saguPos.x) && (saguPos.x < 290) && (750 < saguPos.y) && (saguPos.y < 850))
        {
            element->box.box[2] = irudiaKargatu(".\\img\\combat\\Fight\\mochila_2.bmp");
            if (egoera == SAGU_BOTOIA_EZKERRA)
            {
                element->situacion = 0;
                *atkSelection = 3;
            }
        }
        else
        {
            element->box.box[2] = irudiaKargatu(".\\img\\combat\\Fight\\mochila.bmp");
        }
        if ((290 < saguPos.x) && (saguPos.x < 600) && (750 < saguPos.y) && (saguPos.y < 850))
        {
            element->box.box[3] = irudiaKargatu(".\\img\\combat\\Fight\\huir_2.bmp");
            if (egoera == SAGU_BOTOIA_EZKERRA)
            {
                element->situacion = 0;
                *atkSelection = 4;
            }
        }
        else
        {
            element->box.box[3] = irudiaKargatu(".\\img\\combat\\Fight\\huir.bmp");
        }

        break;
    }
    case 2:
        break;
    }
}
void damageCalculator(POKEMON *pokemon1, POKEMON *pokemon2, int damage, int atak_selection)
{
    int B = 1;                                    // bonificacion de stab
    int E = 1;                                    // efectividad del golpe
    int V = random(1, 25) + 85;                   // variacion del daño entre 85 y 100
    int N = pokemon1->Lvl;                        // nivel del pokemon
    int A = pokemon1->Est.Atk;                    // stat de ataque
    int D = pokemon2->Est.Def;                    // stat de defensa
    int P = pokemon1->Atak[atak_selection].Power; // poder del ataque selecionado

    damage = 0.01 * B * E * V * (((0.2 * N + 1) * A * P) / (25 * D) + 2);
}
int PokemonCreator(int Species)
{
    POKEMON pokemon;
    generateId(&pokemon.Id);
    generateIV(&pokemon.IVS);
    generateEV(&pokemon.EVS);
    generateEST(&pokemon.Est);
    generateAtk(&pokemon.Atak);
    generateHab(&pokemon.Hability);
    writePokemondata(pokemon);
    return 0;
}
int writePokemondata()
{
    FILE *file;
    file = fopen("C:\\Users\\Andoni\\Desktop\\MU\\juegos\\pokemon\\simpleSdlWrapper\\route1.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    fclose(file);
    return 0;
}
int generateId(int *Id)
{

    return 0;
}
int generateIV(EST *est){
    est->Atk=random(1,31);
    est->Spa=random(1,31);
    est->Spe=random(1,31);
    est->Sdef=random(1,31);
    est->Def=random(1,31);
    est->Ps=random(1,31);
}
int generateEV(EST *est){
    est->Atk=0;
    est->Spa=0;
    est->Spe=0;
    est->Sdef=0;
    est->Def=0;
    est->Ps=0;
}