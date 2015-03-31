/*
7881. Ljutnja

Problem code: C1LJUTNJ

Children in a kindergarten have received a large sack containing M candies. It has been decided that the candies are to be distributed among N children.

Each child has stated the number of candies that it wants. If a child isn’t given the amount of candy it wants, it will get angry. In fact it’ll get angrier for each candy it is deprived of. Some speculate that it’s anger will be equal to the square of the number of candy it is deprived of. For instance, if Mirko states that he wants 32 candies but receives only 29, he would be missing 3 candies, so his anger would be equal to 9.

Unfortunately, there is an insufficient amount of candy to satisfy all children. Therefore, the candies should be distributed in such a way that the sum of the children’s anger is minimal.

Input

The first line contains two integers, M (1 ≤ M ≤ 2.109) and N (1 ≤ N ≤ 100 000).

The following N lines contain integers (one per line) which represent the wishes of the children. Those numbers are all strictly less than 2.109, and their sum always exceeds M.

Output

The first and only line of output must contain the minimum sum of the children’s anger.

Note: The test cases will ensure that the result fits in a 64-bit unsigned integer: int64 in Pascal, long long in C/C++, long in Java.

Example

Input:
5 3 
1 
3 
2
Output:
1

Input:
10 4
4
5
2
3

Output:
4
*/

#include <stdio.h>
#define ll long long
#define MOD 9223372036854775808

ll b[100010];

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

ll calculate(ll *arr, ll m, ll n)
{
	int i;
	ll angerVal;

	angerVal = 0;
	for(i = 0 ; i < n ; i++)
	{
		m -= arr[i];
		if(m <= 0)
		{
			angerVal = -1 * m;
			i++;
			break;
		}
	}
	for(; i < n ; i++)
		angerVal = (angerVal + arr[i]) % MOD;

	return angerVal;
}

int main()
{
	ll i, m, n;
	ll arr[100010];

	scanf("%lld %lld", &m, &n);
	for(i = 0 ; i < n ; i++)
		scanf("%lld", &arr[i]);

	mergesort(arr, 0, n - 1);
	printf("%lld\n", calculate(arr, m, n));

	return 0;
}