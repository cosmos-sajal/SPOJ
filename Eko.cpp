/*
11814. Eko

Problem code: EKO

Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty 

new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to 

cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises 

a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than 

H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row 

contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the 

remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 

5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he 

wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the 

sawblade that still allows him to cut off at least M metres of wood.

 

Input

 

The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 

1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

The second line of input contains N space-separated positive integers less than 1 000 000 000, the 

heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to 

obtain the required amount of wood.

 

Output

The first and only line of output must contain the required height setting.

 

Example

Input:
4 7
20 15 10 17

Output:
15
Input:
5 20
4 42 40 26 46
Output:
36
*/

#include <stdio.h>
#define ll long long
#define gc getchar_unlocked

int arr[1000010], b[1000010];

int decide(ll val, ll sum, ll n)
{
	ll i, temp = 0;
	for(i = n - 1 ; arr[i] > val ; i--)
	{
		if(arr[i] > val)
			temp += (arr[i] - val);
	}

	if(temp > sum)
		return 1;
	else if(temp == sum)
		return -1;
	else 
		return 0;
}

ll binarySearch(ll high, ll sum, ll n)
{
	ll low = 0, mid, val;

	while(low < high)
	{
		mid = (low + high) / 2;
		
		val = decide(mid, sum, n);
		if(val == 0)
			high = mid;
		else if(val == 1)
			low = mid + 1;
		else
			return mid;
	}

	return low - 1;
}

void merge(int *a, int low, int mid, int high)
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
  
void mergesort(int *a, int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

void scanint(int &x)
{
register int c = gc();
x = 0;
int neg = 0;
for(;((c<48 || c>57) && c != '-');c = gc());
if(c=='-') {neg=1;c=gc();}
for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
if(neg) x=-x;
}


int main()
{
	ll n, sum, max, i;

	scanf("%lld %lld", &n, &sum);

	max = -1;
	for(i = 0 ; i < n; i++)
	{
		scanint(arr[i]);
		if(max < arr[i])
			max = arr[i];
	}
	mergesort(arr, 0, n - 1);

	printf("%lld\n", binarySearch(max, sum, n));

	return 0;
}