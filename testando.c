    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

//funcao que recebe a entrada e armazena numa struct livro
void colocapalavra(VetorPalavras *p){
    char letra = 0;
    int pos = 0;
    char auxiliar = (char) malloc(sizeof(char));

    //recebe os caracteres e vai colocando na regiao apontada pelo ponteiro nomeaux
    while(letra != '\n'){
        letra = getchar();
            auxiliar = realloc(auxiliar, (pos+1)*sizeof(char));
            auxiliar[pos++] = letra;   
    }
    nomeaux[--pos] = '\0';

    //passa o end alocado pelo nomeaux para o p->nome da struct atual
    p->nome = nomeaux;
    nomeaux = NULL;

    scanf("%f", &p->valor);
}