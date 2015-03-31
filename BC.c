/*
9935. Break the Chocolate

Problem code: BC

Benjamin is going to host a party for his big promotion coming up.

Every party needs candies, chocolates and beer, and of course Benjamin has prepared some of those. But as everyone likes to party, many more people showed up than he expected. The good news is that candies are enough. And for the beer, he only needs to buy some extra cups. The only problem is the chocolate.

As Benjamin is only a 'small court officer' with poor salary even after his promotion, he can not afford to buy extra chocolate. So he decides to break the chocolate cubes into smaller pieces so that everyone can have some.

He have two methods to break the chocolate. He can pick one piece of chocolate and break it into two pieces with bare hand, or put some pieces of chocolate together on the table and cut them with a knife at one time. You can assume that the knife is long enough to cut as many pieces of chocolate as he want.

The party is coming really soon and breaking the chocolate is not an easy job. He wants to know what is the minimum number of steps to break the chocolate into unit-size pieces (cubes of size 1×1×1). He is not sure whether he can find a knife or not, so he wants to know the answer for both situations.

Input

The first line contains an integer T (1 ≤ T ≤ 10000), indicating the number of test cases.

Each test case contains one line with three integers N, M, K (1 ≤ N, M, K ≤ 2000), meaning the chocolate is a cube of size N×M×K.

Output

For each test case in the input, print one line: "Case #X: A B", where X is the test case number (starting with 1) , A and B are the minimum numbers of steps to break the chocolate into N×M×K unit-size pieces with bare hands and knife respectively.

Example

Input:
2
1 1 3
2 2 2

Output:
Case #1: 2 2
Case #2: 7 3
*/

#include <stdio.h>

long long int arr[14];

void precompute()
{
	int i;

	arr[0] = 1;
	for(i = 1 ; i <= 12 ; i++)
	{
		arr[i] = 2 * arr[i - 1];
	}
}

int main()
{
	int testCases, i, itr1, itr2, itr3;
	long long int prod, m, n, k;


	scanf("%d", &testCases);

	precompute();
	for(i = 1 ; i <= testCases ; i++)
	{
		scanf("%lld %lld %lld", &m, &n, &k);

		prod = m * n * k;
		for(itr1 = 0 ; itr1 <= 12 ; itr1++)
			if(arr[itr1] >= m)
				break;
		for(itr2 = 0 ; itr2 <= 12 ; itr2++)
			if(arr[itr2] >= n)
				break;
		for(itr3 = 0 ; itr3 <= 12 ; itr3++)
			if(arr[itr3] >= k)
				break;
	

		if(prod != 0)
			prod--;		

		printf("Case #%d: %lld %d\n", i, prod, itr1 + itr2 + itr3);
	}

	return 0;
}