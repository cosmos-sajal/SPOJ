// A Naive recursive program to find minimum number insertions
// needed to make a string palindrome
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// An LCS based program to find minimum number insertions needed to
// make a string palindrome

   char str[6200];
   char rev[6200];
   int L[6200][6200];

 
/* Utility function to get max of 2 integers */
int max(int a, int b)
{   return (a > b)? a : b; }
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1]. 
   See http://goo.gl/bHQVP for details of this function */
int lcs(int m, int n )
{
   
   int i, j;
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
 
       else if (str[i-1] == rev[j-1])
         L[i][j] = L[i-1][j-1] + 1;
 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

// LCS based function to find minimum number of insersions
int findMinInsertionsLCS(int n)
{
   // Creata another string to store reverse of 'str'
   
   int i, j;
   for(i = 0, j = n - 1 ; i < n ; i++, j--)
   {
        rev[i] = str[j];
   }

   rev[n] = '\0';
 
   // The output is length of string minus length of lcs of
   // str and it reverse
   return (n - lcs(n, n));
}
 


// Driver program to test above functions
int main()
{
    int testCases;
 

    scanf("%d",&testCases);

    while(testCases--)
    {
        scanf("%s",str);
        printf("%d\n", findMinInsertionsLCS(strlen(str)));
    }
    return 0;
}