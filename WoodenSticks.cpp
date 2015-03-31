/*
3937. Wooden Sticks

Problem code: MSTICK

There is a pile of  n  wooden sticks. The length and weight of each stick
are known in advance. The sticks are to be processed by a woodworking machine
in one by one fashion. It needs some time, called setup time, for the  machine
to  prepare  processing  a  stick.  The  setup  times  are  associated  with
cleaning  operations  and changing tools and shapes in the machine. The setup
times of the woodworking machine are given as follows: 
 
(a) The setup time for the first wooden stick is 1 minute. 
(b) Right after processing a stick of length  l  and weight  w , the machine will
need no setup time for a stick of length  l'  and weight  w'  if  l ≤ l' and  w ≤ w'. 
Otherwise, it will need 1 minute for setup. 
 
You are to find the minimum setup time to process a given pile of  n  wooden sticks. 
For example, if you have five sticks whose pairs of length and weight are  
( 9 , 4 ) , ( 2 , 5 ) , ( 1 , 2 ) , ( 5 , 3 ) , and ( 4 , 1 ) , then the minimum
setup time should be 2 minutes since there is a sequence of pairs ( 4 , 1 ) , 
( 5 , 3 ) , ( 9 , 4 ) , ( 1 , 2 ) , ( 2 , 5 ) .
Input

The input consists of T test cases. The number of test cases (T) is given 
in the first line of the input file. Each test case consists of two lines:
 The first line has an integer n , 1 <= n <= 5000 , that represents the number 
of wooden sticks in the test case, and the second line contains 2n positive
integers l1 , w1 , l2 , w2 ,..., ln , wn , each of magnitude at most 10000 ,
where li and wi are the length and weight of the i th wooden stick, respectively.
The 2n integers are delimited by one or more spaces.

SAMPLE INPUT
3 
5 
4 9 5 2 2 1 3 5 1 4 
3 
2 2 1 1 2 2 
3 
1 3 2 2 3 1 

Output

 
The output should contain the minimum setup time in minutes, one per line. 

SAMPLE OUTPUT
2
1
3
*/

#include <stdio.h>

int weightArr[5010], lengthArr[5010];

void merge(int *a, int low, int mid, int high)
{
    int b[5010], c[5010];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
        {
            if(a[i] == a[j])
            {
                if(weightArr[i] < weightArr[j])
                {
                    b[k] = a[i];
                    c[k++] = weightArr[i++];
                }
                else
                {
                    b[k] = a[j];
                    c[k++] = weightArr[j++];
                }
            }
            else
            {
                b[k] = a[i];
                c[k++] = weightArr[i++];
            }
        }
        else
       	{
            b[k] = a[j];
            c[k++] = weightArr[j++];
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        c[k++] = weightArr[i++];
    }
  
    while (j <= high)
    {
        b[k] = a[j];
        c[k++] = weightArr[j++];
    }
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        weightArr[low + k] = c[k];
        k--;
    }
}
  
void mergesort(int *a, int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

void print(int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
        printf("%d %d\n", lengthArr[i], weightArr[i]);
}

int main()
{
	int testCases, n, i, temp, j;
	long long int setupTime;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);
		
		for(i = 0 ; i < n ; i++)
			scanf("%d %d", &lengthArr[i], &weightArr[i]);

		mergesort(lengthArr, 0, n - 1);
		//print(n);
        setupTime = n;
        for(i = 0 ; i < n ; i++)
        {
            temp = weightArr[i];
            if(temp == -1)
                continue;
            else
                weightArr[i] = -1;
            for(j = i + 1 ; j < n ; j++)
            {
                if(weightArr[j] == -1)
                    continue;
                if(weightArr[j] >= temp)
                {
                    setupTime--;
                    temp = weightArr[j];
                    weightArr[j] = -1;
                }
            }
        }

		printf("%lld\n", setupTime);
	}

	return 0;
}