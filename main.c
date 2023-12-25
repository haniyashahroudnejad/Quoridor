#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "board.proje.h"

int up_move=72;
int down_move=80;
int left_move=75;
int right_move=77;
char type_of_movement, move_player;


int check_move(type_of_movement){
    if(type_of_movement==up_move){
        if(board[row1+2][column1]==100||board[row1+2][column1]==2){
            beep(500, 100);
            gotoxy(8, 67);
            setTextColor(42, colorscreen);
            printf("your way is C L O S E D!");
        }
        else if(board[row1+4][column1]==200){
            beep(500, 100);
            gotoxy(8, 67);
            setTextColor(42, colorscreen);
            printf("house is F U L L!");
        }
        else{
            board[row1][column1]=0;
            board[row1+4][column1]=200;
        }
    }
    else if(type_of_movement==down_move){
        if(board[row1-2][column1]==100||board[row1-2][column1]==2){
            beep(500, 100);
            gotoxy(8, 67);
            setTextColor(42, colorscreen);
            printf("your way is C L O S E D!");
        }
        else if(board[row1-4][column1]==200){
            beep(500, 100);
            gotoxy(8, 67);
            setTextColor(42, colorscreen);
            printf("house is F U L L!");
        }
        else{
            board[row1][column1]=0;
            board[row1-4][column1]=200;
        }
    }
    else if(type_of_movement==right_move){
        if(board[row1][column1+2]==100||board[row1][column1+2]==3){
            beep(500, 100);
            gotoxy(8, 67);
            setTextColor(42, colorscreen);
            printf("your way is C L O S E D!");
        }
        else if(board[row1][column1+5]==200){
            beep(500, 100);
            gotoxy(8, 67);
            setTextColor(42, colorscreen);
            printf("house is F U L L!");
        }
        else{
            board[row1][column1]=0;
            board[row1][column1+5]=200;
        }
    }
    else if(type_of_movement==left_move){
        if(board[row1][column1-2]==100||board[row1][column1-2]==3){
            beep(500, 100);
            gotoxy(8, 67);
            setTextColor(42, colorscreen);
            printf("your way is C L O S E D!");
        }
        else if(board[row1][column1+5]==200){
            beep(500, 100);
            gotoxy(8, 67);
            setTextColor(42, colorscreen);
            printf("house is F U L L!");
        }
        else{
            board[row1][column1]=0;
            board[row1][column1+5]=200;

        }
    }
}

int move_player1(){
    int movement;
    gotoxy(3, 67);
    printf("%s is your TURN!", name_player_1[20]);
    gotoxy(5, 67);
    printf("Select your ACTION: 1 = MOVE / 2 = PUTTING STICKS");
    scanf("%d", &movement);
    gotoxy(7, 67);
    if(movement==1){
        printf("BY== v ^ > < ");
        move_player=getch();
        if(move_player!=224) beep(500, 100);
        else type_of_movement=getch();
        if(type_of_movement==up_move){
            check_move();
        }

    }

}




int main(){

    board_game();
    move_player1();






}
