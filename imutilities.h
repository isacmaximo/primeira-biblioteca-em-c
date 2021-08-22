#ifndef IMUTILITIES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define IMUTILITIES_H

//cores das letras
#define VERMELHO    "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define AMARELO "\x1b[33m"
#define CIANO   "\x1b[36m"
#define MAGENTA "\x1b[35m"
#define BRANCO  "\x1b[37m"
#define CINZA_C  "\x1b[90m"
#define VERMELHO_C   "\x1b[91m"
#define VERDE_C    "\x1b[92m"
#define AMARELO_C "\x1b[93m"
#define CIANO_C   "\x1b[94m"
#define MAGENTA_C "\x1b[95m"
#define BRANCO_C  "\x1b[97m"
#define RESET   "\x1b[0m"


//função que lê arquivos linha por linha
void ler_arq(char *nomearq, int tamlinha){              //recebe o nome do arquivo e o tamanho da linha
    char linha[tamlinha];                               //o tamanho da linha é definida 
    FILE * arq = fopen(nomearq, "r");                   //topo arquivo tem um ponteiro que vai ser aberto em modo leitura
    while(fgets(linha, sizeof(linha), arq) != NULL){    //enquanto tiver conteúdo no arquivo
        printf("%s", linha);                            //printará as strings (conteúdo do arquivo)
    }
    fclose(arq);                                        //fecha o arquivo
}

//função que lê arquivos com cor na letra
void ler_arq_cor(char *nomearq, int tamlinha, char *cor){   //recebe o nome do arquivo, e a cor
    char linha[tamlinha];                                   //linha vai ter o tamanho de tamlinha
    FILE * arq = fopen(nomearq, "r");                       //arquivo que vai ser aberto em modo leitura
    while(fgets(linha, sizeof(linha), arq) != NULL){        //enquanto tiver conteúdo no arquivo
        printf("%s%s%s",cor, linha, RESET);                 //printará as strings com a cor (conteúdo do arquivo)
    }
    fclose(arq);                                            //fecha o arquivo
}

//função que lê arquivos e substitui o símbolo pelo nome do símbolo ou nome definido
void substituir(char *nomearq, int tamlinha, char *caractere, char *substituir){   //recebe o nome do arquivo, tamanho da linha, string a ser substituída, string substituta
    char linha[tamlinha];                                                          //linha vai ter o tamanho de tamlinha 
    char *separador;                                                               //ponteiro para separa o txt em sub strings
    char *substituto; substituto = caractere;                                      //ponteiro substituto que vai receber os caracteres
    FILE * arq = fopen(nomearq, "r");                                              //arquivo que vai ser aberto em modo leitura

    while(fgets(linha, sizeof(linha), arq) != NULL){                               //enquanto tiver conteúdo no arquivo
        
        separador = strtok(linha, " ");                                            //as sub strins serão separadas pelo caractere espaço
        while(separador != NULL){                                                  //enquanto for diferente de nulo
            if (strstr(separador, substituto) != 0){                               //aqui ocorrerá a substituição se o caractere for igual a substring da linha
                separador = substituir;
            }
            printf(" %s", separador);                                              //cada sub string do arquivo será exibido
            fflush(stdout);
            separador = strtok(NULL, " ");
        }
    }
    fclose(arq);                                                                   //fecha o arquivo
}




#endif
