/*
9754. Egypt

Problem code: SCPC11D

A long time ago, the Egyptians figured out that a triangle with sides of length 3, 4, and 5 had a right angle as its largest angle. You must determine if other triangles have a similar property.

Input

Input represents several test cases, followed by a line containing 0 0 0. Each test case has three positive integers, less than 30,000, denoting the lengths of the sides of a triangle.

Output

For each test case, a line containing "right" if the triangle is a right triangle, and a line containing "wrong" if the triangle is not a right triangle.

Example

Input:
6 8 1025 52 606 8 10
25 52 60
5 12 13
0 0 0
5 12 130 0 0
Output:
right
wrong
right

*/

#include <stdio.h>

int main()
{
	long long int arr[3], a, b, c;
	int max, pos, flag, temp, i, j;

	while(1)
	{
		scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);

		a = arr[0];
		b = arr[1];
		c = arr[2];

		if(a == 0 && b == 0 && c == 0)
			break;

		if( a + b > c && a + c > b && b + c > a)
		{}
		else
		{
			printf("wrong-\n");
			continue;
		}

		for(i = 0 ; i < 3 ; i++)
		{
			max = arr[i];
			pos = i;
			flag = 0;

			for(j = i + 1 ; j < 3 ; j++)
			{
				if(arr[j] > max)
				{
					max = arr[j];
					pos = j;
					flag = 1;
				}
			}

			if(flag)
			{
				temp = arr[i];
				arr[i] = arr[pos];
				arr[pos] = temp;
			}
		}

		a = arr[0] * arr[0];
		b = arr[1] * arr[1];
		c = arr[2] * arr[2];

		if(a == (b + c))
			printf("right\n");
		else
			printf("wrong\n");


	}

	return 0;
}