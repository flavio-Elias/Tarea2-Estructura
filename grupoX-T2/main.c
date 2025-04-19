#include <stdio.h>
#include <stdlib.h>

#include "modules/processor.h"
#include "modules/sorter.h"
#include "modules/validator.h"

typedef struct {
 char city_name[50];
 int seismic_level;
 float risk_percent;
} CityData;

int main(int argc, char *argv[]) {   

char* archivo_de_entrada = argv[1];
char* archivo_de_salida = argv[3];  

 if (argc != 4) {
 printf("Uso: %s <input> <N> <output>\n", argv[0]);
 return 1;
 }
 // Implementación pendiente


 return 0;
}