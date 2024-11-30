#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int contarVogais=0;
    char cadeiaCaractere[100], converChar;
    printf("Informe a Palavras: ");
    fgets(cadeiaCaractere,100,stdin);
    for(int count=0; count<strlen(cadeiaCaractere); ++count){
        converChar=tolower(cadeiaCaractere[count]);
        switch (converChar){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++contarVogais;
            default:
            break;
        }
    }
    printf("A Palavra contém %d Vogais", contarVogais);
return 0;
}
