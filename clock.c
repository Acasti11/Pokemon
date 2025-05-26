#include "clock.h"
#include <time.h>
long tiempoInicio;

void initializetime()
{
    tiempoInicio = (long)clock();
}
long gettime()
{
    return (long)clock() - tiempoInicio;
}