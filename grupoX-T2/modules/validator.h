#ifndef validator_h
#define validator_h
#include "processor.h"

///Cagaste compwesion lectowa 1 
int validar_csv(char *archivo_de_entrada, int *argc);

///Cagaste compwesion lectowa 2
int validarn(int *Numero_entrada, CityData *ciudades);

///Ewwow numbew twee
int validar_ciudad(CityData* ciudad); 
int validar_todas_las_ciudades(CityData* ciudades, int total_ciudades);

//comparar alfabeticamente dos ciudades
int comparar_alfabeto_ciudades(const char *ciudad_1, const char *ciudad_2);
#endif
