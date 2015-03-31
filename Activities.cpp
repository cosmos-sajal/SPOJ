/*
7386. Activities

Problem code: ACTIV

Ana likes many activities. She likes acrobatics, alchemy, archery, art, Arabic dances, and
many more. She joined a club that offers several classes. Each class has a time interval
in every week. Ana wants to sign up for many classes, but since they overlap in time, she
looks for a subset of non-overlapping classes to attend. A subset is non-overlapping if it
does not contain two classes that overlap in time. If a class starts at the time another
class ends, this is not considered overlapping.
Ana decided to list all the non-overlapping non-empty subsets of classes. Then she will
choose the subset she likes best. In order to predict the amount of paper needed to write
the list, she wants you to calculate how many of these subsets there are.

Input

Each test case is described using several lines. The first line contains an integer N
indicating the number of classes the club offers (1 ≤ N ≤ 105 ). Each of the next N lines
describes a class using two integers S and E that represent the starting and ending times
of the class, respectively (1 ≤ S < E ≤ 109 ). The end of input is indicated with a line
containing a single −1.

Output

For each test case, output a single line with a single integer representing the number of
non-overlapping non-empty subsets of classes. To make your life easier, output only the
last 8 digits of the result. If the result has less than 8 digits, write it with leading zeros
to complete 8 digits.

Example

Input: 
5
1 3
3 5
5 7
2 4
4 6
3
500000000 1000000000
1 500000000
1 500000000
1
999999999 1000000000
-1

Output: 
00000012
00000005
00000001
*/

#include <stdio.h>
#define l long
#define INF 9999999999
const int MODULO = 1e8;

struct node
{
	l start, end;
};

struct node arr[100010], b[100010];
l DP[100010], n;

void merge(struct node *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i].start <= a[j].start)
        {
         	if(a[i].start == a[j].start)
         	{
         		if(a[i].end <= a[j].end)
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

l bsearch(l val)
{
	l left, right, key, mid;

	left = val;
	right = n;
	key = arr[val].end;

	while(right - left > 1)
	{
		mid = (left + right) / 2;
		if(arr[mid].start >= key)
			right = mid;
		else
			left = mid;
	}

	return right;
}

l calc(l x)
{
	l val1, val2, pos;

	if(DP[x] == -1)
	{
		if(DP[x + 1] == -1)
			val1 = calc(x + 1);
		else
			val1 = DP[x + 1];
		pos = bsearch(x);
		if(DP[pos] == -1)
			val2 = calc(pos);
		else
			val2 = DP[pos];
		DP[x] = (val1 + val2 + 1) % MODULO;
	}

	return DP[x];
}

int main()
{
	l i;

	while(1)
	{
		scanf("%ld", &n);

		if(n == -1)
			break;

		for(i = 0 ; i < n ; i++)
		{
			scanf("%ld %ld", &arr[i].start, &arr[i].end);
			DP[i] = -1;
		}
		arr[n].start = arr[n].end = INF;
		DP[n - 1] = 1;
		DP[n] = 0;
		mergesort(arr, 0, n - 1);

		printf("%08ld\n", calc(0));
	}

	return 0;
}