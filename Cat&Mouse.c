/*
1418. The Cats and the Mouse

Problem code: CATM

In a rectangular field of size n by m squares there is a mouse and two cats. The mouse is the first to make a move, then each of the cats makes a move, then again its the mouse's turn, and so on. In each move both the mouse and the cats can move exactly one square vertically or horizontally. If the mouse is standing at the edge of the field then in its next move it can jump off the field and is saved from the cats. If in the next move one of the cats moves to the field with the mouse then there is no escape for the mouse ... =(

You are to write a program which, knowing the initial positions of mouse and the two cats, will find out if there is any way for the mouse to escape from the cats, assuming of course that each cat will do its best to catch the mouse.
Input

In the first line of input two integers n and m are given, not exceeding 100, where n is the number of rows, and m - the number of columns. The second line contains a number k [k <= 10], which defines the number of test cases for the given field. In the next k lines the initial positions of the mouse and the cats are given. The position in the field is given by two numbers: the first is the number of the row, the second is the number of the column. The first two integers are the coordinates of the mouse, the next four integers are the coordinates of the cats.

Output

You must output k lines with answers for each test case. The answer is YES, if the mouse can escape or NO otherwise.

Example

Input:
5 3
3
2 2 1 1 3 3
2 3 1 3 5 2
3 2 1 2 4 3

Output:
NO
YES
YES
Author: Filimonenkov D.O.


*/

#include <stdio.h>

int main()
{
	int numOfRows, numOfCols, testCases, mouseX, mouseY, cat1X, cat1Y, cat2X, cat2Y, cat1YDiff, cat2YDiff;

	scanf("%d %d %d", &numOfRows, &numOfCols, &testCases);
	while(testCases--)
	{
		scanf("%d %d %d %d %d %d", &mouseX, &mouseY, &cat1X, &cat1Y, &cat2X, &cat2Y);

		if((mouseX >= cat1X && mouseX >= cat2X) || (mouseX < cat1X && mouseX < cat2X) || (mouseY >= cat1Y && mouseY >= cat2Y) || (mouseY < cat1Y && mouseY <cat2Y))
		{
			printf("YES\n");
			continue;
		}
		cat1YDiff = mouseY - cat1Y;
		cat2YDiff = mouseY - cat2Y;
		if(cat1X <= mouseX)
		{
			if(cat1YDiff >= 0)
			{
				cat1X += cat1YDiff;
				mouseY -= cat1YDiff;
				if(cat1X == mouseX && cat1Y == mouseY)
				{
					cat2YDiff *= -1;
					mouseY += cat1YDiff;
					cat2X -= cat2YDiff;
					mouseY += cat2YDiff;
					if(cat2X == mouseX && cat2Y == mouseY)
					{
						printf("NO\n");
						continue;
					}
				}
			}
			else if(cat2YDiff >= 0)
			{
				cat2X += cat2YDiff;
				mouseY -= cat2YDiff;
				if(cat2X == mouseX && cat2Y == mouseY)
				{
					cat1YDiff *= -1;
					mouseY += cat2YDiff;
					cat1X -= cat1YDiff;
					mouseY += cat1YDiff;
					if(cat1X == mouseX && cat1Y == mouseY)
					{
						printf("NO\n");
						continue;
					}
				}
			}
		}
		else if(cat1X > mouseX)
		{
			if(cat1YDiff >= 0)
			{
				cat1X -= cat1YDiff;
				mouseY -= cat1YDiff;
				if(cat1X == mouseX && cat1Y == mouseY)
				{
					cat2YDiff *= -1;
					mouseY += cat1YDiff;
					cat2X += cat2YDiff;
					mouseY += cat2YDiff;
					if(cat2X == mouseX && cat2Y == mouseY)
					{
						printf("NO\n");
						continue;
					}
				}
			}
			else if(cat2YDiff >= 0)
			{
				cat2X -= cat2YDiff;
				mouseY -= cat2YDiff;
				if(cat2X == mouseX && cat2Y == mouseY)
				{
					cat1YDiff *= -1;
					mouseY += cat2YDiff;
					cat1X += cat1YDiff;
					mouseY += cat1YDiff;
					if(cat1X == mouseX && cat1Y == mouseY)
					{
						printf("NO\n");
						continue;
					}
				}
			}	
		}
		printf("YES\n");
	}

	return 0;
}