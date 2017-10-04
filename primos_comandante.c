#include <stdio.h>
#include "math.h"


int main(){
    int entrada;
    puts("Ingrese el numero a chequear si es primo: ");
    scanf(" %i", &entrada);
    if(es_primo(entrada))
        puts("Maiamee!! El numero es primo");
    else
        puts("Basta chicos!! El numero no es primo");
    return 0;
}
