#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "processor.h"
#include "validator.h"

///Cagaste numero 1
int validar_csv(char *archivo_de_entrada, int *uwu){
  if (*uwu != 4 ){
    printf("[DEBUG] si me abro~\n");
    printf("****LOUD BUZZER NOISE**** Usaste: %d argumentos \n tienes que usar 4" , *uwu);
    exit(1);
    return 1;
  }

  FILE *OwO = fopen(archivo_de_entrada, "r");
  printf("[DEBUG] stupid2\n");
  if (OwO == NULL){
    fclose(OwO);

  }else{
    fclose(OwO);
    return 1;
  }
  return 0;
}

//2
int validarn(int *Numero_solicitado, CityData *ciudades){
  //verificador de un numero solicitado valido (mayor a 0)
  if (*Numero_solicitado <= 0) {
    printf("Tienes que solicitar una cantidad distinta de 0");
    exit(1);
    return 1;
  }
  if (!ciudades) {
    printf("Error leyendo las ciudades.\n");
    return 1;
  }
  return 0;
}

//3
int validar_ciudad(CityData* ciudad) {
  if (ciudad->seismic_level < 1 || ciudad->seismic_level > 5) {
      printf("Error: El nivel sísmico de la ciudad %s es inválido: %d\n", ciudad->city_name, ciudad->seismic_level);
      return 1;  
  }

  if (ciudad->risk_percent < 0 || ciudad->risk_percent > 100) {
      printf("Error: El porcentaje de riesgo de la ciudad %s es inválido: %.2f\n", ciudad->city_name, ciudad->risk_percent);
      exit(1);
      return 1;  
  }
  return 0; 
}

int validar_todas_las_ciudades(CityData* ciudades, int total_ciudades) {
  for (int i = 0; i < total_ciudades; i++) {
      if (validar_ciudad(&ciudades[i]) != 0) {
      }
  }
  return 0;
}

//funcion para ordenar dos ciudades alfabeticamente de forma inversa
int comparar_alfabeto_ciudades(const char *ciudad_1, const char *ciudad_2){
  return -strcmp(ciudad_1, ciudad_2);
}