#include <stdio.h>
#include <stdlib.h>

#include "modules/processor.h"
#include "modules/sorter.h"
#include "modules/validator.h"

int main(int argc, char *argv[]) {   
    // chequeo de argumentos primero
    if (argc != 4) {
        printf("Uso: %s <input> <N> <output>\n", argv[0]);
        return 1;
    }

    char* archivo_de_entrada = argv[1];
    char* archivo_de_salida = argv[3];
    int Numero_solicitado = atoi(argv[2]);

    // Leer info del CSV
    int total_ciudades = 0;
    CityData* ciudades = leer_info(archivo_de_entrada, &total_ciudades);
    if (!ciudades) {
        printf("Error leyendo las ciudades.\n");
        return 1;
    }

    //verificador de un numero solicitado valido (mayor a 0)
    if (Numero_solicitado < 0) {
      printf("error en el numero de ciudades a categorizar");
      return 1;
    }

    // Ordenar las ciudades
    qsort(ciudades, total_ciudades, sizeof(CityData), comparar_ciudades);

    // Abrir archivo de salida
    FILE* salida = fopen(archivo_de_salida, "w");
    if (!salida) {
        perror("Error al abrir el archivo de salida");
        free(ciudades);
        return 1;
    }

    // Escribir encabezado del archivo de salida
    fprintf(salida, "City Name,Seismic Level,Risk Percent\n");

    // Escribir las primeras ciudades ordenadas (primeras = a la cantidad solicitada)
    for (int i = 0; i < Numero_solicitado; i++) {
        if (ciudades[i].risk_percent == 0) {
            fprintf(salida, "%s,%d,\n", ciudades[i].city_name, ciudades[i].seismic_level);
        } else {
            fprintf(salida, "%s,%d,%.2f\n", ciudades[i].city_name, ciudades[i].seismic_level, ciudades[i].risk_percent);
        }
    }

    // Cerrar archivos y liberar memoria
    fclose(salida);
    free(ciudades);

    return 0;
}
