/*
7741. Sequence

Problem code: BOI7SEQ

We are given a sequence a1 , ..., an . We can manipulate this sequence using the operation reduce(i), which replaces elements ai and ai+1 with a single element max(ai , ai+1 ), resulting in a new shorter sequence. The cost of this operation is max(ai , ai+1 ). After n−1 operations reduce, we obtain a sequence of length 1. Our task is to compute the cost of the optimal reducing scheme, i.e. the sequence of reduce operations with minimal cost leading to a sequence of length 1.

Input

The first line contains n (1 ≤ n ≤ 1,000,000), the length of the sequence. The following n lines contain one integer ai , the elements of the sequence (0 ≤ ai ≤ 1,000,000,000).

Output

In the first and only line of the output print the minimal cost of reducing the sequence to a single element.

Example

Input:
3
1
2
3
Output:
5
*/

#include <stdio.h>
#define ll long long
#define SIZE 1000010
#define gc getchar_unlocked

ll arr[SIZE];

void scanint(ll int &x)
{
	register ll int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}


ll max(ll a, ll b)
{
	ll max = a > b ? a : b;
	return max;
}

int main()
{
	ll n, sum = 0, i;

	scanint(n);
	scanint(arr[0]);
	for(i = 1 ; i < n ; i++)
	{
		scanint(arr[i]);
		sum += max(arr[i - 1], arr[i]); 
	}

	printf("%lld\n", sum);

	return 0;
}