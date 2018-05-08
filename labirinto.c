/****
* Título:Labirinto Do Minotauro

* Autor:Gabriel Santos De Souza

* Data de Criação:19/06/2016

* Última modificação: 26/07/2016

* Descrição: Programa que encontra um caminho que leve o guerreiro de uma posição inicial
qualquer a uma saída do labirinto, caso exista, se durante o percurso o guerreiro encontra o Minotauro
a caminhada termina com a morte do guerreiro.

* Entrada: Como entrada um arquivo texto que na primeira linha contem a posição inicial do guerreiro no
 labirinto (lg, cg), na segunda linha a posição do Minotauro (lm, cm), na terceira a dimensão do labirinto n,
 e logo a matriz de inteiros com a estrutura do labirinto.

* Saída: Um arquivo de saída mostrando o percurso realizado (todos os passos do guerreiro e do minotauro), o caminho até a saída, ou
uma mensagem informando que o caminho não existe, ou que o guerreiro morreu.

****/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
   int lm,cm;
}Minotauro; /*Coordenadas do minotauro */

typedef struct{
   int lg,cg;
}Guerreiro; /*Coordenadas do guerreiro */

/****
* Título: Apresenta

* Autor: Gabriel Santos

* Data de Criação: 26/07/2016

* Última modificação: 27/07/2016

* Descrição: função responsavel por apresentar a interface de usuario.

* Parâmetros:
   int **: matriz(labirinto).
   Minotauro: Coordenadas do Minotauro.
   Guerreiro: Coordenadas do Guerreiro.
   const int: Dimensão da matriz.

* Valor de retorno: A função retorna a matriz alocada.

****/
void Apresenta(int**, const int, Minotauro*, Guerreiro* );

/****
* Título: Aloca_Matriz

* Autor: Gabriel Santos

* Data de Criação: 19/06/2016

* Última modificação: 19/06/2016

* Descrição: função responsavel por alocar a matriz dinamicamente.

* Parâmetros:
   const int : é a dimensão da matriz.

* Valor de retorno: A função retorna a matriz alocada.

****/
int** Aloca_Matriz(const int);

/****
*
* Título: Le_Matriz
*
* Autor: Gabriel Santos

* Data de Criação:  19/06/2016
* Última modificação:  19/06/2016

* Descrição: A função lê e verifica o número de discos a serem usados para resolver o problema em questão.

* Parâmetros:
   (entrada/saída)
           FILE:   É um ponteiro que aponta aqruivo.
           int**: labirinto.
           int: tamanho no labirinto.

* Valor de retorno: void.
****/
void Le_Matriz(FILE * ,int**,int );

/****
*
* Título: Imprimir_Labirinto

* Autor: Gabriel Santos

* Data de Criação:  19/06/2016
* Última modificação:  19/06/2016

* Descrição: A função imprimi o labirinto com seu caracteres especiais.

* Parâmetros:
   (entrada/saída)
           int**: Matriz (labirinto).
           const int: tamanho da matriz.

* Valor de retorno: void.

****/
void Imprimir_Labirinto(int**,const int);


/****
*
* Título: Mov_Guerreiro
*
* Autor: Gabriel Santos

* Data de Criação: 12/07/2016
* Última modificação:25/07/2016

* Descrição: A função fica encarregada dos movimentos do guerreiro quando chamada.

* Parâmetros:
   (entrada/saída)
           int**: matriz.
           int: tamanho da matriz.
           Guerreiro *: coordenadas do guerreiro.

* Valor de retorno: void.
*
****/
void Mov_Guerreiro(int** ,const int ,Guerreiro *);

/****
*
* Título: Mov_Minotauro
*
* Autor: Gabriel Santos

* Data de Criação:  19/06/2016
* Última modificação:  19/06/2016

* Descrição: A função fica encarregada de movimentar o minotauro quando chamada.

* Parâmetros:
   (entrada/saída)
           int **: matriz.
           const int: tamanho da matriz.
           Minotauro *: coordenadas do minotauro.

* Valor de retorno: void.
*
****/
void Mov_Minotauro(int** ,const int ,Minotauro *);


/****
*
* Título: Mov_PasAnter
*
* Autor: Gabriel Santos

* Data de Criação: 25/07/2016
* Última modificação:26/07/2016

* Descrição: função responsavel pelo retorno do guerreiro caso, não tenha mais caminho livre.


* Parâmetros:
   (entrada/saída)
           int **: matriz.
           const int: tamanho da matriz.
           Minotauro *: coordenadas do guerreiro.

* Valor de retorno: void.
****/
void Mov_PasAnter(int**,const int,Guerreiro*);

/****
*
* Título: Liberar_Memoria
*
* Autor: Gabriel Santos
*
* Data de Criação: 19/07/2016
* Última modificação: 19/07/2016
*
* Descrição: Libera uma matriz alocada dinamicamente.
*
* Parâmetros:
*   (entrada)
*           int **: Ponteiro que aponta para a matriz que foi alocada e definida na função Liberar_Memoria.
*           const int: tamanho da matriz.
*
* Valor de retorno: void.
*
****/
void Liberar_Memoria(int**,const int);

/****
*
* Título: Gravar_arquivo
*
* Autor: Gabriel Santos
*
* Data de Criação:
* Última modificação:
*
* Descrição: Grava no arquivo de saida, o resultado do jogo.
*
* Parâmetros:
*   (entrada)
*           int**: matriz.
           const int tamanho da matriz.
*
* Valor de retorno: void.
*
****/
void Gravar_arquivo(int**,const int );

int main()
{
    setlocale(LC_ALL, "Portuguese"); //para o uso de acentos
    Guerreiro g; /*variavel para manipular as coordenadas do guerreiro*/
    Minotauro m; /*variavel para manipular as coordenadas do guerreiro*/
    int n,i,j,**labirinto;
    FILE *arquivo; //arquivo texto

    if((arquivo = fopen("labirinto.txt", "r")) == NULL){//cria arquivo para ler e verifica
        printf("erro ao abrir o arquivo");
        return -1;
        }
    fscanf(arquivo,"%d %d", &g.lg, &g.cg); //Lendo as coordenadas iniciais do guerreiro
    fscanf(arquivo,"%d %d", &m.lm, &m.cm); //Lendo as coordenadas iniciais do minotauro
    fscanf(arquivo,"%d", &n); //Lendo a dimensão do labirinto
    //construção do labirinto
    labirinto = Aloca_Matriz(n);
    Le_Matriz(arquivo, labirinto, n);
    fclose(arquivo);

    //DEFININDO A POSIÇÃO DO MINOTAURO E GUERREIRO
    labirinto[g.lg][g.cg] = 3; /*Guerreiro*/
    labirinto[m.lm][m.cm] = 2; /*Minotauro*/
    //A SAIDA É REPRESENTADA COMO 8 NA MATRIZ
    Apresenta(labirinto,n,&m,&g);
    while(g.cg < n || g.lg < n ){
         //VERIFICAR SE O GUERREIRO ENCONTROU A SAIDA
         if(labirinto[g.lg+1][g.cg] == 8 || labirinto[g.lg][g.cg+1] == 8 || labirinto[g.lg][g.cg-1] == 8 || labirinto[g.lg-1][g.cg] == 8){
                printf("O GUERREIRO ENCONTROU A SAIDA!!");
                return -1;
                }
         //Se não houver mais caminho livre
         if(labirinto[g.lg+1][g.cg] != 1 && labirinto[g.lg][g.cg+1] != 1 && labirinto[g.lg][g.cg-1] != 1 && labirinto[g.lg-1][g.cg] != 1){

             if(labirinto[g.lg+1][g.cg] == 2 || labirinto[g.lg][g.cg+1] == 2 || labirinto[g.lg][g.cg-1] == 2 || labirinto[g.lg-1][g.cg] == 2){
                printf("\nGUERREIRO MORREU");
                return -1;
                }//guerreiro morre ao encontar o minotauro
             else if(labirinto[g.lg+1][g.cg] == 4  || labirinto[g.lg][g.cg+1] == 4 || labirinto[g.lg][g.cg-1] == 4 || labirinto[g.lg-1][g.cg] == 4)
                Mov_PasAnter(labirinto, n, &g);
             else{
                printf("LABIRINTO SEM SAIDA");
                return -1;
                }
            }/*Fim do if*/

        /*controle dos movimentos do guerreiro e minotauro */
        else{
            Mov_Guerreiro(labirinto, n, &g);
            Mov_Guerreiro(labirinto, n, &g);
            Mov_Minotauro(labirinto, n, &m);
            }
        }/*Fim do while*/
    Liberar_Memoria(labirinto, n);
    system("pause");
    return 0;
}/*Fim da main*/

void Apresenta(int **labirinto , const int n,Minotauro *m, Guerreiro*g ){
     printf("********************LABIRINTO DO MINOTAURO************************\n");
     printf("Bem-Vindo ao programa labirinto do minotauro\n");
     printf("\nImforções: \n  O programa labirinto do minotauro, encontra um caminho que leve um guerreiro\n"
             "de uma posição inicial a uma saída do labirinto, caso exista.\n"
             "  Uma saída é uma posição livre na borda da matriz que define o labirinto,\n"
             "se durante o percurso o guerreiro encontra o Minotauro"
             " a caminhada termina\ncom a morte do guerreiro.\n O labirinto é composto por:\n @ -> Guerreiro \n & -> Minotauro \n + -> Parede\n");
     printf("Lg:  %d  Cg: %d\n", g->lg + 1, g->cg + 1); /*Posição inicial do guerreiro*/
     printf("Lm:  %d  Cm: %d\n", m->lm + 1, m->cm + 1);/*Posição inicial do  minotauro*/
     printf("Dimensão: %d\n",n);
     printf("Precione qualquer tecla para iniciar a jornada do guerreiro\n");
     system("pause");
}

//FUNÇÃO RESPONSÁVEL POR ALOCAR DINAMICAMENTE A MATRIZ
int** Aloca_Matriz(const int n){
    int i, **matriz;
    matriz = malloc( n * sizeof( int*));
    if(matriz == NULL){
        printf("ERRO DE ALOCACAO");
        exit(-1);
    }
    for(i = 0 ; i < n; i++){
        matriz[i] = malloc( n * sizeof(int));
        if(matriz[i] == NULL){
            printf("ERRO DE ALOCACAO");
            exit(-1);
        }
    }
    return matriz;
}/*Fim da função*/

void Le_Matriz( FILE *arquivo, int **labirinto, int n ){
  int i, j;
  for( i = 0; i < n; i++)
    for(j = 0; j < n; j++)
       fscanf(arquivo, "%d", &labirinto[i][j]);
  fclose(arquivo);
}
//IMPRIMIR LABIRINTO
void Imprimir_Labirinto( int **matriz, const int n){
    int i,j;
     system("CLS");
     char c;
      for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
          if(matriz[i][j] == 1) c = ' ';  /*CAMINHO LIVRE*/
          else if(matriz[i][j] == 0) c = '+'; /*PAREDE*/
          else if(matriz[i][j] == 3) c = '@'; /*GUERREIRO*/
          else if(matriz[i][j] == 4) c = ' '; /*SOMBRA GUERREIRO*/
          else if(matriz[i][j] == 8) c = ' ';/*SAIDA*/
          else if(matriz[i][j]== 2) c = '&'; /*MINOTAURO*/

       printf(" %c", c);
      }
      printf("\n");
      }
      printf("\n");/*
      for(i=0;i<n;i++){
        for(j=0;j<n;j++)
          printf(" %d",matriz[i][j]);
        printf("\n");
    }
    printf("\n");*/
}/*Fim da função*/

//MOVIMENTOS DO GUERREIRO
void Mov_Guerreiro(int **labirinto , int n, Guerreiro *g ){
        //*****************MOVER GUERREIRO**********************

        //MOVER PARA BAIXO
        if(g->lg + 1 < n && labirinto[g->lg + 1][g->cg] == 1){
                labirinto[g->lg + 1][g->cg] = 3;
                labirinto[g->lg][g->cg] = 4;
                Imprimir_Labirinto(labirinto,n);
                g->lg++;
            }
        //MOVER PARA DIREITA
        else if(g->cg + 1 < n && labirinto[g->lg][g->cg + 1] == 1){
            labirinto[g->lg][g->cg + 1] = 3;
            labirinto[g->lg][g->cg] = 4;
            Imprimir_Labirinto(labirinto, n);
            g->cg++;

            }

         //MOVER PARA CIMA
        else if(g->lg - 1 >= 0 && labirinto[g->lg - 1][g->cg] == 1){
                labirinto[g->lg - 1][g->cg] = 3;
                labirinto[g->lg][g->cg] = 4;
                Imprimir_Labirinto(labirinto,n);
                g->lg--;

            }

            //MOVER PARA A ESQUERDA
        else if(g->cg - 1 >= 0 && labirinto[g->lg][g->cg - 1] == 1){
            labirinto[g->lg][g->cg - 1] = 3;
            labirinto[g->lg][g->cg] = 4;
            Imprimir_Labirinto(labirinto,n);
            g->cg--;
        }


}/*Fim da função Mov_Guerreiro*/

//função para quando o guerreiro se deparar com a parede
void Mov_PasAnter(int **labirinto , const int n, Guerreiro *g){

        //esquerda
        if(labirinto[g->lg][g->cg-1] == 4){
            labirinto[g->lg][g->cg] = 4;
            labirinto[g->lg][g->cg-1] = 3;
            Imprimir_Labirinto(labirinto, n);
            g->lg--;
        }

        //baixo
         else if(labirinto[g->lg + 1][g->cg] == 4){
            labirinto[g->lg][g->cg] = 4;
            labirinto[g->lg + 1][g->cg] = 3;
            Imprimir_Labirinto(labirinto, n);
            g->lg++;
        }
        //direita
        else if(labirinto[g->lg][g->cg + 1] == 4){
            labirinto[g->lg][g->cg] = 4;
            labirinto[g->lg][g->cg + 1] = 3;
            Imprimir_Labirinto(labirinto,n);
            g->cg++;
        }
        //cima
         else if(labirinto[g->lg - 1][g->cg] == 4){
            labirinto[g->lg][g->cg] = 4;
            labirinto[g->lg - 1][g->cg] = 3;
             Imprimir_Labirinto(labirinto,n);
            g->lg--;
        }

}/*Fim da função*/

//MOVIMENTOS DO MINOTAURO
void Mov_Minotauro(int **labirinto, const int n, Minotauro *m){
//*****************MOVER MINOTAURO**********************

        //MOVER PARA BAIXO
        if(m->lm + 1 < n && labirinto[m->lm+1][m->cm] == 1){
                labirinto[m->lm + 1][m->cm] = 2;
                labirinto[m->lm][m->cm] = 1;
                Imprimir_Labirinto(labirinto, n);
                m->lm++;
            }

    //MOVER PARA DIREITA
        else if(m->cm + 1 < n && labirinto[m->lm][m->cm + 1] == 1){
            labirinto[m->lm][m->cm + 1] = 2;
            labirinto[m->lm][m->cm] = 1;
            Imprimir_Labirinto(labirinto, n);
            m->cm++;

            }

             //MOVER PARA CIMA
        else if(m->lm - 1 >= 0 && labirinto[m->lm - 1][m->cm] == 1){
                labirinto[m->lm - 1][m->cm] = 2;
                labirinto[m->lm][m->cm]= 1;
                Imprimir_Labirinto(labirinto, n);
                m->lm--;

            }

         //MOVER PARA A ESQUERDA
        else if(m->cm - 1 >= 0 && labirinto[m->lm][m->cm - 1] == 1){
            labirinto[m->lm][m->cm - 1] = 2;
            labirinto[m->lm][m->cm] = 1;
            Imprimir_Labirinto(labirinto, n);
            m->cm--;
        }




}/*Fim da função*/
void Gravar_arquivo(int **labirinto, const int n){
     int i,j;
     FILE *arquivSaida;
     //abrir o arquivo
     if((arquivSaida = fopen("saida.txt", "w")) == NULL){
        printf("erro ao abrir o arquivo");
        return -1;
    }
     for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
          fprintf(arquivSaida,"%d ",labirinto[i][j]);
     fprintf(arquivSaida,"\n");
    }
    fclose(arquivSaida);
}/*Fim da função*/

//FUNÇÃO PARA LIBERAR A MEMORIA
void Liberar_Memoria(int **labirinto, const int n){
    int i;
    for(i = 0; i < n; i++)
        free(labirinto[i]);
    free(labirinto);
}


