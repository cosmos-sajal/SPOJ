/*
15437. Tambourine

Problem code: UCV2013I

Little HH loves tambourines. He loves them so much that now he wants to build them. A tambourine is a musical instrument shown in Figure 1(a). As you can see in Figure 1(b) the tambourine is just a big circle of radius R with N smaller circles of radius r (r < R).

Figure 2: (a) A tambourine. (b) The radius of the circles is shown. (c) There is a 2N sides regular polygon inscribed in the outter circle


HH knows the radius of the small circles (r), he also knows the number of small circles that he has (N). And he knows that the small circles should be centered on the center of the even sides of a 2N sides regular polygon inscribed in the big circle (the sides of this polygon each measuring 2r), as shown on Figure 1(c). Now HH wants you to help him find the radius R of the big circle.

Input

The input contains several test cases. Each test case consists of two values r and N as described previously. (0 < r  100), (2 <= N <= 10000).


The end of input is indicated by a test case with r = N = 0.

Output

For each test case you must print a number (rounded up to two decimal places) showing the radius of the big circle to build the tambourine.

Example

Input:
1 4
2 4
1 8
0 0

Output:
2.61
5.23
5.13

URL : http://www.spoj.com/problems/UCV2013I/
*/

#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main()
{
	int r, N;
	double R;

	while(1)
	{
		scanf("%d %d", &r, &N);

		if(!r && !N)
			break;
		N *= 2;
		R = (2 * r * sin(PI / 2 - (PI / N))) / sin((2 * PI) / N);

		printf("%.2lf\n", R);
	}

	return 0;
}