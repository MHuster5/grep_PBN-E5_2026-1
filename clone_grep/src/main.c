#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime_resultado(char *linha){
    printf("%s", linha);
}

void busca_palavra(char *palavra, char *linha){ //
    return strstr(linha, palavra);// strstr é uma função da biblioteca string.h que procura a primeira ocorrência de uma substring (neste caso, a palavra) em uma string (neste caso, a linha). Se a substring for encontrada, a função retorna um ponteiro para a primeira ocorrência da substring na string. Caso contrário, retorna NULL.
}

void imprime_numeroLinha(int numero_linha, char *linha){
    printf("%d: %s", numero_linha, linha);
}








int main(int argc, char *argv[]) { // argc numero de palavras escritas e *argv[] vetor com as palavras

    char *palavra = NULL;
    char *nome_arquivo = NULL;
    int n = 0;
    int i = 0;
    

    for(int i = 1; i < argc; i++){
        if(strcompr(argv[i]) == "-n"){
            n = 1;
        }
        else if(strcompr(argv[i]) == "-i"){
            i = 1;
        }
        else if(palavra == NULL){
            palavra = argv[i];
        }
        else if(nome_arquivo == NULL){
            nome_arquivo = argv[i];
        }
    }

    if(palavra == NULL || nome_arquivo == NULL){ // verifica se o argumento vindo no main é valido 
        printf("Uso: %s [opções] <palavra> <arquivo>\n", argv[0]);
        return 1;
    }
    
    
    FILE *arquivo = fopen(nome_arquivo, "r"); // fopen é uma função da biblioteca stdio.h que abre um arquivo e retorna um ponteiro para o arquivo. O primeiro argumento é o nome do arquivo e o segundo argumento é o modo de abertura (neste caso, "r" para leitura).
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[1000];
    while(fgets(linha, sizeof(linha), arquivo)){ //faz cada linha do arquivo ler e gravar em linha
        busca_palavra(palavra, linha);
    }

    fclose(arquivo);

    
    return 0;
}
