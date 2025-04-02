#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define clrscr() system("clear")
#define clearbuffer(x)  while (((x) = getchar())!= '\n');
#define ConvertInput(a, b) { fila = (a) - 64;\
                            column = (b) - '0';}

void UserInput(char, char);
void PrintMatrix(void);
int WinCondition(void);
int CheckPlayCondition(char, char);
char matrix[4][4] = { {' ','1','2','3'}, 
                        {'A','-','-','-'},
                        {'B','-','-','-'},
                        {'C','-','-','-'}};
int f = 0; 

int main(void){
    int a, b, x;
    do{
        clrscr();
        PrintMatrix();
        printf("Donde quiere jugar, indicar con coordenadas: \n");
        a = getchar();
        b = getchar();
        clearbuffer(x)
        UserInput(a,b);
    }while(WinCondition());
    clrscr();
    WinCondition();
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

int CheckPlayCondition(char a, char b){
    a = toupper(a);
    int fila, column;
    ConvertInput(a, b);
    if ( (a < 'A' || 'C'< a) && (b < '1' || '3'<b)){
        return 0; 
    } else if ( matrix[fila][column] == '-'){
        return 0;
    }
    return 1;
}

void UserInput(char a, char b){
    a = toupper(a);
    int fila, column;
    ConvertInput(a,b)
    if(CheckPlayCondition(a,b)){
        printf("Jugada Invalida\n\n");
    } else{
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
            printf("%c es el ganador\n\n", matrix[i][1]);
            return 0;
        }
    }

    //win condition vertical
    for(j = 0; j < 4;j++ ){
        if(matrix[1][j]== matrix[2][j] && matrix[2][j]== matrix[3][j]&& matrix[1][j] != '-'){
            printf("%c es el ganador\n\n", matrix[1][j]);
            return 0;
        }
    }

    //win condition diagonal
    if (matrix[1][1]== matrix[2][2] && matrix[2][2] == matrix[3][3] && matrix[1][1] != '-'){
        printf("%c es el ganador\n\n", matrix[1][1]);
        return 0;
    } else if (matrix[1][3]==matrix[2][2] && matrix[2][2] == matrix[3][1] && matrix[3][1] != '-'){
        printf("%c es el ganador\n\n", matrix[3][1]);
         return 0;
    }
    return 1;
}

