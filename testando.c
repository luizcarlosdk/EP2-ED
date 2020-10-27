    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

void colocapalavra(palavra *p){
    char letra = 0;
    int pos = 0;
    char auxiliar = (char) malloc(sizeof(char));

    while(letra != '\n'){
        letra = getchar();
            auxiliar = realloc(auxiliar, (pos+1)*sizeof(char));
            auxiliar[pos++] = letra;   
    }
    nomeaux[--pos] = '\0';

    //passa o end alocado pelo nomeaux para o p->nome da struct atual
    p->palavra = auxiliar;

    free(auxiliar)
    //auxiliar = NULL;
}