/*
1716. Can you answer these queries III

Problem code: GSS3

You are given a sequence A of N (N <= 50000) integers between -10000 and 10000. On this sequence you have to apply M (M <= 50000) operations: 
modify the i-th element in the sequence or for given x y print max{Ai + Ai+1 + .. + Aj | x<=i<=j<=y }.

Input

The first line of input contains an integer N. The following line contains N integers, representing the sequence A1..AN. 
The third line contains an integer M. The next M lines contain the operations in following form:
0 x y: modify Ax into y (|y|<=10000).
1 x y: print max{Ai + Ai+1 + .. + Aj | x<=i<=j<=y }.
Output

For each query, print an integer as the problem required.

Example

Input:
4
1 2 3 4
4
1 1 3
0 3 -3
1 2 4
1 3 3

Output:
6
4
-3
*/

#include <stdio.h>
#define ll long long

struct node
{
	int msum, lsum, rsum, sum;
};

int arr[50010];
struct node stree[200000];

int max(int a, int b)
{
	int max = a > b ? a : b;
	return max;
}

void createSegmentTree(int pos, int ss, int se)
{
	struct node left, right;
	if(ss == se)
		stree[pos].lsum = stree[pos].rsum = stree[pos].msum = stree[pos].sum = arr[ss];
	else
	{
		createSegmentTree(pos * 2, ss, (ss + se) / 2);
		createSegmentTree(pos * 2 + 1, (ss + se) / 2 + 1, se);
		left = stree[pos * 2];
		right = stree[pos * 2 + 1];
		stree[pos].lsum = max(left.lsum, left.sum + right.lsum);
		stree[pos].rsum = max(right.rsum, right.sum + left.rsum);
		stree[pos].msum = max(left.msum, max(right.msum , left.rsum + right.lsum));
		stree[pos].sum = left.sum + right.sum;
	}
}

struct node query(int pos, int a, int b, int x, int y)
{
	struct node left, right, retVal;
	if(a == x && b == y)
		return stree[pos];
	if(y <= (a + b) / 2)
		return query(pos * 2, a, (a + b) / 2, x, y);
	if(x > (a + b) / 2)
		return query(pos * 2 + 1, (a + b) / 2 + 1, b, x , y);
	left = query(pos * 2, a, (a + b) / 2, x, (a + b) / 2);
	right = query(pos * 2 + 1, (a + b) / 2 + 1, b, (a + b) / 2 + 1, y);
	retVal.lsum = max(left.lsum, left.sum + right.lsum);
	retVal.rsum = max(right.rsum, right.sum + left.rsum);
	retVal.msum = max(left.msum, max(right.msum , left.rsum + right.lsum));
	retVal.sum = left.sum + right.sum;

	return retVal;
}

void update(int pos, int a, int b, int i, int val)
{
	int mid;
	struct node left, right;

	mid = (a + b) / 2;
	if(a == b && a == i)
	{
		stree[pos].lsum = stree[pos].rsum = stree[pos].msum = stree[pos].sum = val;
		return;
	}
	if(mid >= i)
		update(pos * 2, a, mid, i, val);
	else if(mid < i)
		update(pos * 2 + 1, mid + 1, b, i, val);
	left = stree[2 * pos];
	right = stree[2 * pos + 1];
	stree[pos].lsum = max(left.lsum, left.sum + right.lsum);
	stree[pos].rsum = max(right.rsum, right.sum + left.rsum);
	stree[pos].msum = max(left.msum, max(right.msum, left.rsum + right.lsum));
	stree[pos].sum = left.sum + right.sum;
}

int main()
{
	int n, i, m, x, y, queryType;

	scanf("%d", &n);

	for(i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);

	createSegmentTree(1, 0, n - 1);
	scanf("%d", &m);

	for(i = 0 ; i < m ; i++)
	{
		scanf("%d %d %d", &queryType, &x, &y);
		if(queryType == 0)
		{
			arr[x - 1] = y;		
			update(1, 0, n - 1, x - 1, y);
		}
		else
			printf("%d\n", query(1, 0, n - 1, x - 1, y - 1).msum);
	}

	return 0;
}