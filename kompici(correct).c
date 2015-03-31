/*
SPOJ Problem Set (classical)
10069. Kompići
Problem code: KOMPICI

 
After successfully solving his math homework from the previous task, Mirko has become bored, so he 
has made a list of N large integers. On the list there are some pairs of numbers that he likes, and some 
pairs he doesn’t like. 
Mirko has named the pairs that he likes pals. Two numbers are pals if they have at least one digit in 
common (not necessarily in the same position). 
Help Mirko count how many pairs of numbers in his list are pals. 
INPUT 
The first line of input contains the positive integer N (1 ≤ N ≤ 1 000 000). 
Each of the next N lines contains a positive integer from the range [1, 10
18
], a number from Mirko’s 
list. No two numbers in the list will be equal. 
OUTPUT 
The first and only line of output must contain the number of pairs that are pals. 

*/

#include <stdio.h>
#include <math.h>


int canMakePairs( int num1, int num2 )
{
	int binaryNum1[11]={0},binaryNum2[11]={0};
	int quotient,i=1;

	quotient = num1;

    while( quotient != 0 )
    {
         binaryNum1[i++]= quotient % 2;
         quotient = quotient / 2;
    }

    
    i=1;
    quotient = num2;

	while( quotient != 0 )
    {
         binaryNum2[i++]= quotient % 2;
         quotient = quotient / 2;
    }

    for( i = 0 ; i < 11 ; i++ )
    {
    	if( binaryNum1[i] == 1 && binaryNum2[i] == 1 )
    		return 1;
    }

    return 0;

}


int main()
{
	long long int n,i,j;
	char num[20];
	int map[10];
	long long int arr[1024]={0};
	long long int numOfPairs = 0 ;
	int returnValue;

	scanf("%lld",&n);

	for( i = 0 ; i < n ; i++ )
	{
		scanf("%s",num);

		for( j = 0 ; j < 10 ; j++ )
			map[j] = 0;

		for( j = 0 ; num[j] != '\0' ; j++ )
		{
			if( map[ num[j] - '0'] == 0 )
				map[ num[j] - '0' ] = 1;
		}

		int arrayIndex = 0;

		for( j = 0 ; j < 10 ; j++ )
		{
			if( map[j] == 1 )
				arrayIndex += pow(2,j);
		}

		arr[arrayIndex]++;

	}



	
	for( i = 0 ; i < 1023 ; i++ )
	{
		if( arr[i] == 0 )
			continue;

		if( arr[i] != 1 )
			numOfPairs += (arr[i]*(arr[i]-1))/2;

		for( j = i+1 ; j < 1024 ; j++ )
		{
			if( arr[j] == 0 )
				continue;

			returnValue = canMakePairs(i,j);

			if(returnValue)
			{
				numOfPairs += arr[i]*arr[j];
				//printf("\n--------%lld %lld \n",i,j);
			}
		}
	}


	if( arr[1023] != 1 )
		numOfPairs += (arr[1023]*(arr[1023]-1))/2;

	printf("%lld\n",numOfPairs);

	return 0;


}