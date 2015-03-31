/*
10239. Between the Mountains

Problem code: ACPC11B

Did you try to ride a telepherique (cable car)? It is a lot of fun. Our company is trying to build a new telepherique line between two high mountains and you will be invited for a free ride. The trick to get your free ride is to help the company in building the telepherique line.

The company wants to build two platforms, one on each mountain. The line will extend between these two platforms. The suitable points for holding a platform in each mountain were determined, and the altitudes of these points were reported.

One of the talented engineers suggested that the company can save a lot of energy if the two stations have the same altitude or at least have altitudes which are as close to each other as possible. Your job is to select two points, one at each mountain, from those suitable points, so that the altitude difference between the two points is as little as possible.

Input

Your program will be tested on one or more test cases. The first line of the input will be a single integer T , the number of test cases (1 ≤ T ≤ 100). Follows 2T lines containing the test cases, each on a pair of lines.

Each of the two lines in a case describe the altitudes of suitable points to build a platform on one mountain. Each line starts with an integer N , the number of reported altitudes (1 ≤ N ≤ 1,000), followed by N integers, which represent the altitudes reported from this mountain. Any altitude value will be between 1 and 1,000,000, inclusive.

Output

For each test case, output, on a single line, a single number representing the minimum

altitude difference between two suitable platform points, one at each mountain.

 

Example

 

Input:
2
8 1 3 5 7 9 7 3 1
8 2 4 6 8 10 8 6 2
8 2 3 5 10 9 3 2 1
7 1 2 6 12 13 3 2

Output:
1
0
*/

#include <stdio.h>

void merge(long long int *a, int low, int mid, int high)
{
    int b[10000];
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

void displayArr(long long int *arr, int size)
{
	int i;

	for(i = 0 ; i < size ; i++)
		printf("%lld\t",arr[i]);

	printf("\n");
}

int main()
{
	int testCases;

	long long int arr1[1010], arr2[1010];
	int arr1Size, arr2Size, i, j;
	long long int min, diff;

	scanf("%d",&testCases);

	while(testCases--)
	{
		scanf("%d",&arr1Size);

		for(i = 0 ; i < arr1Size ; i++)
			scanf("%lld",&arr1[i]);

		scanf("%d",&arr2Size);

		for(i = 0 ; i < arr2Size ; i++)
			scanf("%lld",&arr2[i]);

		//sorting the arrays

		mergesort(arr1,0,arr1Size-1);
		mergesort(arr2,0,arr2Size-1);

		//displayArr(arr1,arr1Size);
		//displayArr(arr2,arr2Size);

		min = 999999999999;

		for(i = 0, j = 0 ; i < arr1Size && j < arr2Size ;)
		{
			diff = arr1[i] - arr2[j];

			if(diff < 0)
				diff = -1 * diff;

			if(diff < min)
				min = diff;

			if(arr1[i] < arr2[j])
				i++;
			else if(arr1[i] > arr2[j])
				j++;
			else
			{
				i++;
				j++;
			}
		}

		printf("%lld\n",min);

	}

	return 0;
}