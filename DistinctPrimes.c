/*
10232. Distinct Primes

Problem code: AMR11E

Arithmancy is Draco Malfoy's favorite subject, but what spoils it for him is that Hermione Granger is in his class, and she is better than him at it.  Prime numbers are of mystical importance in Arithmancy, and Lucky Numbers even more so. Lucky Numbers are those positive integers that have at least three distinct prime factors; 30 and 42 are the first two. Malfoy's teacher has given them a positive integer n, and has asked them to find the nth lucky number. Malfoy would like to beat Hermione at this exercise, so although he is an evil git, please help him, just this once.  After all, the know-it-all Hermione does need a lesson.

 

Input (STDIN):

The first line contains the number of test cases T. Each of the next T lines contains one integer n.

 

Output (STDOUT):

Output T lines, containing the corresponding lucky number for that test case.

 

Constraints:

1 <= T <= 20

1 <= n <= 1000

 

Sample Input:

2

1

2

 

Sample Output:

30

42
*/

#include <stdio.h>

int primeNoArr[2001];
int sieveArr[2001];
int numArr[2710];
int resultArr[2710];

int initialiseSieve()
{
	int i, j;


	//for(i = 0 ; i <= 1001 ; i++)
	//	sieveArr[i] = 0;

	for(i = 2 ; i <= 751 ; i++)
	{
		for(j = i * 2 ; j <= 1502 ; j += i)
		{
			sieveArr[j] = 1;
		}
	}

	for(i = 2, j = 0 ; i <= 1502 ; i++)
	{
		if(sieveArr[i] == 0)
			primeNoArr[j++] = i;
	}

	return j;

}

void initiliseNumberArr(int numOfPrimes)
{
	int i, j, primeNo;

	//for(i = 0 ; i <= 1001 ; i++)
	//	numArr[i] = 0;

	for(i = 0 ; i < numOfPrimes ; i++)
	{
		primeNo = primeNoArr[i];
		for(j = 2 * primeNo ; j <= 2700 ; j+= primeNo)
		{
			numArr[j]++;
		}
	}

	for(i = 1, j = 0 ; i <= 2700 ; i++)
	{
		if(numArr[i] > 2)
		{
			resultArr[j++] = i;
		}
	}
}

int main()
{
	int testCases, numOfPrimes, input;


	numOfPrimes = initialiseSieve();

	//for(i = 0 ; i < numOfPrimes ; i++)
	//	printf("%d\n",primeNoArr[i]);

	//printf("%d\n",numOfPrimes );

	initiliseNumberArr(numOfPrimes);

	scanf("%d",&testCases);

	while(testCases--)
	{
		scanf("%d",&input);
		printf("%d\n",resultArr[input - 1]);
	}

	return 0;
}