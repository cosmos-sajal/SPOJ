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

int main()
{
	int testCases;
	long long int input[110];
	long long int i, j, temp, pos, min;
	int actualPositionsOfTestCases[110];
	long long int m[110];
	long long int intermediateResults[110];
	long long int prevOne = 1, prevTwo = 0;
	int flag = 0;

	scanf("%d",&testCases);

	for(i = 0 ; i < testCases ; i++)
		scanf("%lld%lld",&input[i],&m[i]);

	//sorting the input

	for(i = 0; i < testCases; i++)
	{
		min = input[i];
		pos = i;
		flag = 0;

		for(j = i + 1; j < testCases; j++)
		{
			if(min > input[j])
			{
				min = input[j];
				pos = j;
				flag = 1;
			}
		}

		if(flag)
		{
			temp = input[i];
			input[i] = input[pos];
			input[pos] = temp;
			actualPositionsOfTestCases[i] = pos;
		}
	}

	for(i = 2; i <= input[0]; i++)
	{
		intermediateResults[0] = ((prevOne + prevTwo)%m[actualPositionsOfTestCases[0]] + (i - 1))%m[actualPositionsOfTestCases[0]];
		prevTwo = prevOne%m[actualPositionsOfTestCases[0]];
		prevOne = intermediateResults[0];
	}



	for(i = 1; i < testCases ; i++)
	{
		//printf("input->%lld\n",input[i] );

		for(j = input[i-1] + 1 ; j <= input[i] ; j++)
		{
			intermediateResults[i] = ((prevOne + prevTwo)%m[actualPositionsOfTestCases[i]] + (j - 1))%m[actualPositionsOfTestCases[i]];
			//printf("%lld\n",intermediateResults[i] );
			prevTwo = prevOne%m[actualPositionsOfTestCases[i]];
			prevOne = intermediateResults[i];
		}
	}



	for(i = 0 ; i < testCases ; i++)
	{

		if(input[actualPositionsOfTestCases[i]] == 1)
			printf("1\n");
		else if(input[actualPositionsOfTestCases[i]] == 0)
			printf("0\n");
		else
			printf("%lld\n",intermediateResults[actualPositionsOfTestCases[i]]);
	}

	return 0;
}
