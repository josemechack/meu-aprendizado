#include<stdio.h>
int main(){
    float valorCompra;
    printf("informe o valor da compra: ");scanf("%f",&valorCompra);
    if(valorCompra>500){float porcentualDesconto=0.1; float desconto=valorCompra-porcentualDesconto;printf("Valor apos o desconto %2f",desconto);}
    else if(valorCompra>=300 && valorCompra<=500){float porcentualDesconto=0.05; float desconto=valorCompra-porcentualDesconto;printf("Valor apos o desconto %2f",desconto);}
    else{printf("Sem desconto");}
    
return 0;
}
