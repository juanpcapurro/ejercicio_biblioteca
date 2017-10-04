#include "math.h"

bool es_primo(int entrada){
    int cant_divisores=0;
    for(int i=1;i<=entrada;i++){
        if(entrada%i == 0)
            cant_divisores++;
    }
    if(cant_divisores!=2)
        return false;
    return true;
}
