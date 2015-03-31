/*
3921. The Great Ball

Problem code: BYTESE2

The Great Ball (5 points) Hogwarts has organized The Great Ball to welcome the schools participating in the Triwizard Tournament. The ball is being held in the Great Hall and The Weird Sisters have been called to play the band. The students drift in to dance and then go out when they get tired. Hagrid is stationed at the gate and is noting down the time at which people enter and leave the hall. At the end of the day, he wonders what the maximum number of dancers was during the course of the ball. For convenience, he writes down for each person entering, the number of minutes from the start of the ball at which the person entered and left. The door of the hall is narrow, so at any time, either one person can enter or one person can exit, but not both. For example, suppose the observations noted down by Hagrid are the following:
Serial No	Enters at	Leaves at
1	1	7
2	2	4
3	6	9
4	3	8
5	5	10
Each line denotes the entry time and exit time of one person. (The identity of the person is not important - the same person may enter and leave many times. For instance, in the example, it might well be that the entries and exits recorded at serial no. 2 & 5 refer to the same person). In this example, the maximum size of the dancers during the ball was 4. This was achieved between time 6 & 7. Hagrid is not good at Math so he requires your help. Your task is to read the list of entry and exit times and compute the maximum number of dancers during the ball.

Input

The first line is a single integer, T (1<=T<=100), which is the number of test cases. For each of the test case, the first line contains a single integer N, (1<=N<=100), the number of entries and exits recorded. This is followed by N lines. Each of these lines consists of two integers, separated by a space, describing the entry and exit time of that person. The entry and exit times are guaranteed to be distinct, and the entry time will be less than the exit time. The constraint on entry and exit times is 10000000.

Output

A total of T lines each of them containing a single integer, denoting the maximum number of dancers during the ball.

Example

Input:
1
5
1 7
2 4
6 9
3 8
5 10

Output:
4
*/

#include <stdio.h>
#define ll long long

ll entryArray[110], leaveArray[110];

void merge(long long int *a, int low, int mid, int high)
{
    int b[110];
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


int main()
{
	int testCases, n, i, j;
	ll maxPeople, tempSum;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);

		for(i = 0 ; i < n ; i++)
			scanf("%lld %lld", &entryArray[i], &leaveArray[i]);
		mergesort(entryArray, 0, n - 1);
		mergesort(leaveArray, 0, n - 1);
		maxPeople = -1;
		tempSum = 0;
		for(i = 0, j = 0 ; i < n ;)
		{
			if(entryArray[i] < leaveArray[j])
			{
				tempSum++;
				if(tempSum > maxPeople)
					maxPeople = tempSum;
				i++;
			}
			else if(entryArray[i] > leaveArray[j])
			{
				tempSum--;
				j++;
			}
			else
			{
				i++;
				j++;
			}
		}

		printf("%lld\n", maxPeople);
	}

	return 0;
}