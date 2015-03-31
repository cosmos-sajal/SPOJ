/*
15980. Ascending Fibonacci Numbers

Problem code: ASCDFIB

John is trying to learn the Fibonacci sequence. This is what he has learned so far. The first two terms of the sequence are f(1) = 0 and f(2) = 1.  The next term f(n) is then calculated by adding the previous two terms f(n-1) and f(n-2). Therefore,

f(1) = 0

f(2) = 1

f(3) = f(2) + f(1) = 1 + 0 = 1

f(4) = f(3) + f(2) = 1 + 1 = 2

f(5) = f(4) + f(3) = 2 + 1 = 3

f(6) = f(5) + f(4) = 3 + 2 = 5

After calculating this for a while, John realized that the values are becoming too big. In order to keep the values small, John changed his algorithm. Instead of calculating f(n) = f(n-1)+f(n-2), he decided he will calculate f(n) = ( f(n-1)+f(n-2) ) % 10^5.

Now John wants to do some research on his new modified Fibonacci sequence. He will give you an integer A (A<=10^5) and an integer B (B<=10^6). You have to output all the terms from f(A) to f(A+B) in ascending order (non-decreasing order). But printing so many numbers is too much of a hassle. So, if there are more than 100 terms in the output, then only print the first 100.

Input

The first line contains an integer T (T<=100), which is the number of test cases. 
Each test case contains two positive integers A and B as mentioned before.

Output

For each test case, print case number (Check sample output) and then print the terms from f(A)  to f(A+B) in ascending order (non-decreasing order). If there are more than 100 terms in the output, then only print the first 100.

Example

Input:
3
1 3
3 3
100 1

Output:

Case 1: 0 1 1 2
Case 2: 1 2 3 5
Case 3: 15075 69026
*/

#include <stdio.h>
#define MOD 100000


long long int fibArr[1100010];
long long int heap[1100010], heapSize;

void precompute(){
	long long int i;

	fibArr[0] = 0;
	fibArr[1] = 0;
	fibArr[2] = 1;

	for(i = 3 ; i < 1100001 ; i++)
		fibArr[i] = (fibArr[i - 1] + fibArr[i - 2]) % MOD;
}

/*Initialize Heap*/
void Init()
{
        heapSize = 0;
        heap[0] = -9999999999;
}
/*Insert an element into the heap */
void Insert(long long int element)
{
        heapSize++;
        heap[heapSize] = element; /*Insert in the last place*/
        /*Adjust its position*/
        long long int now = heapSize;
        while(heap[now/2] > element) 
        {
                heap[now] = heap[now/2];
                now /= 2;
        }
        heap[now] = element;
}

long long int DeleteMin()
{
        /* heap[1] is the minimum element. So we remove heap[1]. Size of the heap is decreased. 
           Now heap[1] has to be filled. We put the last element in its place and see if it fits.
           If it does not fit, take minimum element among both its children and replaces parent with it.
           Again See if the last element fits in that place.*/
        long long int minElement,lastElement,child,now;
        minElement = heap[1];
        lastElement = heap[heapSize--];
        /* now refers to the index at which we are now */
        for(now = 1; now*2 <= heapSize ;now = child)
        {
                /* child is the index of the element which is minimum among both the children */ 
                /* Indexes of children are i*2 and i*2 + 1*/
                child = now*2;
                /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only one 
                  child */
                if(child != heapSize && heap[child+1] < heap[child] ) 
                {
                        child++;
                }
                /* To check if the last element fits ot not it suffices to check if the last element
                   is less than the minimum element among both the children*/
                if(lastElement > heap[child])
                {
                        heap[now] = heap[child];
                }
                else /* It fits there */
                {
                        break;
                }
        }
        heap[now] = lastElement;
        return minElement;
}


int main(){
	int testCases;
	long long int a, b, i, j, k = 1;

	scanf("%d", &testCases);

	precompute();

	while(testCases--){
		Init();

		scanf("%lld %lld", &a, &b);

		for(i = a, j = 0 ; i <= a + b ; i++, j++)
			Insert(fibArr[i]); 

		//mergesort(0, j - 1);

		if(b <= 100){
			printf("Case %lld: ", k++);
			for(i = 0 ; i < j - 1 ; i++)
				printf("%lld ", DeleteMin());
			printf("\n");
		}
		else{
			printf("Case %lld: ", k++);
			for(i = 0 ; i < 100 ; i++)
				printf("%lld ", DeleteMin());
			printf("\n");
		}
	}

	return 0;
}