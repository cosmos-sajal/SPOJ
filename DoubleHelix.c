/*
4560. The Double HeLiX

Problem code: ANARC05B

Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are
printed in bold:
First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can ‘walk” over these two sequences in the following way:
1. You may start at the beginning of any of the two sequences. Now start moving forward.
2. At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450  which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62

Input

Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. Each line denotes a sequence and is speciﬁed using the following format:

                 n  v1 v2 ... vn
Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. All elements are between -10,000 and 10,000 (inclusive). 
The last line of the input includes a single zero, which is not part of the test cases.

Output

For each test case, write on a separate line, the largest possible sum that can be produced.

Sample

input 
 
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0
output 
 
450
2100
*/

#include <stdio.h>

int main()
{
	long long int seq1[10010], seq2[10010];
	long long int seq1Sum[10010], seq2Sum[10010];
	long long int commonNumbers[10010], hash[20010];
	long long int m, n, count, i, j;
	long long int tempSum;

	while(1)
	{
		count = 0;
		for(i = 0 ; i < 20010 ; i++)
			hash[i] = 0;

		scanf("%lld", &m);

		for(i = 0 ; i < m ; i++)
		{
			scanf("%lld", &seq1[i]);
			if(seq1[i] >= 0)
				hash[seq1[i]]++;
			else
				hash[(seq1[i] * (-1)) + 10000]++;
		}

		if(m == 0)
			break;

		scanf("%lld", &n);

		for(i = 0 ; i < n ; i++)
		{
			scanf("%lld", &seq2[i]);
			if(seq2[i] >= 0)
			{
				hash[seq2[i]]++;
				if(hash[seq2[i]] == 2)
					commonNumbers[count++] = seq2[i];	
			}
			else
			{
				hash[(seq2[i] * (-1)) + 10000]++;
				if(hash[(seq2[i] * (-1)) + 10000] == 2)
					commonNumbers[count++] = seq2[i];
			}

			
		}

		tempSum = 0;

		for(i = 0, j = 0 ; i < m ; i++ )
		{
			tempSum += seq1[i];
			if(j < count && seq1[i] == commonNumbers[j])
			{
				seq1Sum[j++] = tempSum;
				tempSum = 0;
			}
		}

		seq1Sum[j++] = tempSum;

		tempSum = 0;

		for(i = 0, j = 0 ; i < n ; i++)
		{
			tempSum += seq2[i];
			if(j < count && seq2[i] == commonNumbers[j])
			{
				seq2Sum[j++] = tempSum;
				tempSum = 0;
			}
		}



		seq2Sum[j++] = tempSum;

		tempSum = 0;
		for(i = 0 ; i < j ; i++)
		{
			if(seq1Sum[i] > seq2Sum[i])
				tempSum += seq1Sum[i];
			else
				tempSum += seq2Sum[i];
		}

		printf("%lld\n", tempSum);

	}

	return 0;
}
