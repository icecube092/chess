#include <stdio.h>
#include <stdlib.h>
#include "shapes.c"

struct shape (*board)[8];
char side;
int done;

void show_board();
void define_side(int turn);
char validate();

int main(){
    board = malloc(sizeof(struct shape) * 64);
    make_shapes(board);

//    printf("%d", xx);
    for (int turn = 1; turn; turn++){
        int sx = -1;
        int sy = -1;
        int fx = -1;
        int fy = -1;
        done = 0;
        define_side(turn);
        printf("Turn %d. %c move.\n", turn, side);
        while (!done){
            show_board();
            done = validate(&sx, &sy, &fx, &fy);
        }
    }
    free(board);
}

char validate_turn(int sx, int sy, int fx, int fy){
    if (board[sx][sy].color == side && board[fx][fy].color != side){
        switch (board[sx][sy].shapetype){
            case
        }
    }
    return 0;
}

char validate_position(int x, int y){
    if (0 <= x && x <= 7 && 0 <= y && y <= 7){
        return 1;
    }
    return 0;
}

char validate(int sx, int sy, int fx, int fy){
    for (;;){
        printf("Choose your shape row: \n");
        scanf("%d", &sx);
        printf("Choose your shape column: \n");
        scanf("%d", &sy);
        if (validate_position(sx, sy)){
            printf("Choose finish row: \n");
            scanf("%d", &fx);
            printf("Choose finish column: \n");
            scanf("%d", &fy);
            if (validate_position(fx, fy)){
                if (validate_turn(sx, sy, fx, fy)){
                    return 1;
                }
            }
        }
        printf("Wrong position, enter again\n");
    }
}

void define_side(int turn){
    switch (turn % 2){
        case 0:
            side = BLACK;
            break;
        case 1:
            side = WHITE;
    }
}

void show_board(){
    printf("-----------------------------\n");
    for (int r = 0; r < 8; r++){
        printf("%d | ", r);
        for (int n = 0; n < 8; n++){
            printf("%s ", board[r][n].view);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
    printf("  | 0  1  2  3  4  5  6  7  |\n");
}