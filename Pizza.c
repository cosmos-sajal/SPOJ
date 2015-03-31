/*
12151. Pizzamania

Problem code: OPCPIZZA

Singham and his friends are fond of pizza. But this time they short of money. So they decided to help each other.They all decided to bring pizza in pairs. Our task is to find the total number of pairs possible which can buy pizza, given the cost of pizza. As pizza boy dont have any cash for change, if the pair adds upto more money than required, than also they are unable to buy the pizza. Each friend is guaranteed to have distinct amount of money. As it is Singham's world, money can also be negative ;).



Input:

The first line consist of t(1<=t<=100) test cases.In the following 2*t lines, for each test case first there is n and m, where n(1<=n<=100000) is number of Singham's friend and m is the price of pizza.The next line consist of n integers, seperated by space, which is the money each friend have. 



The value of m and money is within the limits of int in C,C++.



Output: 

A single integer representing the number of pairs which can eat pizza.



Example

Sample Input:

2

4 12

9 -3 4 3

5 -9

-7 3 -2 8 7



Sample Output:

1

1


*/

#include <stdio.h>
#define ll long long
int arr[100010];

void merge(int *a, int low, int mid, int high)
{
    int b[100010];
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
/*
int binarySearch(ll firstNoPos, ll secondNo, ll n)
{
	ll low = 0, high = n, mid, itr;

	posMap[firstNoPos] = 1;
	while(low < high)
	{
		mid = (low + high) / 2;
		if(arr[mid] == secondNo)
		{
			if(!posMap[mid])
			{
				posMap[mid] = 1;
				posMap[firstNoPos] = 1;
				return 1;
			}
			else
			{
				itr = mid - 1;
				while(itr >= 0 && arr[itr] == secondNo)
				{
					if(!posMap[itr])
					{
						posMap[itr] = 1;
						posMap[firstNoPos] = 1;
						return 1;
					}
					itr--;
				}
				itr = mid + 1;
				while(itr < n && arr[itr] == secondNo)
				{
					if(!posMap[itr])
					{
						posMap[itr] = 1;
						posMap[firstNoPos] = 1;
						return 1;
					}
					itr++;
				}
				posMap[firstNoPos] = 0;
				return 0;
			}
		}
		else if(arr[mid] > secondNo)
			high = mid - 1;
		else
			low = mid + 1;
	}

	posMap[firstNoPos] = 0;
	return 0;
}
*/

ll searchPairs(n, m)
{
	ll i, j, tempSum, noOfPairs = 0;
	for(i = 0, j = n - 1 ; i < j ;)
	{
		tempSum = arr[i] + arr[j];
		if(tempSum == m)
		{
			noOfPairs++;
			i++;
			j--;
		}
		else if(tempSum < m)
			i++;
		else
			j--;
	}

	return noOfPairs;
}

int main()
{
	ll testCases;
	ll i, n, m;

	scanf("%lld", &testCases);

	while(testCases--)
	{
		scanf("%lld %lld", &n, &m);

		for(i = 0 ; i < n ; i++)
			scanf("%d", &arr[i]);

		//for(i = 0 ; i < 100010 ; i++)
		//	posMap[i] = 0;
		mergesort(arr, 0, n - 1);
		//noOfPairs = 0;
		/*for(i = 0 ; i < n ; i++)
		{
			firstNo = arr[i];
			secondNo = m - firstNo;
			if(posMap[i])
				continue;
			retVal = binarySearch(i, secondNo, n);
			if(retVal)
			{
				//printf("1st no=%lld 2nd no=%lld\n", firstNo, secondNo);
				noOfPairs++;
			}
		}*/

		printf("%lld\n", searchPairs(n, m));
	}

	return 0;
}