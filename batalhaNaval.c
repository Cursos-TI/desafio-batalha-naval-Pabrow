#include <stdio.h>

int main(){
    int tabuleiro[10][10]={//tabuleiro de 10x10 inicializado com zeros
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
    };

    int areaCone[10][10]={//área do cone
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
    };

    int areaCruz[10][10]={//área do cruz
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
    };

    int areaOctaedro[10][10]={//área do octaedro
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
    };

    int navios[3][6]={ //array declarando ONDE vai ficar o navio, as duas primeiras varíaveis são as coordenadas iniciais e a as duas ultimas são as coordenadas finais.
        {2, 3, 3, 3, 4, 3},
        {9, 2, 9, 3, 9, 4},
        {6, 1, 7, 2, 8, 3}
    };
    
    int cone[2]={4,0};//ponto central da habilidade cone -> 1 pra cima, 1 pra cada lado e 5 pra baixo
    int cruz[2]={5,5};//ponto central da habilidade cruz -> 2 pra cima, 2 pra baixo, 2 pra cada lado
    int octaedro[2]={7,8};//ponto central da habilidade octaedro -> 1 pra cima, 1 pra baixo e 1 pra cada lado

    //botador de navios no tabuleiro
    //fazer um FOR que vai rodar a quantidade de linhas do array navios(ou seja, quantidade de navios) e vai colocar o valor 3 no tabuleiro na posição do navio, para indicar que tem um navio naquela posição
    int tamanho = sizeof(navios) / sizeof(navios[0]);
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<6;j+=2){
            if(tabuleiro[navios[i][j]][navios[i][j+1]]==0){
                tabuleiro[navios[i][j]][navios[i][j+1]]=3;                
            }else{
                printf("Erro: posição (%d, %d) já ocupada por outro navio ou fora do tabuleiro.\n", navios[i][j], navios[i][j+1]);              
                return 1;   
            }
        }
    }

    printf("%s \n", areaCone[cone[0]][cone[1]]== 0 ? "5" : "0");
    
    //setando o cone:
    areaCone[cone[0]][cone[1]]=areaCone[cone[0]][cone[1]]== 0 ? 5 : 0;
    areaCone[cone[0]-1][cone[1]]=areaCone[cone[0]-1][cone[1]]== 0 ? 5 : 0;
    areaCone[cone[0]][cone[1]-1]=areaCone[cone[0]][cone[1]-1]== 0 ? 5 : 0;
    areaCone[cone[0]][cone[1]+1]=areaCone[cone[0]][cone[1]+1]==0 ? 5 : 0;
    areaCone[cone[0]+1][cone[1]]=areaCone[cone[0]+1][cone[1]]== 0 ? 5 : 0;
    areaCone[cone[0]+1][cone[1]-1]=areaCone[cone[0]+1][cone[1]-1]== 0 ? 5 : 0;
    areaCone[cone[0]+1][cone[1]+1]=areaCone[cone[0]+1][cone[1]+1]== 0 ? 5 : 0;
    areaCone[cone[0]+1][cone[1]-2]=areaCone[cone[0]+1][cone[1]-2]== 0 ? 5 : 0;
    areaCone[cone[0]+1][cone[1]+2]=areaCone[cone[0]+1][cone[1]+2]== 0 ? 5 : 0;

    //setando a cruz:
    areaCruz[cruz[0]][cruz[1]]=6;
    areaCruz[cruz[0]-2][cruz[1]]=6;
    areaCruz[cruz[0]-1][cruz[1]]=6;
    areaCruz[cruz[0]+1][cruz[1]]=6;
    areaCruz[cruz[0]+2][cruz[1]]=6;
    areaCruz[cruz[0]][cruz[1]-1]=6;
    areaCruz[cruz[0]][cruz[1]+1]=6;
    areaCruz[cruz[0]][cruz[1]-2]=6;
    areaCruz[cruz[0]][cruz[1]+2]=6;

    //setando o octaedro:
    areaOctaedro[octaedro[0]][octaedro[1]]=7;
    areaOctaedro[octaedro[0]][octaedro[1]+1]=7;
    areaOctaedro[octaedro[0]][octaedro[1]-1]=7;
    areaOctaedro[octaedro[0]-1][octaedro[1]]=7;    
    areaOctaedro[octaedro[0]+1][octaedro[1]]=7;    

    //botador de habilidades no tabuleiro
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(areaCone[i][j]==5){
                tabuleiro[i][j]=5;
            }
            if(areaCruz[i][j]==6){
                tabuleiro[i][j]=6;
            }
            if(areaOctaedro[i][j]==7){
                tabuleiro[i][j]=7;
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
                    printf("%d ", tabuleiro[i][j]);                    
                }
            }            
        }
        printf("\n");//dá o espaçamento necessário entre as linhas do tabuleiro
    }
}