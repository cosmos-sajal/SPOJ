/*
10514. K12 - Building Construction

Problem code: KOPC12A

   Given N buildings of height h1,h2,h3...hn, the objective is to make every building has equal height. This can be done by removing bricks from a building or adding some bricks to a building.Removing a  brick or  adding  a brick is done at certain cost which will be given along with the heights of the buildings.Find the minimal cost at which you can make the buildings look beautiful by re-constructing the buildings such that the N buildings satisfy 

h1=h2=h3=..=hn=k ( k can be any number).

For convenience, all buildings are considered to be vertical piles of bricks, which are of same dimensions. 

 

         Given N buildings of height h1,h2,h3...hn, the objective is to make every building has equal height. This can be done by removing bricks from a building or adding some bricks to a building.Removing a  brick or  adding  a brick is done at certain cost which will be given along with the heights of the buildings.Find the minimal cost at which you can make the buildings look beautiful by re-constructing the buildings such that the N buildings satisfy h1=h2=h3=..=hn=k ( k can be any number).
Input

 

The first line of input contains an integer T which denotes number of test cases .This will be followed by 3*T lines , 3 lines per test case. The first line of each test case contains an integer n and the  second line contains n integers which denotes the heights of the buildings [h1,h2,h3....hn] and the third line contains n integers [c1,c2,c3...cn] which denotes the cost of adding or removing one unit of brick from the corresponding building.

T<=15;n<=10000;0<=Hi<=10000;0<=Ci<=10000;

Output

 

The output must contain T lines each line corresponding to a testcase.

 

Example

Input:
1
3
1 2 3
10 100 1000


Output:
120
*/

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
#define SIZE 10010

int heightArr[SIZE], costArr[SIZE];
int minHeight, maxHeight;

ll min(ll a, ll b)
{
	ll min = a < b ? a : b;
	return min;
}

ll helper(double h, int n)
{
	int i;
	ll sum = 0;

	for(i = 0 ; i < n ; i++)
		sum += (abs)(heightArr[i] - h) * costArr[i];

	return sum;
}

ll ternarySearch(int n)
{
	double l = (double)minHeight, r = (double) maxHeight, ml, mr;
	while(r - l > 1)
	{
		ml = (l + (r - l) / 3.0);
		mr = (r - (r - l) / 3.0);
		if(helper(ml, n) < helper(mr, n))
			r = mr;
		else
			l = ml;

	}

	return min(helper(floor(l), n), helper(ceil(l), n));
}

int main()
{
	int testCases, n, i;

	scanf("%d", &testCases);

	while(testCases--)
	{
		minHeight = INT_MAX;
		maxHeight = INT_MIN;

		scanf("%d", &n);	
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d", &heightArr[i]);
			if(heightArr[i] > maxHeight)
				maxHeight = heightArr[i];
			if(heightArr[i] < minHeight)
				minHeight = heightArr[i];
		}
		for(i = 0 ; i < n ; i++)
			scanf("%d", &costArr[i]);

		printf("%lld\n", ternarySearch(n));
	}

	return 0;
}