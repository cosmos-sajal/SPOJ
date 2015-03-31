/*
11409. Fibonacci With a Twist

Problem code: FIBTWIST
Fibonacci numbers are given by 

f(n)=f(n-1) + f(n-2)

with f(0) =0       &        f(1) =1

first number of series ------ 0  1  1  2  3  5  8  13 

Now lets have a new series called "Fibonacci Twist" which is given by 

ft(n) = ft(n-1) + ft(n-2) + (n-1)  

with ft(0) = 0  & ft(1) =1

with first few number in the series ----- 0  1  2  5  10  19  34  59 

 

Now your task is to find ft(n).

Since the number can be Big you have to find the result mod M.

Input

first line having single number 't' -- number of test cases.

next t lines have 2 number each     'n' and 'M'

Output

Single number given the nth term mod M

Example

Input:
3
5 20
10 77
15  111

Output:

19
45
69
NOTE -
10<=t<=100
0<=n<=10^9
100<=M<=10^9
Explanation - 
1)  ft(5) is 19 . 19%20 = 19
2)  ft(10) is 276 .  276%77  = 45
3)  ft(15) is 3177 . 3177 %111=69
*/

#include <stdio.h>

long long int arr[30000001];

int main()
{
	long long int i;
	int testCases;
	long long int n, m;
	long long int answer, onePrev, twoPrev;

	arr[0] = 0;
	arr[1] = 1;

	for(i = 2; i <= 20000000 ; i++)
		arr[i] = arr[i-1] + arr[i-2] + (i-1);

	for(i = 0 ; i < 100 ; i++)
		printf("%lld\t",arr[i] );


	scanf("%d",&testCases);

	while(testCases--)
	{
		scanf("%lld%lld",&n,&m);

		if(n <= 30000000)
			printf("%lld\n",arr[n]%m);
		else
		{
			onePrev = arr[30000000];
			twoPrev = arr[29999999];

			for(i = 30000000; i < n ; i++)
			{
				answer = (onePrev + twoPrev + (i - 1))%m;
				twoPrev = onePrev;
				onePrev = answer;
			}

			printf("%lld\n",answer);
		}
	}

	return 0;
}