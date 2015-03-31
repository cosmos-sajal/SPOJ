/*
8061. Christmas Play

Problem code: AMR10G

My kid's kindergarten class is putting up a Christmas play.  (I hope he gets the lead role.)  The kids are all excited, but the teacher has a lot of work.  She has to produce costumes for a scene with K soldiers.  She wants to buy all the costumes in the same size, allowing for some small amount of length alteration to be done by the kids' parents later.  So she has taken all the kids' height measurements.  Can you help her select K kids from her class of N to play the soldier role, such that the height difference between the tallest and shortest in the group is minimized, and alternations will be easiest?  Tell her what this minimum difference is. 
 
 
INPUT 
The first line contains the number of test cases T. T test cases follow each containing 2 lines. 
 
The first line of each test case contains 2 integers N and K. 
The second line contains N integers denoting the height of the N kids. 
 
OUTPUT 
Output T lines, each line containing the required answer for the corresponding test case. 
 
CONSTTRAINTS 
T <= 30 
1 <= K <= N <= 20000 
1 <= height <= 1000000000 
 
SAMPLE INPUT
3 
3 1 
2 5 4  
3 2 
5 2 4  
3 3 
2 5 4  
 
 
SAMPLE OUTPUT 
0 
1 
3 
 
EXPLANATION
In the first test case, the teacher needs to only select 1 kid and hence she can choose any kid since the height difference is going to be 0. 
In the second test case, the teacher can choose kids with height 4 and 5. 
In the third test case, the teacher is forced to choose all 3 kids and hence the answer = 5-2 = 3


*/

#include <stdio.h>

void merge(long long int *a, int low, int mid, int high)
{
    int b[20010];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) 
    {
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
    if (low < high) 
    {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}


int main()
{
	int testCases, n, k, i, j;
	long long int arr[20010];
	long long int minDiff, tempDiff;

	scanf("%d",&testCases);

	while(testCases--)
	{
		minDiff = 9999999999;

		scanf("%d %d",&n, &k);

		for(i = 0 ; i < n ; i++)
			scanf("%lld",&arr[i]);

		if(k == 1)
		{
			printf("0\n");
			continue;
		}

		mergesort(arr, 0, n - 1);

		if(k == n)
		{
			printf("%lld\n", arr[n - 1] - arr[0]);
			continue;
		}

		for(i = 0, j = k - 1; j < n; i++, j++)
		{
			tempDiff = arr[j] - arr[i];
			if(tempDiff < minDiff)
				minDiff = tempDiff;
		}

		printf("%lld\n", minDiff);
	}

	return 0;
}