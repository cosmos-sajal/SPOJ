/*
4053. Card Sorting

Problem code: MCARDS

Dave’s little son Maverick likes to play card games, but being only four years old, he always lose when playing with his older friends. Also, arranging cards in his hand is quite a problem to him.

When Maverick gets his cards, he has to arrange them in groups so that all the cards in a group are of the same color. Next, he has to sort the cards in each group by their value – card with lowest value should be the leftmost in its group. Of course, he has to hold all the cards in his hand all the time.

He has to arrange his cards as quickly as possible, i.e. making as few moves as possible. A move consists of changing a position of one of his cards.

Write a program that will calculate the lowest number of moves needed to arrange cards.

Input

The first line of input file contains two integers C, number of colors (1 ≤ C ≤ 4), and N, number of cards of the same color (1 ≤ N ≤ 100), separated by a space character.

Each of the next C*N lines contains a pair of two integers X and Y, 1 ≤ X ≤ C, 1 ≤ Y ≤ N, separated by a space character.

Numbers in each of those lines determine a color (X) and a value (Y) of a card dealt to little Maverick. The order of lines corresponds to the order the cards were dealt to little Maverick. No two lines describe the same card.

Output

The first and only line of output file should contain the lowest number of moves needed to arrange the cards as described above.

Sample

CARDS.IN

2 2
2 1
1 2
1 1
2 2

CARDS.OUT

2
 
CARDS.IN

4 1
2 1
3 1
1 1
4 1

CARDS.OUT

0
 
CARDS.IN

3 2
3 2
2 2
1 1
3 1
2 1
1 2

CARDS.OUT
2
*/

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
	int color, number;
};

/*
int LIS(int *arr, int n)
{
	int i, len, left, right, mid, pos, LISArr[110];

	LISArr[0] = arr[0];
	len = 1;
	for(i = 1 ; i < n ; i++)
	{
		if(arr[i] < LISArr[0])
			LISArr[0] = arr[i];
		else
		{
			left = 1;
			right = len;
			while(right >= left)
			{
				mid = left + (right - left) / 2;
				if(LISArr[mid] < arr[i] && LISArr[mid + 1] > arr[i])
				{
					pos = mid;
					break;
				}
				else if(mid == len - 2 && LISArr[mid + 1] < arr[i])
				{
					pos = mid + 1;
					break;
				}
				else if(LISArr[mid] > arr[i])
					right = mid;
				else if(LISArr[mid] < arr[i])
					left = mid + 1;

			}
		}
	}
}
*/


int LIS(int start, int end, int *arr)
{
	int i, j, LISLength, LISLengthArr[410];

	for(i = 0 ; i < 410 ; i++)
		LISLengthArr[i] = 1;
	for(i = start + 1 ; i <= end ; i++)
	{
		for(j = start ; j < i ; j++)
		{
			if(arr[j] < arr[i] && LISLengthArr[j] + 1 > LISLengthArr[i])
				LISLengthArr[i] = LISLengthArr[j] + 1;
		}
	}
	LISLength = LISLengthArr[0];
	for(i = 1 ; i < 410 ; i++)
		if(LISLengthArr[i] > LISLength)
			LISLength = LISLengthArr[i];

	return LISLength;
}

int main()
{
	int i, j, k, moves, minMoves, noOfCards, noOfColours, colors[4], finalArr[410], colorMap[4] = {0, 0, 0, 0};
	struct node arr[410];

	scanf("%d %d", &noOfColours, &noOfCards);

	for(i = 0 ; i < noOfCards * noOfColours ; i++)
	{
		scanf("%d %d", &arr[i].color, &arr[i].number);
		colorMap[arr[i].color - 1] = 1;
	}
	for(i = 0, j = 0 ; i < 4 ; i++)
	{
		if(colorMap[i] == 1)
			colors[j++] = i + 1;
	}
	vector < int > v(noOfColours * noOfCards);
	minMoves = 99999999;
	do
	{
		for(i = 0, k = 0 ; i < noOfColours * noOfCards ; i++, k++)
		{
			for(j = 0 ; j < noOfColours ; j++)
				if(arr[i].color == colors[j])
				{
					finalArr[k] = j * noOfCards + arr[i].number - 1;
					break;
				}
		}
		moves = noOfCards * noOfColours - LIS(0, noOfColours * noOfCards - 1, finalArr);
		if(moves < minMoves)
			minMoves = moves;

	}while(next_permutation(colors, colors + noOfColours));

	printf("%d\n", minMoves);

	return 0;
}