#include <stdio.h>
int main(){
	int matriz[3][3];
	int linhas, colunas;

	for(linhas=0; linhas<3; ++linhas){
		for(colunas=0; colunas<3; ++colunas)
		{
            printf("Informe os números: ");
			scanf("%i",&matriz[linhas][colunas]);
		}
	}


	for(linhas=0; linhas<3; ++linhas){
		for(colunas=0; colunas<3; ++colunas)
		{
			printf("%3i",matriz[linhas][colunas]);
		}
		printf("\n");
	}

    printf("\n");
    printf("Diagonal Principal %3i",matriz[0][2]+matriz[1][1]+matriz[2][0]);
    printf("\n");
    printf("Diagonal Secundário %3i",matriz[0][0]+matriz[1][1]+matriz[2][2]);
    printf("\n");
    printf("Resultado da subtração %3i",(matriz[0][2]+matriz[1][1]+matriz[2][0])-(matriz[0][0]+matriz[1][1]+matriz[2][2]));
	return 0;
}
