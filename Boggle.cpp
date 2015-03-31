/*
12462. Boggle Scoring

Problem code: BOGGLE

In Boggle, you win points for words you find on the board which no other player finds. If another player finds the same word as you, neither player gets points for that word.

For words of 4 or fewer letters, 1 point is awarded. 5-letter words are worth 2 points, 6-letter words are worth 3 points, 7-letter words are worth 5 points, and words longer than 7 letters are worth 11 points.

Given the set of words that some boggle players found, determine the score of the winner.

Input:
The first line is the number of players (at most 100).
Each subsequent line is the space-separated list of no more than than 50 words each no more than 50 characters (ASCII 33-126) that player found

Output:
The score of the winning player

Input												Output
2
one two three
two three four										1

3
good dual strange stranger would
dual would duality dregs gnaw
dual gnaw draw would student						17

2
grid grades dread bread thread threads
grid grids grade brood broods thread threads		9 
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct node
{
	struct node *link[95];
	int nullPtr, playerNo;
};

struct node *start = NULL, *ptr = NULL, *temp = NULL;
long long int playerScore[60];

int main()
{
	int noOfPlayers, i, j, k, l;
	long long int maxScore;
	char words[3000];
	scanf("%d", &noOfPlayers);
	getc(stdin);
	//std::cin>>noOfPlayers;

	for(i = 0 ; i < 60 ; i++)
		playerScore[i] = 0;

	for(i = 1 ; i <= noOfPlayers ; i++)
	{
		//scanf("%s", words);
		gets(words);
		for(j = 0 ; words[j] != '\0' ;)
		{

			if(start == NULL)
			{
				start = (struct node *)malloc(sizeof(struct node));
				for(l = 0 ; l < 95 ; l++)
					start->link[l] = NULL;
				start->nullPtr = 0;
				start->playerNo = -1;
			}
			ptr = start;
			for(k = 0 ; words[k + j] != ' ' && words[k + j] != '\0' ; k++)
			{
				if(ptr->link[words[k + j] - 33] == NULL)
				{
					temp = (struct node *)malloc(sizeof(struct node));
					for(l = 0 ; l < 95 ; l++)
						ptr->link[l] = NULL;
					ptr->link[words[k + j] - 33] = temp;
					ptr->nullPtr = 0;
					ptr->playerNo = -1;
				}
				ptr = ptr->link[words[k + j] - 33];	
			}
			j += (k + 1);
			ptr->nullPtr = 1;
			if(ptr->playerNo > 0)
				printf("%d\n", ptr->playerNo);//do nothing
			else
				ptr->playerNo = -1;

			if(ptr->playerNo > 0)
			{
				if(k < 5)
					playerScore[ptr->playerNo]--;
				else if(k == 5)
					playerScore[ptr->playerNo] -= 2;
				else if(k == 6)
					playerScore[ptr->playerNo] -= 3;
				else if(k == 7)
					playerScore[ptr->playerNo] -= 5;
				else if(k > 7)
					playerScore[ptr->playerNo] -= 11;
				ptr->playerNo = 0;
			}
			else if(ptr->playerNo == -1)
			{
				ptr->playerNo = i;
				if(k < 5)
					playerScore[ptr->playerNo]++;
				else if(k == 5)
					playerScore[ptr->playerNo] += 2;
				else if(k == 6)
					playerScore[ptr->playerNo] += 3;
				else if(k == 7)
					playerScore[ptr->playerNo] += 5;
				else if(k > 7)
					playerScore[ptr->playerNo] += 11;	
			}

		}
	}

	maxScore = -99999999;
	for(i = 1 ; i <= noOfPlayers ; i++)
		if(playerScore[i] > maxScore)
			maxScore = playerScore[i];

	printf("%lld\n", maxScore);

	return 0;
}