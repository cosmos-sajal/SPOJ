/*
4200. Hamster flight

Problem code: HAMSTER1

There is a competition of flying hamsters in Hamsterburg. Each competing hamster is thrown from a sling. The judges rate the flight according to its length and height. Let X meters be the distance of the flight, and Y meters – maximum height to which the hamster rose during the flight. The hamster will receive K1*X + K2*Y points for such a flight. The initial speed of the hamsters is V0 m/s. Free fall acceleration is g = 10 m/s2. There is no air friction. The size of the hamster and the sling are negligible. When the hamster is thrown from the sling its height is 0 meters. You should determine the angle at which the hamster must be thrown so that he receives maximum points.

Input

The first line of input contains number t – the amount of tests. Then t tests follow one per line. The description of each test consists of three integers separated by single spaces. The first integer is V0, the second – K1, the third – K2.

Constraints

1 <= t <= 10000
1 <= V0 <= 100
0 <= K1, K2 <= 1000
0 < K1 + K2

Output

For each test output the angle in radians at which the hamster must be thrown, and the amount of points it will receive. The numbers should be separated with spaces. Print the numbers with exactly three digits in the fractional part.

Example

Input:
3
10 10 0
10 0 10
10 10 10

Output:
0.785 100.000
1.571 50.000
0.908 128.078
*/

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main()
{
	int testCases;
	double k1, k2, v, angle, score;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%lf %lf %lf", &v, &k1, &k2);

		if(k2 == 0)
			angle = PI / 2.0;
		else
			angle = atan((-4 * k1) / k2) + PI;
		angle /= 2;
		score = ((k1 * v * v * sin(2.0 * angle) )/ 10.0) + ((k2 * v * v * sin(angle) * sin(angle)) / 20.0);

		printf("%.3lf %.3lf\n", angle, score);
	}

	return 0;
}