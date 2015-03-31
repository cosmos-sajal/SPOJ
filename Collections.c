/*
15627. Create Collections

Problem code: IITKWPCO

Little Feluda likes to play very much. As you know he only plays with numbers. So he is given n numbers. Now tries to group the numbers into collections each containing two numbers. He can form the collection containing two numbers iff small number in the collection is exactly half of large number.

  Given n numbers, Find out how many maximum number of collections he can form ?

Input

T: number of test cases. (1 <= T <= 100).

For each test case:

First line will contain n :  (1 <= n <= 100)

Then next line will contain n numbers single space seperated. Range of each number will be between 1 and 10^6.

Output

For each test case, output maximum number of collections that can be formed.

Example

Input:
2
2
1 2
3 
1 2 4
Output:
1
1
*/

#include <stdio.h>

int hash[2000010];

void merge(long long int *a, int low, int mid, int high)
{
    int b[110];
    int i = low, j = mid + 1, k = 0;
  
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
  
void mergesort(long long int *a, int low, int high)
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
	int testCases, n, i;
	long long int arr[110];
	long long int pairs = 0;

	scanf("%d",&testCases);

	while(testCases--)
	{
		pairs = 0;

		scanf("%d", &n);

		for(i = 0 ; i < n ; i++)
		{
			scanf("%lld",&arr[i]);
			hash[arr[i]] = hash[arr[i] * 2] = 0;
		}

		mergesort(arr, 0 , n - 1);

		for(i = 0 ; i < n ; i++)
		{
			if(hash[arr[i] * 2] > 0)
			{
				hash[arr[i] * 2]--;
				pairs++;
			}
			else
			{
				hash[arr[i]]++;
			}
		}

		printf("%lld\n", pairs);

	}

	return 0;
}