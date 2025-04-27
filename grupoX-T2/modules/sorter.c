#include "sorter.h"
#include "validator.h"
#include <string.h>

/// Nota a futuro: sintaxis generica de qsort() (funcion integrada del quicksort) qsort(arr, n, size, comp) , donde arr: es eñ puntero al primer elemento
// n: es el numero de elementos. size: tamaño de cada elemento. comp: puntero a una funcion que compare.

//funcion usada por qsort (pa ordenar las iudades)
int comparar_ciudades(const void* a, const void* b) {
    const CityData* ciudad1 = (const CityData*) a;
    const CityData* ciudad2 = (const CityData*) b;

    // Comparar seismic_levle
    if (ciudad1->seismic_level != ciudad2->seismic_level) {
          //ponemos al mayor primero
        return ciudad2->seismic_level - ciudad1->seismic_level;
    }

    // si el nivel sismico es igual, compararemos el riesgo
    int riesgo1_faltante = (ciudad1->risk_percent == 0);
    int riesgo2_faltante = (ciudad2->risk_percent == 0);

    if (riesgo1_faltante && !riesgo2_faltante) {
        // ciudad2 tiene riesgo válido, ciudad1 no, entonces ciudad2 va primero
        if (ciudad1->seismic_level >= 4) return -1;
        return 1;
    }
    if (!riesgo1_faltante && riesgo2_faltante) {
      //ciudad1 tiene una entrada valida, entonces caso contrario del de arriba
      if (ciudad2->seismic_level >= 4) return 1;
        return -1;
    }

    //los dos tienen una entrada valida
    if (!riesgo1_faltante && !riesgo2_faltante) {
        // oordenamos segun cual tiene un mayor riesgo
        if (ciudad1->risk_percent < ciudad2->risk_percent) return 1;
        if (ciudad1->risk_percent > ciudad2->risk_percent) return -1;
    }

    //ninguno tiene entrada valida
    if (riesgo1_faltante && riesgo2_faltante) {
        // Aplicamos las reglas segun el nivel sismico
        if (ciudad1->seismic_level >= 4 && ciudad2->seismic_level <= 2) return -1;
        if (ciudad1->seismic_level <= 2 && ciudad2->seismic_level >= 4) return 1;
        if (ciudad1->seismic_level == 3 && ciudad2->seismic_level != 3) return 1;
        if (ciudad1->seismic_level != 3 && ciudad2->seismic_level == 3) return -1;
        // Si tienen el mismo nivel, entonces, seguimos alfabéticamente inverso
    }

    /// si todo es igual antes de, entonces seguimos con ordenar segun el alfabeto inverso
    /// nota para el corrector esta función esta definida en validator.c / validator.h por
    // si es que revisas antes esta
    return comparar_alfabeto_ciudades(ciudad1->city_name, ciudad2->city_name);
}
