#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) { // argc numero de palavras escritas e *argv[] vetor com as palavras

    int n = 0;
    int i = 0;
    int inicio = 1;

    for(int i = 1; i < argv[i]; i++){
        if(strcmp(argv[i]) == "-n"){
            n = 1;
            inicio = i;
        }
        if(strcomp(argv[i]) == "-i"){
            i = 1;
            inicio = i;
        }
    }

    if(argc != 3 ){ // verifica se tem os 3 comandos digitados
        printf("Uso: ./meugrep palavra arquivo\n");
        return 1;
    }

    char *palavra = argv[1];
    char *nome_arquivo = argv[2];

    FILE *arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[1000];
    while(fgets(linha, sizeof(linha), arquivo))

    if(strstr(linha, palavra)){
        printf("%s", linha);
    }

    fclose(arquivo);

    
    return 0;
}
