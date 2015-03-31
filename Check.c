/*
13651. Check

Problem code: KNGCHECK

Chess is a two-player strategy board game played on a chessboard, a square checkered game board with 64 squares arranged in an eight-by-eight grid. It is one of the world's most popular games, played by millions of people worldwide at home, in clubs, online, by correspondence, and in tournaments. Each player begins the game with 16 pieces: one king, one queen, two rooks, two knights, two bishops, and eight pawns. Each of the six piece types moves differently. Pieces are used to attack and capture the opponent's pieces, with the objective to 'checkmate' the opponent's king by placing it under an inescapable threat of capture. In addition to checkmate, the game can be won by the voluntary resignation of the opponent, which typically occurs when too much material is lost, or if checkmate appears unavoidable. A game may also result in a draw in several ways, where neither player wins. The course of the game is divided into three phases: opening, middle game, and endgame. Source Wikipedia

To simplify this problem you will only deal with Kings, Knights and Pawns of the Black and the White Players. Assume that the White Player starts at the lower half of the board and the Black Player starts at the upper half. Given the state of the board, your task is to determine whether the black king is checked or not. For Clarity a 'Check' occurs when the King's square can be attacked by any of the opponent's pieces for his next move, and note that in this problem we will ignore the consequences which will follow, we don’t even care whose turn is now but only consider the board state (out of chess rules).

The Knight moves like an "L", it moves from cell (r1, c1) to cell (r2, c2) if and only if (r1 - r2)2 + (c1-c2)2 = 5 (8 possible moves).

The King can move only one move in its four main directions and its four diagonals (8 possible moves).

The Pawn attacks only one move diagonally and only to the oppenent direction (2 possible moves).

This problem is NOT following all chess rules, for example in real chess third case in the sample is INVALID, so please assume that the given board is always valid, just check the black king state.

 

Input

You are given an 8x8 Board with Chess Pieces denoted as following: BK = Black King, WK = White King, BH = Black Knight, WH = White Knight, BP = Black Pawn, WP = White Pawn. We ensure that there is one and only one Black King in the Chess Board. Blank fields are denoted by “-”. Cases are seperated by blank lines.

Output

You should output “Check” if a Check exists or “Not Check” if no check exists. Follow the output format described in the sample tests.

Example

Input:
3
- - - - - - - -
- - - - - - - -
- - - - - - - -
- BH - - - - - -
- - - BK - - - -
- - WP - - - - -
- - - - - - - -
- - - - - - - -

- - - - - - - -
BH - - BH - - - -
- - - - - - - -
- - - - - - - -
- - - BK - - - -
- - - - - - - -
- WP - - - - WH -
- - - WK - - - -

- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - BK - - - -
- - - WK - - - -
- - - - - - WH -
- - - - - - - -
- WP - - - - WH -Output:
Case #1: Check
Case #2: Not Check
Case #3: Check
*/

#include <stdio.h>
#include <string.h>

struct chessBoard
{
	char character[3];
};


int main()
{
	int testCases, i, j, k;
	int blackKingPosX, blackKingPosY, whiteKingPosX, whiteKingPosY;
	int whiteKnightPosX[64], whiteKnightPosY[64];
	int whitePawnPosX[64], whitePawnPosY[64];
	int numOfWhiteKinghts, numOfWhitePawns;
	int checkFlag = 0;
	int r1, r2, c1, c2, val;

	struct chessBoard cb[8][8];

	scanf("%d",&testCases);

	for(k = 0 ; k < testCases ; k++)
	{
		numOfWhitePawns = numOfWhiteKinghts = 0;
		checkFlag = 0;
		whiteKingPosX = whiteKingPosY = -100;

		for(i = 0 ; i < 8 ; i++)
		{
			for(j = 0 ; j < 8 ; j++)
			{
				scanf("%s",cb[i][j].character);
				
				if(strcmp(cb[i][j].character,"-") != 0)
				{
					if(strcmp(cb[i][j].character,"BK") == 0)
					{
						blackKingPosX = j;
						blackKingPosY = i;	
					}
					else if(strcmp(cb[i][j].character,"WK") == 0)
					{
						whiteKingPosX = j;
						whiteKingPosY = i;
					}
					else if(strcmp(cb[i][j].character,"WP") == 0)
					{
						whitePawnPosX[numOfWhitePawns] = j;
						whitePawnPosY[numOfWhitePawns] = i;
						numOfWhitePawns++;
					}
					else if(strcmp(cb[i][j].character,"WH") == 0)
					{
						whiteKnightPosX[numOfWhiteKinghts] = j;
						whiteKnightPosY[numOfWhiteKinghts] = i;
						numOfWhiteKinghts++;
					}
				}		
			}
		}


		for(i = 0; i < numOfWhitePawns ; i++)
		{
			if(((whitePawnPosX[i] - 1) == blackKingPosX) && ((whitePawnPosY[i] - 1) == blackKingPosY))
			{
				checkFlag = 1;
				break;
			}
			else if(((whitePawnPosX[i] + 1) == blackKingPosX) && ((whitePawnPosY[i] - 1) == blackKingPosY))
			{
				checkFlag = 1;
				break;
			}
		}

		if(checkFlag == 1)
		{
			printf("Case #%d: Check\n",k + 1);
			continue;
		}

		for(i = 0 ; i < numOfWhiteKinghts ; i++)
		{
			r1 = whiteKnightPosX[i];
			c1 = whiteKnightPosY[i];
			r2 = blackKingPosX;
			c2 = blackKingPosY;
			val = ((r1 - r2)*(r1 - r2)) + ((c1 - c2)*(c1 - c2));

			if(val == 5)
			{
				checkFlag = 1;
				break;
			}

		}

		if(checkFlag == 1)
		{
			printf("Case #%d: Check\n",k + 1);
			continue;
		}

		r1 = whiteKingPosX - blackKingPosX;
		c1 = whiteKingPosY - blackKingPosY;

		if(r1 < 0)
			r1 = -1 * r1;
		if(c1 < 0)
			c1 = -1 * c1;

		if(r1 <= 1 && c1 <= 1)
			checkFlag = 1;

		if(checkFlag == 1)
		{
			printf("Case #%d: Check\n",k + 1);
			continue;
		}

		printf("Case #%d: Not Check\n",k + 1);

	}

	return 0;
}