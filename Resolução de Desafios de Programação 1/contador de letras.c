#include<stdio.h>
int main(){
    char palavras[100];
    int contador=0;
    printf("Informe a palavra: ");
    fgets(palavras,100,stdin);
    for(int i=0; i<strlen(palavras); ++i){
        if(palavras[i]>='A'&&palavras[i]<='Z'||palavras[i]>='a'&&palavras[i]<='z')
            ++contador;
    }
    printf("Quantidade de palavras: %d",contador);
return 0;
}
