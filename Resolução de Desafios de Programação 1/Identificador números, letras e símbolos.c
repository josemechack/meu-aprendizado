#include<stdio.h>
int main(){
   char caractere;
   printf("informe a letra ");
   scanf("%c",&caractere);
   if(caractere>='0'&& caractere<='9'){
    printf("É um numero");
   }
   else if(caractere>='A'&&caractere<='Z'||caractere>='a'&&caractere<='z'){
    printf("É uma letra");
   }
   else{
    printf("é um símbolo");
   }

return 0;
}

