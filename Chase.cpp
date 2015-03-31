/*
1326. A Chase In WonderLand

Problem code: CHASE

Alice is in Wonderland. It is March and March Hare is raving mad. It begins to chase Alice. Alice runs as fast as she can, but she comes to the the edge of a quicksand pool. Now this pool has several safe spots where she may comfortably step on without being swallowed by the quicksand. She may step onto any safe spot from solid ground, but thereafter she can jump from spot to spot only in a straight line, and she cant turn back. March Hare is still hot on her heels, so she needs to know the maximum number of jumps she can make.

Input

On the first line there will be a single integer n, denoting the number of test cases. Each test case will consist of a single integer k by itself on a line, followed by k lines containing the x and y co-ordinates of the safe spots , seperated by a single space. Both coordinates are integer values. There are no leading or trailing spaces or blank lines. 0<k≤2200

Output

For each case print a single integer by itself on a line, with no leading or trailing spaces. Do not print blank lines.

Example

Input:
2
5
0 0
1 1
2 2
4 8
2 75
3
0 0
1 2
3 4


Output:
2
1

*/

#include <stdio.h>
#include <map>

using namespace std;

struct node
{
	int x, y;
};

struct key
{
	struct node point;
	double slope;

	bool operator<(const key &rhs) const {
		return slope < rhs.slope;
	}
};

struct node arr[2210];

int max(int a, int b)
{
	int max = a >= b ? a : b;
	return max;
}

int main()
{
	int n, i, j, count, answer, testCases;
	double slope;
	map <struct key, int> m;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++)
			scanf("%d %d", &arr[i].x, &arr[i].y);

		answer = 1;
		for(i = 0 ; i < n ; i++)
		{
			for(j = i + 1 ; j < n ; j++)
			{
				struct node tempPoint;
				tempPoint = arr[i];
				if(arr[j].x - arr[i].x == 0)
					slope = 999999;
				else
					slope = (double)(arr[j].y - arr[i].y) / (double)(arr[j].x - arr[i].x);
				if(slope < 0)
					slope *= -1;
				struct key k;
				k.point = tempPoint;
				k.slope = slope;
				map<key, int>::iterator it = m.find(k);
				if(it != m.end())
					count = it->second;
				else
					count = 0;
				m[k] = ++count;
				answer = max(answer, count);
			}
		}
		m.clear();

		printf("%d\n", answer - 1);
	}

	return 0;
}