/*

*/

// A Naive recursive solution for Rod cutting problem
#include <stdio.h>
#include <limits.h>
 
// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b)? a : b;}
 
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int val[10];

int cutRod(int price[], int n)
{
   if (n <= 0)
     return 0;
   int max_val = INT_MIN;
 
   // Recursively cut the rod in different pieces and compare different 
   // configurations
   for (int i = 0; i<n; i++)
   {
   		if(val[n - i - 1] == -1)
   		{
   			val[n - i - 1] = cutRod(price, n-i-1);
   			max_val = max(max_val, price[i] + val[n - i - 1]);	
   		}
   		else
   			max_val = max(max_val, price[i] + val[n - i - 1]);	
   }
 
   return max_val;
}

int main()
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    val[0] = 0;
    for(int i = 1 ; i < 10 ; i++)
    	val[i] = -1;
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    return 0;
}