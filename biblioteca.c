#include "imutilities.h"

int main(){
    char *texto; texto = "texto.txt";
    char *substituto; substituto = "@@@@";
    char *nome; nome = "Meu Nome";

    ler_arq(texto, 20); //ler arquivo
    printf("\n");
    substituir(texto, 50, substituto, nome); //substitui símbolo do arquivo pelo nome
    printf("\n");
    ler_arq_cor(texto, 50, VERMELHO); //ler arquivo com uma cor de letra

    return 0;
}
