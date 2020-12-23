#include <stdio.h>
#include <stdlib.h>
#include "shapes.c"


void main(){
    struct shape (*board)[8];
    board = malloc(sizeof(struct shape) * 64);
    make_shapes(board);
    printf("%d %c\n", board[3][7].isalive, board[7][7].color);
    printf("%ld\n", sizeof(board));
}