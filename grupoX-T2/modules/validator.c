#include "validator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

///Cagaste numero 1
int validar_csv(const char *archivo_de_entrada){
  FILE *OwO = fopen(archivo_de_entrada, "r");
  if (OwO == NULL){
    fclose(OwO);
    return 0;
  }else{
    fclose(OwO);
    return 1;
  }
}

//funcion para ordenar dos ciudades alfabeticamente de forma inversa
int comparar_alfabeto_ciudades(const char *ciudad_1, const char *ciudad_2){
  return -strcmp(ciudad_1, ciudad_2);
}