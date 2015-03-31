/*
1710. Two Ends

Problem code: TWENDS

In the two-player game “Two Ends”, an even number of cards is laid out in a row. On each card, face up, is written a positive integer. Players take turns removing a card from either end of the row and placing the card in their pile. The player whose cards add up to the highest number wins the game. Now one strategy is to simply pick the card at the end that is the largest — we’ll call this the greedy strategy. However, this is not always optimal, as the following example shows: (The first player would win if she would first pick the 3 instead of the 4.)

3 2 10 4

You are to determine exactly how bad the greedy strategy is for different games when the second player uses it but the first player is free to use any strategy she wishes.

Input

There will be multiple test cases. Each test case will be contained on one line. Each line will start with an even integer n followed by n positive integers. A value of n = 0 indicates end of input. You may assume that n is no more than 1000. Furthermore, you may assume that the sum of the numbers in the list does not exceed 1,000,000.

Output

For each test case you should print one line of output of the form:

In game m, the greedy strategy might lose by as many as p points.

where m is the number of the game (starting at game 1) and p is the maximum possible difference between the first player’s score and second player’s score when the second player uses the greedy strategy. When employing the greedy strategy, always take the larger end. If there is a tie, remove the left end.

Example

Input:
4 3 2 10 4
8 1 2 3 4 5 6 7 8
8 2 2 1 5 3 8 7 3
0

Output:
In game 1, the greedy strategy might lose by as many as 7 points.
In game 2, the greedy strategy might lose by as many as 4 points.
In game 3, the greedy strategy might lose by as many as 5 points.
*/

#include <stdio.h>

int arr[1010], firstPlayerDP[1010][1010], secondPlayerDP[1010][1010];

void init(int n)
{
	int i, j;

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			if(j - i == 1)
			{
				if(arr[i] > arr[j])
				{
					firstPlayerDP[i][j] = arr[i];
					secondPlayerDP[i][j] = arr[j];
				}
				else
				{
					firstPlayerDP[i][j] = arr[j];
					secondPlayerDP[i][j] = arr[i];	
				}
			}
			else
				firstPlayerDP[i][j] = secondPlayerDP[i][j] = -1;
		}
	}
}

void recFun(int start, int end)
{
	int a, b, c, d, choicePlayer1, choicePlayer2;

	choicePlayer1 = arr[start];
	if(arr[start + 1] >= arr[end])
	{
		choicePlayer2 = arr[start + 1];
		if(firstPlayerDP[start + 2][end] == -1)
			recFun(start + 2, end);
		a = choicePlayer1 + firstPlayerDP[start + 2][end];
		b = choicePlayer2 + secondPlayerDP[start + 2][end];
	}
	else
	{
		choicePlayer2 = arr[end];
		if(firstPlayerDP[start + 1][end - 1] == -1)
			recFun(start + 1, end - 1);
		a = choicePlayer1 + firstPlayerDP[start + 1][end - 1];
		b = choicePlayer2 + secondPlayerDP[start + 1][end - 1];
	}
	choicePlayer1 = arr[end];
	if(arr[start] >= arr[end - 1])
	{
		choicePlayer2 = arr[start];
		if(firstPlayerDP[start + 1][end - 1] == -1)
			recFun(start + 1, end - 1);
		c = choicePlayer1 + firstPlayerDP[start + 1][end - 1];
		d = choicePlayer2 + secondPlayerDP[start + 1][end - 1];
	}
	else
	{
		choicePlayer2 = arr[end - 1];
		if(firstPlayerDP[start][end - 2] == -1)
			recFun(start, end - 2);
		c = choicePlayer1 + firstPlayerDP[start][end - 2];
		d = choicePlayer2 + secondPlayerDP[start][end - 2];
	}
	if((a - b) >= (c - d))
	{
		firstPlayerDP[start][end] = a;
		secondPlayerDP[start][end] = b;
	}
	else
	{
		firstPlayerDP[start][end] = c;
		secondPlayerDP[start][end] = d;
	}

}

int main()
{
	int i, n, testCaseNo = 1;

	while(1)
	{
		scanf("%d", &n);

		if(!n)
			break;
		for(i = 0 ; i < n ; i++)
			scanf("%d", &arr[i]);

		init(n);
		recFun(0, n - 1);

		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", testCaseNo++, firstPlayerDP[0][n - 1] - secondPlayerDP[0][n - 1]);
	}

	return 0;
}