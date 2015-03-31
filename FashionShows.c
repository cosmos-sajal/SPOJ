/*
1025. Fashion Shows

Problem code: FASHION

A fashion show rates participants according to their level of hotness. Two different fashion shows were organized, one for men and the other for women. A date for the third is yet to be decided ;) .

Now the results of both fashion shows are out. The participants of both the fashion shows have decided to date each other, but as usual they have difficuly in choosing their partners. The Maximum Match dating serive (MMDS) comes to their rescue and matches them in such a way that that maximizes the hotness bonds for all couples.

If a man has been rated at hotness level x and a women at hotness level y, the value of their hotness bond is x*y.

Both fashion shows contain N participants each. MMDS has done its job and your job is to find the sum of hotness bonds for all the couples that MMDS has proposed.

Input

The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of 3 lines:

The first line contains a single integer N (1 <= N <= 1000).
The second line contains N integers separated by single spaces denoting the hotness levels of the men.
The third line contains N integers separated by single spaces denoting the hotness levels of the women.
All hotness ratings are on a scale of 0 to 10.

Output

For each test case output a single line containing a single integer denoting the sum of the hotness bonds for all pairs that MMDS has proposed.

Example

Input:
2
2
1 1
3 2
3
2 3 2
1 3 2

Output:
5
15
*/

#include <stdio.h>
#define ull long long int

ull classesArr[1010], costArr[1010], b[1010];

void merge(ull *a, ull low, ull mid, ull high)
{
    ull i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i] >= a[j])
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
  
void mergesort(ull *a, ull low, ull high)
{
    if (low < high) {
        ull m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

int main()
{
	ull n, i, sum, testCases;

    scanf("%lld", &testCases);

	while(testCases--)
	{
		scanf("%lld", &n);

		for(i = 0 ; i < n ; i++)
			scanf("%lld", &classesArr[i]);
		for(i = 0 ; i < n ; i++)
			scanf("%lld", &costArr[i]);
		mergesort(classesArr, 0, n - 1);
		mergesort(costArr, 0, n - 1);
		sum = 0;
		for(i = 0 ; i < n ; i++)
			sum += classesArr[i] * costArr[i];

		printf("%lld\n", sum);
	}

	return 0;
}