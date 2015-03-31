/*
7804. Defense of a Kingdom

Problem code: DEFKIN

Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

 

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.

Help Theodore write a program that calculates the penalty of the given position.

 

 

Input

 

The first line of the input file contains the number of test cases.

 

Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

 

Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

 

 

Output

 

For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.

 

 

Example

Input:
1
15 8 3
3 8
11 2
8 6

Output:
12
*/

#include <stdio.h>
#define MIN -999999999
#define ll long long

int b[40010];

void merge(long long int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
  
    while (j <= high)
        b[k++] = a[j++];
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}
  
void mergesort(long long int *a, int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

ll calculate(ll *xPos, ll *yPos, ll n)
{
	ll i, max, xDiff, yDiff, maxXDiff, maxYDiff;

	max = maxXDiff = maxYDiff = MIN;
	for(i = 1 ; i < n ; i++)
	{
		xDiff = xPos[i] - xPos[i - 1] - 1;
		yDiff = yPos[i] - yPos[i - 1] - 1;
		if(maxXDiff < xDiff)
			maxXDiff = xDiff;
		if(maxYDiff < yDiff)
			maxYDiff = yDiff;
	}
	max = maxXDiff * maxYDiff;

	return max;
}

int main()
{
	int i, testCases;
	ll xPos[40010], yPos[40010];
	ll width, height, noOfTowers;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%lld %lld %lld", &width, &height, &noOfTowers);
		xPos[0] = yPos[0] = 0;
		for(i = 1 ; i <= noOfTowers ; i++)
			scanf("%lld %lld", &xPos[i], &yPos[i]);
		xPos[i] = width + 1;
		yPos[i] = height + 1;
		mergesort(xPos, 0, noOfTowers + 1);
		mergesort(yPos, 0, noOfTowers + 1);
		printf("%lld\n", calculate(xPos, yPos, noOfTowers + 2));
	}

	return 0;
}
