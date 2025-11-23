#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void preencherMat (int **mat,int linha, int coluna);
void mostrarMat (int **mat,int linha,int coluna); 
void zerarDiagonalPrincipal (int **mat, int linha,int coluna);

int main(){
    srand(time(NULL));
    int linhas, colunas; 
    printf("informe a quantidade de linhas e colunas da matriz:"); 
    scanf("%d %d",&linhas,&colunas);

    int **matriz = (int **)malloc (linhas*sizeof(int*));
    if(matriz == NULL){
        printf("erro de alocacao das linhas");
    }
    
    for(int i =0; i< linhas; i++){
        *(matriz + i) = malloc(colunas * sizeof(int));
        if ( *(matriz + i) == NULL){
            printf("erro de alocacao das colunas");
        }
    }

    printf("Matriz:\n");
    preencherMat(matriz,linhas,colunas);
    mostrarMat(matriz,linhas,colunas);
    zerarDiagonalPrincipal(matriz,linhas,colunas);

    return 0;
}

void preencherMat (int **mat,int linha, int coluna){
    for(int i =0; i< linha; i++){
        for(int j =0; j< coluna; j++){
           *(*(mat + i) + j)= rand() % 10;
        }
    }
}

void mostrarMat (int **mat,int linha,int coluna){
    for(int i =0; i< linha; i++){
        for(int j =0; j< coluna; j++){
            printf("%d ",*(*(mat + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void zerarDiagonalPrincipal (int **mat, int linha,int coluna){
    printf("Matriz com a diagonal principal zerada:\n");
    for(int i =0; i< linha; i++){
        for(int j=0; j< coluna; j++){
            if(i==j){
                *(*(mat + i) + j)=0;
            }
        }
    }
    mostrarMat(mat,linha,coluna);
}