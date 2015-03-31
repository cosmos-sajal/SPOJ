/*
345. Mixtures

Problem code: MIXTURES

Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

Input

There will be a number of test cases in the input.

The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.

The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Output

For each test case, output the minimum amount of smoke.

Example

Input:
2
18 19
3
40 60 20

Output:
342
2400
In the second test case, there are two possibilities:

first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400
first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400
The first scenario is a much better way to proceed.
*/

#include <stdio.h>
#define ll long long

int main()
{
	int i, j, k, L, q, noOfMixtures;
	ll mulMatrix[110][110], mixtureMatrix[110][110];

	while(scanf("%d", &noOfMixtures) == 1)
	{
		for(i = 1 ; i <= noOfMixtures ; i++)
		{
			scanf("%lld", &mixtureMatrix[i][i]);
			mulMatrix[i][i] = 0;
		}

		for (L=2; L <= noOfMixtures ; L++)   
    	{
	        for (i = 1 ; i <= noOfMixtures - L + 1 ; i++)
	        {
	            j = i + L - 1;
	            mulMatrix[i][j] = 99999999;
	            for (k = i ; k <= j - 1 ; k++)
	            {
	                // q = cost/scalar multiplications
	                q = mulMatrix[i][k] + mulMatrix[k + 1][j] + mixtureMatrix[i][k]*mixtureMatrix[k + 1][j];
	                if (q < mulMatrix[i][j])
	                {
	                    mulMatrix[i][j] = q;
	                    mixtureMatrix[i][j] = (mixtureMatrix[i][k] + mixtureMatrix[k + 1][j]) % 100;
	                }
	            }
	        }
    	}

    	printf("%lld\n", mulMatrix[1][noOfMixtures]);

	}

	return 0;
}