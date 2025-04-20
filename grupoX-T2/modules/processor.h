#ifndef processor_h
#define processor_h


#include <stdio.h>

typedef struct {
    char city_name[50];
    int seismic_level;
    float risk_percent;
   } CityData;

CityData* leer_info(const char* archivo_de_entrada, int*contador2);

#endif