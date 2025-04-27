#include "processor.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

///Puntero a una instancia de la estrucutra de CityData
CityData* leer_info(const char* archivo_de_entrada, int* contador2) {
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

        //leemos el nombre de la ciudad
        char* token = strtok(linea, ",");

        strncpy(cities[contador].city_name, token, sizeof(cities[contador].city_name));
        cities[contador].city_name[sizeof(cities[contador].city_name) - 1] = '\0';

        //leemos el nivel sismico
        token = strtok(NULL, ",");

        cities[contador].seismic_level = atoi(token);

        //leemos el porcentaje de riesgo
        token = strtok(NULL, ",\n");

        //como las intrucciones dicen que solo este item puede estar faltante, añadimos la
        //verificacion de si el token de corte no esta o si el largo del str de riesgo es 0,
        //en caso de que sea el caso (valga la redunancia) asignamos el riesgo como 0, asumo
        //que no hay ciudades con riesgo 0% (no sucede en la realidd)
        if (token == NULL || strlen(token) == 0) {
            cities[contador].risk_percent = 0;
        } else {
            cities[contador].risk_percent = atof(token);
        }

        contador++;
    }

    fclose(archivo);
	*contador2 = contador;
    return cities;
}
