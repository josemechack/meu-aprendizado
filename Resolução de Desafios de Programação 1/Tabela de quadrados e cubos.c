/*
   Leia um número N e exiba os quadrados dos números de 1 a N.
*/
#include<stdio.h>
#include<stdint.h>
void main()
{
    int num;
    scanf("%d",&num);
    system("clear");
    printf("############################################\n");
    printf("\t\tTABELA\n");
    printf("############################################");
    for(int i=1; i<=num; ++i){
       int quadrado, cubo;
       quadrado=i*i;
       cubo=i*i*i;
       printf("\nNUMERO\t\tQUADRADO\t\tCUBO\n%i%20d%22d",i,quadrado,cubo);
    }

}


