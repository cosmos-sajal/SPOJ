/*
11515. I AM VERY BUSY

Problem code: BUSYMAN

I AM VERY BUSY



You are actually very busy man. You have a big schedule of activities. Your aim is to do as much as activities as possible.



In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3. 

Either you can 
* watch movie, play DotA and sleep peacefully (or)
* date with crush, play DotA and sleep peacefully




Input Specifications:

The first line consists of an integer t, the number of test cases. For each test case the first line consists of an integer n, the number of activities. Then the next n lines contains two integers m and n, the start and end time of each activity.

 

Output Specifications:

For each test case find the maximum number of activities that you can do.




Input Constraints:

 1<=t<=10

1<=n<=100000

0<=start<end<=1000000

 

Sample Input: (empty lines just for clarity)

3

3

3 9

2 8

6 9


4

1 7

5 8

7 8

1 8

 

6

7 9

0 10

4 5

8 9

4 10

5 7

 

Sample Output:

1

2

3

URL : http://www.spoj.com/problems/BUSYMAN/
*/


#include <stdio.h>
#define ll long

struct node
{
	int start, end;
};

int DPArr[2000010];
struct node b[100010];

int max(int a, int b)
{
	int max = a >= b ? a : b;
	return max;
}

void merge(struct node *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i].end <= a[j].end)
        {
         	if(a[i].end == a[j].end)
         	{
         		if(a[i].start <= a[j].start)
         			b[k++] = a[i++];
         		else
         			b[k++] = a[j++];
         	}
         	else
            	b[k++] = a[i++];
        }
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
  
void mergesort(struct node *a, int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

int main()
{
	int i, j, n, testCases;
	int start, end, maxEnd;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);

		maxEnd = -1;
		struct node arr[100010];
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d %d", &start, &end);
			arr[i].start = start;
			arr[i].end = end;
			if(arr[i].end > maxEnd)
				maxEnd = arr[i].end;
		}

		mergesort(arr, 0, n - 1);
		/*for(i = 0 ; i < n ; i++)
			printf("%d %d %d\n", arr[i].start, arr[i].end, arr[i].profit);
		printf("-------\n");
		*/
		DPArr[0] = 0;
		for(i = 1, j = 0 ; i <= maxEnd ; i++)
		{
			if(i == arr[j].end)
			{
				DPArr[i] = max(DPArr[i - 1], 1 + DPArr[arr[j].start]);
				j++;
				while(i == arr[j].end)
				{
					DPArr[i] = max(DPArr[i], 1 + DPArr[arr[j].start]);
					j++;
				}
			}
			else
				DPArr[i] = DPArr[i - 1];
		}

		/*for(i = 0 ; i <= maxEnd ; i++)
			printf("%ld ", DPArr[i]);
		printf("\n");*/

		printf("%d\n", DPArr[maxEnd]);
	}

	return 0;
}