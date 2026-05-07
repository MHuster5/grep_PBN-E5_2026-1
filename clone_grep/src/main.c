#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int numero_linha;
    int ignorar_case;
    int contar_ocorrencias;
} Opcoes;


void minusculo(char *texto){
    for(int i = 0; texto[i]; i++){
        texto[i] = tolower(texto[i]);
    }
}

void busca (char *palavra, FILE *arquivo, Opcoes opcoes){
    char linha[1000];
    int numero_linha = 1;
    int ocorrencias = 0;

    while(fgets(linha, sizeof(linha), arquivo)){
        int encontrou = 0;

        if(!opcoes.ignorar_case){
            if(strstr(linha, palavra) != NULL){
                encontrou = 1;
            }
        }else{
            char copiaLinha[1000];
            char copiaPalavra[100];

            strcpy(copiaLinha, linha);
            strcpy(copiaPalavra, palavra);

            minusculo(copiaLinha);
            minusculo(copiaPalavra);

            if(strstr(copiaLinha, copiaPalavra) != NULL){
                encontrou = 1;
            }
        }

        if(encontrou){
            if(opcoes.numero_linha){
                printf("%d: %s", numero_linha, linha);
            }
            else if(opcoes.contar_ocorrencias){
                ocorrencias++;
            }
            else{
                printf("%s", linha);
            }
        }

        numero_linha++;
    }
}


int main(int argc, char *argv[]) { // argc numero de palavras escritas e *argv[] vetor com as palavras

    char *palavra = NULL;
    char *nome_arquivo = NULL;
    Opcoes opcoes;
    
    opcoes.numero_linha = 0;
    opcoes.ignorar_case = 0;
    opcoes.contar_ocorrencias = 0;
    
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-n") == 0){
            opcoes.numero_linha = 1;
        }
        else if(strcmp(argv[i], "-i") == 0){
            opcoes.ignorar_case = 1;
        }
        else if(strcmp(argv[i], "-c") == 0){
            opcoes.contar_ocorrencias = 1;
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
    
    busca(palavra, arquivo, opcoes);
    

    fclose(arquivo);

    
    return 0;
}
