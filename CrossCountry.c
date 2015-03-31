/*
66. Cross-country

Problem code: CRSCNTRY

Agness, a student of computer science, is very keen on cross­country running, and she participates in races organised every Saturday in a big park. Each of the participants obtains a route card, which specifies a sequence of checkpoints, which they need to visit in the given order. Agness is a very atractive girl, and a number of male runners have asked her for a date. She would like to choose one of them during the race. Thus she invited all her admirers to the park on Saturday and let the race decide. The winner would be the one, who scores the maximum number of points. Agnes came up with the following rules:

a runner scores one point if he meets Agnes at the checkpoint,
if a runner scored a point at the checkpoint, then he cannot get another point unless he and Agnes move to the next checkpoints specified in their cards.
route specified by the card may cross the same checkpoint more than once,
each competitor must strictly follow race instructions written on his card.
Between two consecutive meetings, the girl and the competitors may visit any number of checkpoints. The boys will be really doing their best, so you may assume, that each of them will be able to visit any number of checkpoints whilst Agnes runs between two consecutive ones on her route.

Task

Write a program which for each data set from a sequence of several data sets:

reads in the contents of Agnes' race card and contents of race cards presented to Tom,
computes the greatest number of times Tom is able to meet Agnes during the race,
writes it to output.
Input

There is one integer d in the first line of the input file, 1 <= d <= 10. This is the number of data sets. The data sets follow. Each data set consists of a number of lines, with the first one specifying the route in Agnes' race card. Consecutive lines contain routes on cards presented to Tom. At least one route is presented to Tom. The route is given as a sequence of integers from interval [1, 1000] separated by single spaces. Number 0 stands for the end of the route, though when it is placed at the beginning of the line it means the end of data set. There are at least two and at most 2000 checkpoints in a race card.

Output

The i-th line of the output file should contain one integer. That integer should equal the greatest number of times Tom is able to meet with Agnes for race cards given in the i-th data set.

Example

Sample input:

3 
1 2 3 4 5 6 7 8 9 0 
1 3 8 2 0 
2 5 7 8 9 0 
1 1 1 1 1 1 2 3 0 
1 3 1 3 5 7 8 9 3 4 0 
1 2 35 0 
0 
1 3 5 7 0 
3 7 5 1 0 
0 
1 2 1 1 0 
1 1 1 0 
0 

Sample output:

6 
2 
3 
*/

#include <stdio.h>

int arr1[2010], arr2[2010], DP[2][2010];

void LCS(int len1, int len2)
{
	int i, j;

	for(i = 0 ; i <= len2 ; i++)
		DP[0][i] = 0;
	DP[1][0] = 0;
	for(i = 1 ; i <= len1 ; i++)
	{
		if(i % 2) //odd
		{	
			for(j = 1 ; j <= len2 ; j++)
			{
				if(arr1[i - 1] == arr2[j - 1])
					DP[1][j] = DP[0][j - 1] + 1;
				else if(DP[0][j] >= DP[1][j - 1])
					DP[1][j] = DP[0][j];
				else
					DP[1][j] = DP[1][j - 1];
			}
		}
		else //even
		{
			for(j = 1 ; j <= len2 ; j++)
			{
				if(arr1[i - 1] == arr2[j - 1])
					DP[0][j] = DP[1][j - 1] + 1;
				else if(DP[1][j] >= DP[0][j - 1])
					DP[0][j] = DP[1][j];
				else
					DP[0][j] = DP[0][j - 1];
			}
		}
	}
}

int main()
{
	int i, val, len1, len2, max, check, testCases;

	scanf("%d", &testCases);

	while(testCases--)
	{
		i = 0;
		while(1)
		{
			scanf("%d", &arr1[i]);
			if(arr1[i] == 0)
				break;
			i++;
		}
		len1 = i;
		max = -999999;
		while(1)
		{
			scanf("%d", &check);
			if(check == 0)
				break;
			arr2[0] = check;
			i = 1;
			while(1)
			{
				scanf("%d", &arr2[i]);
				if(arr2[i] == 0)
					break;
				i++;
			}
			len2 = i;
			LCS(len1, len2);
			if(len1 % 2) //odd
				val = DP[1][len2];
			else //even
				val = DP[0][len2];
			if(val > max)
				max = val;
		}

		printf("%d\n", max);

	}
	return 0;
}