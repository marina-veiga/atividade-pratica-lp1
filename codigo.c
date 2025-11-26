#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

// protótipos das funções 
void preencherMat (int **mat,int linha, int coluna);
void mostrarMat (int **mat,int linha,int coluna); 
void zerarDiagonalPrincipal (int **mat, int linha,int coluna);
void somaElementos(int linha, int colunas, int **mat);

int main(){
    srand(time(NULL)); // inicia o gerador de números aleatórios
    int linhas, colunas; 
    printf("informe a quantidade de linhas e colunas da matriz:"); 
    scanf("%d %d",&linhas,&colunas);

    // alocação da matriz de forma dinâmica
    // primeiro, aloco o vetor de linhas (cada linha é um ponteiro para inteiros)
    int **matriz = (int **)malloc (linhas*sizeof(int*));  
    if(matriz == NULL){
        printf("erro de alocacao das linhas");
        return 1;
    }
    
    // para cada linha, aloco um vetor de inteiros (as colunas)
    for(int i =0; i< linhas; i++){
        *(matriz + i) = malloc(colunas * sizeof(int));
        if ( *(matriz + i) == NULL){
            printf("erro de alocacao das colunas");
            return 1;
        }
    }

    printf("\nMatriz:\n");
    preencherMat(matriz,linhas,colunas); // preenche a matriz com números aleatórios
    mostrarMat(matriz,linhas,colunas); // mostra a matriz na tela
    somaElementos(linhas,colunas,matriz); // soma os elementos de cada linha
    zerarDiagonalPrincipal(matriz,linhas,colunas); // zera a diagonal principal e mostra o resultado

    // liberação da memória
    // primeiro a liberação de cada linha
    for(int i =0; i< linhas; i++){
        free(*(matriz+i));  
    }

    free(matriz); // libera o vetor de ponteiros

    return 0;
}

// função que preenche toda a matriz com números aleatórios de 0 a 9
void preencherMat (int **mat,int linha, int coluna){
    for(int i =0; i< linha; i++){ 
        for(int j =0; j< coluna; j++){
           *(*(mat + i) + j)= rand() % 10; //coloca um número aleatório de 0 a 9 na posição (i,j) da matriz
        }
    }
}

// função que imprime a matriz na tela de forma simples
void mostrarMat (int **mat,int linha,int coluna){
    for(int i =0; i< linha; i++){
        for(int j =0; j< coluna; j++){
            printf("%d ",*(*(mat + i) + j)); // imprime o valor da posição (i,j) da matriz
        }
        printf("\n");
    }
    printf("\n");
}

// função que zera os elementos da diagonal principal.
void zerarDiagonalPrincipal (int **mat, int linha,int coluna){
    printf("Matriz com a diagonal principal zerada:\n");
    for(int i =0; i< linha; i++){
        for(int j=0; j< coluna; j++){
            if(i==j){
                *(*(mat + i) + j)=0; // zera o elemento (i,j)
            }
        }
    }
    mostrarMat(mat,linha,coluna); // mostra o resultado final
}

// soma os elementos de cada linha e imprime a soma.
void somaElementos(int linha, int colunas, int **mat){
    int i, j;
    for(i =0; i< linha;i++){
        int soma =0; // reinicia a soma para cada linha
        for(j =0; j<colunas;j++){
            soma += *(*(mat + i)+j); // somando o valor da posição atual
        }
      printf("A soma da linha %d eh %d\n",i,soma);
    } 
    printf("\n");
}