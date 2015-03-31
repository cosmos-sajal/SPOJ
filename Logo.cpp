/*
Imagine a 2D diagram drawn in the following way: Starting at the origin, you’re given a sequence of letters which is entirely made of the following four letters ’U’, ’D’, ’L’,and ’R’.A ’U’ is an instruction for you to move one unit upward and drawing a segment at the same time. Similarly, ’D’ is for moving down, ’L’ for left, and ’R’ for right.

For example, ﬁgure (a) is drawn by giving the sequence ’UURDLL’ while ﬁgure (b) is the result of ’UURRRDLLLLUURRRDDD’ (in both ﬁgures, the starting point is identiﬁed by a small circle.)


While segments are allowed to intersect, they’re not allowed to overlap. In other words, any two segments will have, at most, one point in common. We’re interested in knowing the number of closed polygons, not containing any lines inside, in such diagrams. Figure (a), has only one closed polygon while ﬁgure (b) has three. Write a program to do exactly that.

Input

Your program will be tested on one or more test cases. Each test case is speciﬁed on a separate line. The diagram is speciﬁed using a sequence made entirely of (U|D|L|R) and terminated by the letter ’Q’. All letters are capital letters. None of the segments in a test case will overlap.


The end of test cases is identiﬁed by the letter ’Q’ on a line by itself.

Length of each sequence is smaller than 1000.

Output

For each test case, write the answer on a separate line.

Sample

input
UURDLLQ
UURRRDLLLLUURRRDDDQ
Q

output
1
3

URL : http://www.spoj.com/problems/ANARC05I/
*/

#include <stdio.h>
#include <cstdio>

using namespace std;

bool visited[2002][2002];
int count;

void init()
{
	int i, j;

	for(i = 0 ; i < 2002 ; i++)
		for(j = 0 ; j < 2002 ; j++)
			visited[i][j] = false;
	count = 0;
}

void check(int posx, int posy)
{
	if(visited[posx][posy])
		count++;
	visited[posx][posy] = true;
}

int main()
{
	int i, posx, posy;
	char str[1010];

	while(1)
	{
		scanf("%s", str);

		if(str[0] == 'Q')
			break;
		init();
		posx = 1001;
		posy = 1001;
		visited[1001][1001] = true;
		for(i = 0 ; str[i] != 'Q' ; i++)
		{
			switch(str[i])
			{
				case 'U' : posy--; check(posx, posy); break;
				case 'D' : posy++; check(posx, posy); break;
				case 'L' : posx--; check(posx, posy); break;
				case 'R' : posx++; check(posx, posy); break;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}