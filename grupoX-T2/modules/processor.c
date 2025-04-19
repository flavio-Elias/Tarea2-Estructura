#include "processor.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

///Puntero a una instancia de la estrucutra de CityData
CityData* leer_info(const char* archivo_de_entrada) {
    FILE* archivo = fopen(archivo_de_entrada, "r");

    char linea[256];
    int i = 4;
    int contador = 0;


    CityData* cities = malloc(i*sizeof(CityData));

    fgets(linea, sizeof(linea), archivo);

    while (fgets(linea, sizeof(linea), archivo)) {
        if (contador >= i){
            i*= 2;
            CityData* temp = realloc(cities, i *sizeof(CityData));
            cities = temp;
        }

        ///Nombre de la ciudad
        char* separador = strtok(linea, ",");
        strncpy(cities[contador].city_name,separador,sizeof(cities[contador].city_name));
        cities[contador].city_name[sizeof(cities[contador].city_name)-1] = '\0';

        printf("%s\n", cities[contador].city_name);

        /// Nivel
        separador = strtok(NULL, ",");
        cities[contador].seismic_level = atoi(separador);

        ///riesgo
        separador = strtok(NULL, ",\n");
        cities[contador].risk_percent = atof(separador);


        contador++;
    }
    fclose(archivo);
    return cities;
}
