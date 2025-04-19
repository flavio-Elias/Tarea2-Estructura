#include <stdio.h>
#include <stdlib.h>

#include "modules/processor.h"
#include "modules/sorter.h"
#include "modules/validator.h"

int main(int argc, char *argv[]) {   

    char* archivo_de_entrada = argv[1];
    char* archivo_de_salida = argv[3];  
    
    //chequeo de arg
    if (argc != 4) {
        printf("Uso: %s <input> <N> <output>\n", argv[0]);
        return 1;
        }

    FILE* entrada = fopen(archivo_de_entrada, "r");

    FILE* salida = fopen(archivo_de_salida, "w");


 // Implementación pendiente

 CityData* ciudades = leer_info(archivo_de_entrada);
 free(ciudades);

 return 0;
}