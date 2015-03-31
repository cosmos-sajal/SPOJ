
#include <stdio.h>


int main()
{
	int i, j, sum,;
	int input[100], dp[100];

	scanf("%d", &n);

	for(i = 0 ; i < n ; i++)
		scanf("%d", &input[i]);

	for(i = 0 ; i < n ; i++)
	{
	    dp[i] = 1;
	    for(j = 0 ; j < i ; j++)
	    {	
	        if(input[j] < input[i])
	        	dp[i] = dp[i] + dp[j];
	    }
	}

	sum = 0;
	for(i = 0 ; i < n ; i++)
		sum += dp[i];

	printf("%d\n", sum);

	return 0;
}