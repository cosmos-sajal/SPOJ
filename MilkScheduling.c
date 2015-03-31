/*
18965. Milk Scheduling

Problem code: MSCHED

Farmer John has N cows that need to be milked (1 <= N <= 10,000), each of which takes only one unit of time to milk.

Being impatient animals, some cows will refuse to be milked if Farmer John waits too long to milk them. More specifically, cow i produces g_i gallons of milk (1 <= g_i <= 1000), but only if she is milked before a deadline at time d_i (1 <= d_i <= 10,000). Time starts at t=0, so at most x total cows can be milked prior to a deadline at time t=x.

Please help Farmer John determine the maximum amount of milk that he can obtain if he milks the cows optimally.

Input :

 - Line 1: The value of N.

 - Lines 2..1+N: Line i+1 contains the integers g_i and d_i.

Output : A single numbers denotes the maximum number of gallons of milk Farmer John can obtain.



Sample :

 Input:

 4

 10 3

 7 5

 8 1

 2 1

 Output :

 25

Input details : There are 4 cows. The first produces 10 gallons of milk if milked by time 3, and so on.

Output details : Farmer John milks cow 3 first, giving up on cow 4 since she cannot be milked by her deadline due to the conflict with cow 3. Farmer John then milks cows 1 and 2.
*/

#include <stdio.h>
#define ll long long
#define MIN -9999

ll milkArr[10010], deadlineArr[10010];
int deadlineMap[10010];

void merge(long long int *a, int low, int mid, int high)
{
    int b[10010], c[10010];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i] >= a[j])
        {
            b[k] = a[i];
            c[k++] = deadlineArr[i++]; 
        }
        else
        {
            b[k] = a[j];
            c[k++] = deadlineArr[j++];
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        c[k++] = deadlineArr[i++];
    }
  
    while (j <= high)
    {
        b[k] = a[j];
        c[k++] = deadlineArr[j++];
    } 
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        deadlineArr[low + k] = c[k];
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

void print(int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
		printf("%lld %lld\n", milkArr[i], deadlineArr[i]);
}

int main()
{
	ll optimumSum;
	ll int n, i, j, maxDeadLine;

	scanf("%lld", &n);

	maxDeadLine = MIN;
	for(i = 0 ; i < n ; i++)
	{
		scanf("%lld %lld", &milkArr[i], &deadlineArr[i]);
		if(maxDeadLine < deadlineArr[i])
			maxDeadLine = deadlineArr[i];
	}

	optimumSum = 0;
	mergesort(milkArr, 0, n - 1);
	//print(n);
	for(i = 0 ; i < n ; i++)
	{
		if(!deadlineMap[deadlineArr[i]])
		{
			deadlineMap[deadlineArr[i]] = 1;
			optimumSum += milkArr[i];
		}
		else
		{
			j = deadlineArr[i];
			while(j > 0 && deadlineMap[j])
				j--;
			if(j > 0)
			{
				deadlineMap[j] = 1;
				optimumSum += milkArr[i];
			}
		}
	}

	/*for(i = maxDeadLine ; i > 0 ; i--)
	{
		max = MIN;
		maxPos = -1;
		for(j = 0 ; j < n ; j++)
		{
			if(deadlineArr[j] >= i && max < milkArr[j])
			{
				max = milkArr[j];
				maxPos = j;
			}
		}
		if(max != MIN)
		{
			milkArr[maxPos] = MIN;
			optimumSum += max;
		}
	}
	*/
	printf("%lld\n", optimumSum);

	return 0;
}