/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-18.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun May 17 03:28:03 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

// (a)
enum Piece {empty,PAWN,ROOK,KNIGHT,BISHOP,QUEEN,KING};
enum Color {WHITE,BLACK};

// (b)
struct Square {
	enum Piece piece;
	enum Color color;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	// (c), (d)
	struct Square board[8][8] =

	// Board is turned sidways!
	// A little messy, but this was the only way to do without using subscripting ([0][0].piece, [0][0].color), so imo it's cleaner
	//V ROW  COL -->0              1              2              3              4              5             6               7
	/*0 a*/{{{ROOK  , BLACK}, {PAWN,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {PAWN,WHITE}, {ROOK  ,WHITE}},
	/*1 b*/	{{KNIGHT, BLACK}, {PAWN,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {PAWN,WHITE}, {KNIGHT,WHITE}},
	/*2 c*/	{{BISHOP, BLACK}, {PAWN,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {PAWN,WHITE}, {BISHOP,WHITE}},
	/*3 d*/	{{QUEEN , BLACK}, {PAWN,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {PAWN,WHITE}, {QUEEN ,WHITE}},
	/*4 e*/	{{KING  , BLACK}, {PAWN,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {PAWN,WHITE}, {KING  ,WHITE}},
	/*5 f*/	{{BISHOP, BLACK}, {PAWN,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {PAWN,WHITE}, {BISHOP,WHITE}},
	/*6 g*/	{{KNIGHT, BLACK}, {PAWN,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {PAWN,WHITE}, {KNIGHT,WHITE}},
	/*7 h*/	{{ROOK  , BLACK}, {PAWN,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {empty,BLACK}, {PAWN,WHITE}, {ROOK  ,WHITE}}};

	printf("\n-------------------EXERCISE 16-18------------------\n");
	printf("      TESTING    \n");
	printf("Should print queen (5) | black (1):\n");
	printf("Board 3,0 - piece: %d | color: %d\n\n", board[3][0].piece, board[3][0].color);

	printf("Should print queen (5) | white (0):\n");
	printf("Board 3,7 - piece: %d | color: %d\n\n", board[3][7].piece, board[3][7].color);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*
 *   BOARD LAYOUT
 *
 *   a b c d e f g h
 *   0 1 2 3 4 5 6 7
 * 0 r n b q k b n r
 * 1 p p p p p p p p
 * 2 . . . . . . . .
 * 3 . . . . . . . .
 * 4 . . . . . . . .
 * 5 . . . . . . . .
 * 6 P P P P P P P P
 * 7 R N B Q K B N R
 *
 ******************/
