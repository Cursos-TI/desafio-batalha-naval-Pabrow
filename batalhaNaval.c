#include <stdio.h>

int main(){
    int tabuleiro[10][10]={
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };//tabuleiro de 10x10 inicializado com zeros

    int navios[3][6]={ 
        {2, 3, 3, 3, 4, 3},
        {9, 1, 9, 2, 9, 3},
        {7, 1, 8, 1, 9, 1}
    };//array declarando ONDE vai ficar o navio, as duas primeiras varíaveis são as coordenadas iniciais e a as duas ultimas são as coordenadas finais.

    //botador de navios no tabuleiro
    //fazer um FOR que vai rodar a quantidade de linhas do array navios(ou seja, quantidade de navios) e vai colocar o valor 3 no tabuleiro na posição do navio, para indicar que tem um navio naquela posição
    
    int tamanho = sizeof(navios) / sizeof(navios[0]);
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<6;j+=2){
            if(tabuleiro[navios[i][j]][navios[i][j+1]]==0){
                tabuleiro[navios[i][j]][navios[i][j+1]]=3;                
            }else{
                printf("Erro: posição (%d, %d) já ocupada por outro navio.\n", navios[i][j], navios[i][j+1]);
              
                return 1;
            }
        }
    }

    char letras[10]={'A','B','C','D','E','F','G','H','I','J'};//array de letras para printar o tabuleiro

    for(int i=-1; i<10; i++){//impressora de tabuleiro
        for(int j=-1; j<10; j++){
            if(i==-1){//percorre a primeira linha do tabuleiro, que é a linha das letras
                if(j==-1){
                    printf("   ");
                }else{
                    printf("%c ", letras[j]);
                }                
            }else{
                if(j==-1){//percorre a primeira coluna do tabuleiro, que é a coluna dos números
                    if(i==-1){
                        printf("  ");
                    }else if(i==9){
                        printf("%d ", i+1);
                    }else{
                        printf(" %d ", i+1);
                    }
                }else{//percorre o restante do tabuleiro, preenchendo com 0 ou 3 dependendo se tem navio na posição
                    if(tabuleiro[i][j]==0){
                        printf("0 ");
                    }else{
                        printf("3 ");
                    }
                }
            }            
        }
        printf("\n");//dá o espaçamento necessário entre as linhas do tabuleiro
    }
}