#include <stdio.h>

bool es_primo(int entrada){
    int cant_divisores=0;
    for(int i=1;i<=entrada;i++){
        if(entrada%i == 0)
            cant_divisores++;
    }
    if(cant_divisores==2)
        return true;
    else
        return false;
}

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
