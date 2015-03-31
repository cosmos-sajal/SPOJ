/*
18180. Love Story

Problem code: PIHU1

Rancho is in love with Pihu. So on the Valentine’s Day they decided to spend time together at Assi Ghat, but Rancho, as we all know is very busy with his work, so he failed. It was now Pihu’s turn to go mad with anger. But there’s something which you can do.

Rancho tells Pihu that he is a novice programmer and is generally busy in solving problems at spoj. So Pihu decides to check his algorithmic skills. She puts forward an array of N integers. She gives him a number P and asks if he can find three (strictly three) integers Ai Aj Ak  ( i ≠ j ≠ k ) in the array, whose sum is equal to number P, i.e.

Ai + Aj + Ak  =P.

Now, sooner Rancho answers her query in YES or NO, sooner he gets a kiss.

Input

The first line of input consists of an integer T, number of test cases.

The second line of input consists of an integer N, denoting the size of array.

The third line consists of N integers A1, A2 A3 ……………. AN , separated with space .

The fourth line consists of number P.

CONSTRAINTS

1<=T<=15

3<= N <= 1000

1<= Ai <= 10^9    where 1<= i <=N

1<= P <= 3*10^9

Output

If you find three numbers Ai ,Aj ,Ak  ,  ( i ≠ j ≠ k )  in the array such that Ai + Aj + Ak  =P, print “YES” else print “NO” ( quotes for clarification only). 

Example

Input

1

3

1 2 3

6

Output

YES
*/

#include <stdio.h>
#define ll long long

ll arr[1010];

void merge(long long int *a, int low, int mid, int high)
{
    ll b[1010];
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

int binarySearch(ll valueToSearch, int n, int i, int j)
{
	int mid, high, low;
	low = 0;
	high = n - 1;
	while(low < high)
	{
		mid = (low + high) / 2;
		if(arr[mid] == valueToSearch)
		{
			if(i != mid && j != mid)
				return 1;
			else
			{
				if(i == mid && j != mid)
				{
					if((arr[mid - 1] == arr[mid] && mid - 1 != j)|| (arr[mid + 1] == arr[mid] && mid + 1 != j))
						return 1;
				}
				else if(j == mid && i != mid)
				{
					if((arr[mid - 1] == arr[mid] && mid - 1 != i) || (arr[mid + 1] == arr[mid] && mid + 1 != i))
						return 1;	
				}
				return 0;
			}
		}
		else if(arr[mid] < valueToSearch)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return 0;
}

int main()
{
	int testCases, n, i, j, flag;
	ll sum, temp, valueToSearch;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);

		for(i = 0 ; i < n ; i++)
			scanf("%lld", &arr[i]);
		scanf("%lld", &sum);

		mergesort(arr, 0, n - 1);
		flag = 0;
		for(i = 0 ; i < n ; i++)
		{
			for(j = i + 1 ; j < n ; j++)
			{
				temp = arr[i] + arr[j];
				valueToSearch = sum - temp;
				if(binarySearch(valueToSearch, n, i, j))
				{
					printf("YES\n");
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(!flag)
			printf("NO\n");
	}

	return 0;
}