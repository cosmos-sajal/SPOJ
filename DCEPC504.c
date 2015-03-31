/*
11402. The Indian Connection

Problem code: DCEPC504

Rajesh Kuthrapali has a weird family structure. Every male member gives birth to a male child first and then a female child whereas every female member gives birth to a female child first and then to a male child. Rajesh analyses this pattern and wants to know what will be the Kth child in his Nth generation. Help him.

Note:

1.Every member has exactly 2 children.

2. The generation starts with a male member(Rajesh).

3. In the figure given below:

                                   M-------- 1st generation 

                              /        \
                          M             F ------- 2nd generation
                        /    \         /   \
                      M     F       F     M
                                      |
                                   3rd child of 3rd generation

Input

First line specifies T, the number of test cases.

Next T lines each gives 2 numbers, N and K

Output

Output 1 line for each test case giving the gender of the Kth child in in Nth generation.

Print “Male” for male “Female” for female (quotes only for clarification).

Constraints

1<=T<=100

1<=N<=10000

1<=K<=min(10^15 , 2^(n-1))

Example

Input:
4
1 1
2 1
2 2
4 5 
Output:
Male
Male
Female
Female
*/

#include <stdio.h>
#define ll long long

int main()
{
	ll testCases, level, n, numOf1s;

	scanf("%lld", &testCases);

	while(testCases--)
	{
		scanf("%lld %lld", &level, &n);

		numOf1s = 0;
		n--;
		while(n >= 1)
		{
			if(n % 2 != 0)
				numOf1s++;
			n /= 2;
		}
		if(numOf1s % 2)
			printf("Female\n");
		else
			printf("Male\n");
	}

	return 0;
}