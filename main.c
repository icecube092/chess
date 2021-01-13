#include <stdio.h>
#include <stdlib.h>
#include "shapes.c"

struct shape (*board)[8];
char side;
char direction; // в какую сторону противник
int done;
int turn;

void show_board();
void define_side(int turn);
char validate();

int main(){
    board = malloc(sizeof(struct shape) * 64);
    make_shapes(board);

//    printf("%d", xx);
    for (turn = 1; turn; turn++){
        int sx = -1;  // pos of shape
        int sy = -1;
        int fx = -1;  // pos of destination
        int fy = -1;
        done = 0;  // success turn
        define_side(turn);
        printf("Turn %d. %c move.\n", turn, side);
        while (!done){
            show_board();
            done = validate(&sx, &sy, &fx, &fy);
        }
    }
    free(board);
}
char mod(char m){
    if (m > 0){
        return m;
    } else {
        return -m;
    }
}
// обработка хода
char make_turn(int del, int sx, int sy, int fx, int fy){}
// проверка фигур на пути
char shapes_on_way(int sx, int sy, int fx, int fy){}

char validate_turn(int sx, int sy, int fx, int fy){
    int kill = 0;
    printf("%d%d%d%d\n", sx, sy, fx ,fy);
    if (board[sx][sy].color == side && board[fx][fy].color != side){  // проверка что ставим не на свою фигуру
        switch (board[sx][sy].shapetype){
            case PAWN:
                if (board[fx][fy].shapetype != EMPTY){
                        if (fx - sx != 0 && fy - sy != 0){
                            kill = 1;
                        } else {
                            printf("Pawn can kill only on diag\n");
                            return 0;
                        }
                } else {
                    if (!(fy - sy == 0 && (fx - sx == direction || ((turn == 1 || turn == 2) && fx - sx == 2 * direction)))){
                        printf("Wrong move\n");
                        return 0;
                    }
                }
                break;
            case HORSE:
                if (!((mod(fx - sx) == 2 && mod(fy - sy) == 1) || (mod(fx - sx) == 1 && mod(fy - sy) == 2))){
                    printf("Wrong move\n");
                    return 0;
                } else {
                    if (board[fx][fy].shapetype != EMPTY){
                        kill = 1;
                    }
                }
        }
        make_turn(kill, sx, sy, fx, fy);
        return 1;
    } else {
        printf("Position must be a shape of moving side and destination must not\n");
        return 0;
    }
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
        int scansx = scanf("%d", &sx);
        printf("Choose your shape column: \n");
        int scansy = scanf("%d", &sy);
        if (!scansx || !scansy){
            printf("Position coords must be a numbers\n");
            continue;
        }
        if (validate_position(sx, sy)){
            printf("Choose finish row: \n");
            int scanfx = scanf("%d", &fx);
            printf("Choose finish column: \n");
            int scanfy = scanf("%d", &fy);
            if (!scanfx || !scanfy){
                printf("Destination coords must be a numbers\n");
                continue;
            }
            if (validate_position(fx, fy)){
                if (validate_turn(sx, sy, fx, fy)){
                    return 1;
                }
            } else {
                printf("Wrong destination\n");
            }
        } else{
            printf("Wrong position, enter again\n");
        }
    }
}

void define_side(int turn){
    switch (turn % 2){
        case 0:
            side = BLACK;
            direction = -1;
            break;
        case 1:
            side = WHITE;
            direction = 1;
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