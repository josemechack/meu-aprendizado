#include<stdio.h>
int main(){
    char opcao;
    int numero, numero2;
    printf("Esolha a operacao desejada: +, -, x, / ");
    scanf("%c",&opcao);
    switch(opcao){
        case '+':
            int soma;
              printf("Informe o primeiro numero: ");
              scanf("%d",&numero);
              printf("Informe o segundo numero: ");
              scanf("%d",&numero2);
              soma=numero+numero2;
              printf("Resultado da soma: %i",soma);
        break;
        case '-':
            int subtracao;
              printf("Informe o primeiro numero: ");
              scanf("%d",&numero);
              printf("Informe o segundo numero: ");
              scanf("%d",&numero2);
              subtracao=numero-numero2;
              printf("Resultado da subtracao: %i",subtracao);
        break;
        case 'x':
            int multiplicacao;
              printf("Informe o primeiro numero: ");
              scanf("%d",&numero);
              printf("Informe o segundo numero: ");
              scanf("%d",&numero2);
              multiplicacao=numero*numero2;
              printf("Resultado da multiplicacao: %i",multiplicacao);
        break;
        case '/':
            float divisao, num, num2;
              printf("Informe o primeiro numero: ");
              scanf("%f",&num);
              printf("Informe o segundo numero: ");
              scanf("%f",&num2);
              if(num==0){
                printf("Impossivel a divisao.");
              }
              divisao=num/num2;
              printf("Resultado da divisao: %f",divisao);
        default: break;
    }

return 0;
}
