/*
3934. Recaman’s Sequence

Problem code: MRECAMAN

The Recaman’s sequence is deﬁned by a0 = 0 ; for m > 0, a(m) = a(m−1) − m if the resulting a(m) is positive and not already in the sequence, otherwise a(m) = a(m−1) + m. The ﬁrst few numbers in the Recaman’s Sequence is 0, 1, 3,6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9 · · · .

Given k, your task is to calculate ak.

Input

The input consists of several test cases. Each line of the input contains an integer k where 0 ≤ k ≤ 500000. The last line contains an integer −1, which should not be processed.


Sample Input
7
10000
-1
Output

 
For each k given in the input, print one line containing ak to the output.

Sample output
20
18658
*/

#include <stdio.h>
#define ll long long

ll arr[500010];
int map[10000000];

void precompute()
{
	ll i, temp;

	arr[0] = 0;
	for(i = 1 ; i < 500010 ; i++)
	{
		temp = arr[i - 1] - i;
		if(temp > 0 && !map[temp])
		{
			arr[i] = temp;
			map[temp] = 1;
		}
		else
		{
			arr[i] = arr[i - 1] + i;
			map[arr[i]] = 1;
		}
	}
}

int main()
{
	ll index;

	precompute();
	while(1)
	{
		scanf("%lld", &index);
		if(index == -1)
			break;
		printf("%lld\n", arr[index]);
	}

	return 0;
}
