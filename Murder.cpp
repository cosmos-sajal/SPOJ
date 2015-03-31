/*
10810. Its a Murder!

Problem code: DCEPC206

Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.

Input

First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.

Output

For each test case output one line giving the final sum for each test case.

Constraints

T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.

Example

Input:
1
5
1 5 3 6 4

Output:
15
*/

#include <stdio.h>

long long int count;

void merge(long long int *a, int low,long long int mid,long long int high)
{
    int b[1000010];
    long long int i = low, j = mid + 1, k = 0;
    long long int length = high - mid;
  
    while (i <= mid && j <= high) 
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i];
            count += (a[i] * length);
            i++; 
        }
        else
        {
            b[k++] = a[j++];
            length--;
        }
    }
    while (i <= mid)
        b[k++] = a[i++];
  
    while (j <= high)
        b[k++] = a[j++];
  
    k--;
    while (k >= 0) 
    {
        a[low + k] = b[k];
        k--;
    }
}
  
void mergesort(long long int *a,long long int low,long long int high)
{
    if (low < high) 
    {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

int main()
{
    int testCases;
    long long int arr[1000010], i , n;

    scanf("%d",&testCases);

    while(testCases--)
    {
        scanf("%lld",&n);

        for(i = 0 ; i < n ; i++)
            scanf("%lld",&arr[i]);

        count = 0;
        mergesort(arr, 0 , n - 1);

        printf("%lld\n", count);
    }

    return 0;
}
