#include <stdio.h>
#include <ctype.h>
#define clearbuffer(x)  while (((x) = getchar())!= '\n');

void UserInput(char a, int b);
void PrintMatrix(void);
int WinCondition(void);
char matrix[4][4] = { {' ','1','2','3'}, 
                        {'A','-','-','-'},
                        {'B','-','-','-'},
                        {'C','-','-','-'}};
int f = 0; 

int main(void){
    int a, b, x;
    do{
        PrintMatrix();
        printf("Donde quiere jugar, indicar con coordenadas: \n");
        a = getchar();
        b = getchar();
        clearbuffer(x)
        UserInput(a,b);
    }while(WinCondition());
    PrintMatrix();
    return 0;
}

void PrintMatrix(void){
    int i, j;
    for (i = 0; i <4; i++){
        for(j=0; j< 4; j++){
            printf(" %c", matrix[i][j]);
        }
        putchar('\n');
    }
}

void UserInput(char a, int b){
    a = toupper(a);
    if( (a < 'A' || 'C' < a ) && (b < '1' || '3'< b)){
        printf("Jugada Invalida\n");
    } else{
    int fila = a - 64; 
    int column = b - '0';
    if (f == 0){
        matrix[fila][column]= 'X';
        f = 1; 
    }else{
        matrix[fila][column]= 'O';
        f = 0;
    }
    }
}

int WinCondition(void){
    int i, j;
    //win condition horizontal
    for(i = 0; i < 4;i++ ){
        if(matrix[i][1]== matrix[i][2] && matrix[i][2]== matrix[i][3] && matrix[i][1] != '-'){
            printf("%c es el ganador\n", matrix[i][1]);
            return 0;
        }
    }

    //win condition vertical
    for(j = 0; j < 4;j++ ){
        if(matrix[1][j]== matrix[2][j] && matrix[2][j]== matrix[3][j]&& matrix[1][j] != '-'){
            printf("%c es el ganador\n", matrix[1][j]);
            return 0;
        }
    }

    //win condition diagonal
    if (matrix[1][1]== matrix[2][2] && matrix[2][2] == matrix[3][3] && matrix[1][1] != '-'){
        printf("%c es el ganador\n", matrix[1][1]);
        return 0;
    } else if (matrix[1][3]==matrix[2][2] && matrix[2][2] == matrix[3][1] && matrix[3][1] != '-'){
        printf("%c es el ganador\n", matrix[3][1]);
         return 0;
    }
    return 1;
}

