/*
10565. Alice Sieve

Problem code: ALICESIE

Alice has recently learned to use the Sieve of Eratosthenes, an ancient algorithm for finding all

prime numbers up to any given limit. As expected, she was really impressed by it's simplicity and

elegancy.

Now, she has decided to design her own sieve method: The Sieve of Alice, formally defined by the

following procedure, which determines the Sieve of Alice up to a given limit N.

1. Create a list of consecutive integers from N to 2 (N, N-1, N-2, ..., 3, 2). All of those N-1

numbers are initially unmarked.

2. Initially, let P equal N, and leave this number unmarked.

3. Mark all the proper divisors of P (i.e. P remains unmarked).

4. Find the largest unmarked number from 2 to P – 1, and now let P equal this number.

5. If there were no more unmarked numbers in the list, stop. Otherwise, repeat from step 3.

Unfortunately, Alice has not found an useful application for it's Sieve. But she still wants to know,

for a given limit N, how many integers will remain unmarked.

 

 

Input

 

The first line contains an integer T, the number of test cases (1 ≤ T ≤ 10^4) . Each of the next T lines

contains an integer N ( 2 ≤ N ≤ 10^6).

 

Output

 

Output T lines, one for each test case, containing the required answer.

 

Example

Input:
3
2
3
5
Output:
1
2
3
*/

#include <stdio.h>

int main()
{
	int testCases;
	long long int n;

	scanf("%d",&testCases);

	while(testCases--)
	{
		scanf("%lld",&n);
		if(n % 2 == 0)
			printf("%lld\n",n / 2);
		else
			printf("%lld\n",n / 2 + 1);
	}

	return 0;
}