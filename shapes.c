
struct shape{
    char color;  // B(66) or W(87)
    unsigned char isalive;
    char updown;
    char leftright;
    char diag;
//    unsigned char shapetype;
    unsigned char number;
    unsigned char posx; // 1-8
    unsigned char posy; // 1-8
    char *view;
};

const char
    PAWN = 80, // P
    HORSE = 72, // H
    ELEF = 69, // E
    ROOK = 82, // R
    QUEEN = 81, // Q
    KING = 75, // K

    WHITE = 87, // W
    BLACK = 66 // B
;

struct shape
    empty,

    wpawn_1,
    wpawn_2,
    wpawn_3,
    wpawn_4,
    wpawn_5,
    wpawn_6,
    wpawn_7,
    wpawn_8,

    bpawn_1,
    bpawn_2,
    bpawn_3,
    bpawn_4,
    bpawn_5,
    bpawn_6,
    bpawn_7,
    bpawn_8,

    whorse_1,
    whorse_2,

    bhorse_1,
    bhorse_2,

    welef_1,
    welef_2,

    belef_1,
    belef_2,

    wrook_1,
    wrook_2,

    brook_1,
    brook_2,

    wqueen,
    wking,

    bqueen,
    bking;

char *get_view(char color, char shape){
    char *s = malloc(sizeof(char) * 2);
    s[0] = color;
    s[1] = shape;
    return s;
}

void make_pawns(){
    bpawn_1.color = bpawn_2.color = bpawn_3.color = bpawn_4.color = bpawn_5.color = bpawn_6.color = bpawn_7.color = bpawn_8.color = BLACK;
    bpawn_1.updown = bpawn_2.updown = bpawn_3.updown = bpawn_4.updown = bpawn_5.updown = bpawn_6.updown = bpawn_7.updown = bpawn_8.updown = 1;
    bpawn_1.view = bpawn_2.view = bpawn_3.view = bpawn_4.view = bpawn_5.view = bpawn_6.view = bpawn_7.view = bpawn_8.view = get_view(BLACK, PAWN);
    bpawn_1.posy = bpawn_2.posy = bpawn_3.posy = bpawn_4.posy = bpawn_5.posy = bpawn_6.posy = bpawn_7.posy = bpawn_8.posy = 1;

    wpawn_1.color = wpawn_2.color = wpawn_3.color = wpawn_4.color = wpawn_5.color = wpawn_6.color = wpawn_7.color = wpawn_8.color = WHITE;
    wpawn_1.updown = wpawn_2.updown = wpawn_3.updown = wpawn_4.updown = wpawn_5.updown = wpawn_6.updown = wpawn_7.updown = wpawn_8.updown = 1;
    wpawn_1.view = wpawn_2.view = wpawn_3.view = wpawn_4.view = wpawn_5.view = wpawn_6.view = wpawn_7.view = wpawn_8.view = get_view(WHITE, PAWN);

    wpawn_1.posy = wpawn_2.posy = wpawn_3.posy = wpawn_4.posy = wpawn_5.posy = wpawn_6.posy = wpawn_7.posy = wpawn_8.posy = 6;

    bpawn_1.posx = bpawn_1.number = wpawn_1.number = wpawn_1.posx = 0;
    bpawn_2.posx = bpawn_2.number = wpawn_2.number = wpawn_2.posx = 1;
    bpawn_3.posx = bpawn_3.number = wpawn_3.number = wpawn_3.posx = 2;
    bpawn_4.posx = bpawn_4.number = wpawn_4.number = wpawn_4.posx = 3;
    bpawn_5.posx = bpawn_5.number = wpawn_5.number = wpawn_5.posx = 4;
    bpawn_6.posx = bpawn_6.number = wpawn_6.number = wpawn_6.posx = 5;
    bpawn_7.posx = bpawn_7.number = wpawn_7.number = wpawn_7.posx = 6;
    bpawn_8.posx = bpawn_8.number = wpawn_8.number = wpawn_8.posx = 7;

}

void make_elefs(){
    belef_1.color = belef_2.color = BLACK;
    belef_1.updown = belef_2.updown = 8;
    belef_1.leftright = belef_2.leftright = 8;
    belef_1.posy = belef_2.posy = 0;
    belef_1.posx = 0;
    belef_2.posx = 7;
    belef_1.view = belef_2.view = get_view(BLACK, ELEF);

    welef_1.color = welef_2.color = WHITE;
    welef_1.updown = welef_2.updown = 8;
    welef_1.leftright = welef_2.leftright = 8;
    welef_1.posy = welef_2.posy = 7;
    welef_1.posx = 0;
    welef_2.posx = 7;
    welef_1.view = welef_2.view = get_view(WHITE, ELEF);

    belef_1.number = welef_1.number = 0;
    belef_2.number = welef_2.number = 1;
}

void make_rooks(){
    brook_1.color = brook_2.color = BLACK;
    brook_1.diag = brook_2.diag = 8;
    brook_1.posy = brook_2.posy = 0;
    brook_1.posx = 2;
    brook_1.posx = 5;
    brook_1.view = brook_2.view = get_view(BLACK, ROOK);

    wrook_1.color = wrook_2.color = WHITE;
    wrook_1.diag = wrook_2.diag = 8;
    wrook_1.posy = wrook_2.posy = 7;
    wrook_1.posx = 2;
    wrook_1.posx = 5;
    wrook_1.view = wrook_2.view = get_view(WHITE, ROOK);

    brook_1.number = wrook_1.number = 0;
    brook_2.number = wrook_2.number = 1;
}

void make_queens(){
    bqueen.color = BLACK;
    bqueen.view = get_view(BLACK, QUEEN);

    wqueen.color = WHITE;
    wqueen.view = get_view(WHITE, QUEEN);

    bqueen.updown = bqueen.leftright = bqueen.diag = wqueen.updown = wqueen.leftright = wqueen.diag = 8;

}

void make_kings(){
    bking.color = BLACK;
    bking.view = get_view(BLACK, KING);

    wking.color = WHITE;
    wking.view = get_view(WHITE, KING);

    bking.updown = bking.leftright = bking.diag = wking.updown = wking.leftright = wking.diag = 8;
}

void make_shapes(struct shape (*board)[8]){
    make_pawns();
    make_elefs();
    make_rooks();
    make_queens();
    make_kings();
    struct shape b[8][8] = {
        welef_1, whorse_1, wrook_1, wking, wqueen, wrook_2, whorse_2, welef_2,
        wpawn_1, wpawn_2, wpawn_3, wpawn_4, wpawn_5, wpawn_6, wpawn_7, wpawn_8,
        empty, empty, empty, empty, empty, empty, empty, empty,
        empty, empty, empty, empty, empty, empty, empty, empty,
        empty, empty, empty, empty, empty, empty, empty, empty,
        empty, empty, empty, empty, empty, empty, empty, empty,
        bpawn_1, bpawn_2, bpawn_3, bpawn_4, bpawn_5, bpawn_6, bpawn_7, bpawn_8,
        belef_1, bhorse_1, brook_1, bking, bqueen, brook_2, bhorse_2, belef_2,
    };
    for (char row = 0; row < 8; row++){
        for (char col = 0; col < 8; col++){
            board[row][col] = b[row][col];
            if (board[row][col].color){
                board[row][col].isalive = 1;
            }
        }
    }
}