#include "mathnuel.h"
bool es_par(int entrada);

bool es_primo(int entrada){
    int cant_divisores=0;
    for(int i=1;i<=entrada;i++){
        if(entrada%i == 0)
            cant_divisores++;
    }
    if(cant_divisores==2)
        return true;
    return false;
}
bool es_par(int entrada){

}
