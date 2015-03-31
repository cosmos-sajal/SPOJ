/*
Codechef

Chef and Frogs

Nobody knows, but N frogs live in Chef's garden.
Now they are siting on the X-axis and want to speak to each other. One frog can send a message to another one if the distance between them is less or equal to K.
Chef knows all P pairs of frogs, which want to send messages. Help him to define can they or not!
Note : More than 1 frog can be on the same point on the X-axis.
 
Input

The first line contains three integers N, K and P.
The second line contains N space-separated integers A1, A2, ..., AN denoting the x-coordinates of frogs".
Each of the next P lines contains two integers A and B denoting the numbers of frogs according to the input.
 
Output

For each pair print "Yes" without a brackets if frogs can speak and "No" if they cannot.
 
Constraints

1 ≤ N, P ≤ 10^5
0 ≤ Ai, K ≤ 10^9
1 ≤ A, B ≤ N
 
Example

Input:
5 3 3
0 3 8 5 12
1 2
1 3
2 5

Output:
Yes
Yes
No

 
Explanation


For pair (1, 2) frog 1 can directly speak to the frog 2 as the distance between them is 3 - 0 = 3 <= K . 

For pair (1, 3) frog 1 can send a message to frog 2, frog 2 can send it to frog 4 and it can send it to frog 3.
For pair (2, 5) frogs can't send a message under current constraints. 
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

struct node
{
	ll val, pos;
};

struct node b[100010];

void merge(struct node *a, ll low, ll mid, ll high)
{
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i].val <= a[j].val)
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
  
void mergesort(struct node *a, ll low, ll high)
{
    if (low < high) {
        ll m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

/*
void print(struct node *a, ll n)
{
	ll i;
	for(i = 0 ; i < n ; i++)
		printf("%lld %lld  ", a[i].val, a[i].pos);
	printf("\n");
}
*/

void swap(ll * a, ll * b)
{
	ll temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int binarySearch(ll beg, ll end, ll *arr, ll n)
{
	ll left = 0, right = n - 1, mid;

	while(right - left > 1)
	{
		mid = (left + right) / 2;
		if(arr[mid] > beg && arr[mid] < end)
			return 1;
		else if(arr[mid] == beg)
		{
			if(mid < n - 1 && arr[mid + 1] - 1 == arr[mid])
				return 1;
			else
				left = mid;
		}
		else if(arr[mid] == end)
		{
			if(mid > 0 && arr[mid - 1] + 1 == arr[mid])
				return 1;
			else
				right = mid;
		}
		else if(arr[mid] > end)
			right = mid;
		else if(arr[mid] < beg)
			left = mid;
	}
	if(left == 0)
	{
		if(arr[0] >= beg && arr[1] <= end && arr[1] == arr[0] + 1)
			return 1;
		else if(arr[0] > end)
			return 0;
		else if(arr[1] < beg)
			return 0;
		else
			return 0;

	}
	else if(right == n - 1)
	{
		if(arr[n - 2] >= beg && arr[n - 1] <= end && arr[n - 1] == arr[n - 2] + 1)
			return 1;
		else if(arr[n - 2] > end)
			return 0;
		else if(arr[n - 1] < beg)
			return 0;
		else
			return 0;
	}
	else
	{
		if(arr[left] >= beg && arr[right] <= end && arr[left] + 1 == arr[right])
			return 1;
		else if(arr[left] > end)
			return 0;
		else if(arr[right] < beg)
			return 0;
		else
			return 0;
	}

	return 0;
}

int main()
{
	ll i, j, l, n, k, p, beg, end, flag, actualPos[100010], diffViolationArr[100010], diffViolationArrLen;
	struct node arr[100010];
	ll sortedDistinctElements[100010];

	scanf("%lld %lld %lld", &n, &k, &p);
	for(i = 0 ; i < n ; i++)
	{
		scanf("%lld", &arr[i].val);
		arr[i].pos = i;
	}

	mergesort(arr, 0, n - 1);
	for(i = 0, j = 1 , l = 0 ; i < n ;)
	{
		while(i < n -1 && arr[i].val == arr[i + 1].val)
		{
			actualPos[arr[i].pos] = j;
			actualPos[arr[i + 1].pos] = j;
			i++;
		}
		actualPos[arr[i].pos] = j;
		sortedDistinctElements[l++] = arr[i].val;
		i++; j++;
	}
	for(i = 0 , j = 0 ; i < l - 1 ; i++)
	{
		if(sortedDistinctElements[i + 1] - sortedDistinctElements[i] > k)
		{
			if(j == 0)
			{
				diffViolationArr[j++] = i + 1;
				diffViolationArr[j++] = i + 2;
			}
			else if(j > 0 && diffViolationArr[j - 1] == i + 1)
				diffViolationArr[j++] = i + 2;
			else if(j > 0 && diffViolationArr[j - 1] != i + 1)
			{
				diffViolationArr[j++] = i + 1;
				diffViolationArr[j++] = i + 2;	
			}
		}
	}
	diffViolationArrLen = j;
	/*for(i = 0 ; i < n ; i++)
		printf("%lld ", actualPos[i]);
	printf("\n");
	for(i = 0 ; i < l ; i++)
		printf("%lld ", sortedDistinctElements[i]);
	printf("\n");
	for(i = 0 ; i < diffViolationArrLen ; i++)
		printf("%lld ", diffViolationArr[i]);*/
	for(i = 0 ; i < p ; i++)
	{
		scanf("%lld %lld", &beg, &end);
		
		beg = actualPos[beg - 1];
		end = actualPos[end - 1];
		if(beg == end)
		{
			printf("Yes\n");
			continue;
		}
		//printf("beg = %lld end = %lld\n", beg, end);
		if(beg > end)
			swap(&beg, &end);
		flag = binarySearch(beg, end, diffViolationArr, diffViolationArrLen);
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}