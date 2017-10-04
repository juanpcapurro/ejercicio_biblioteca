#include <stdio.h>
#include <stdbool.h>
#include "mathnuel.h"


int main(){
    int numero_ingresado;
    puts("Ingrese el numero a chequear si es primo: ");
    scanf(" %i", &numero_ingresado);

    if(es_primo(numero_ingresado))
        puts("Maiamee!! El numero es primo");
    else
        puts("Basta chicos!! El numero no es primo");
}
