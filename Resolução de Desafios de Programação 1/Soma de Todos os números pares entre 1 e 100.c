#include<stdio.h>
int main(){
    int soma=0, i;
    printf(" Todos os pares do intervalo (1 à 100):\n ");
    for(i=2; i<=100; i+=2){
        soma+=i;
        printf("%i ", i);
    }
    printf("\n\n A soma de todos os números pares dentro do intervalo (1 à 100): %i",soma);
return 0;
}
