#include <stdio.h>

int main(){



int num1, i, a;
scanf(" %i", &num1);
a=0;
for(i=1;i<=num1;i++)
{
    if(num1%i == 0)
a++;
}

if(a==2)
    puts("Maiamee!! El numero es primo");
else
{
    puts("Basta chicos!! El numero no es primo");
}

}
