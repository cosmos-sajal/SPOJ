/*
145. Aliens

Problem code: ALIENS

Aliens visited our planet with an obvious intention to find some new species for their space zoo. After entering Earth's orbit, they positioned themselves over the town of Belgrade, having detected some life-form activity on the ground. As they approached the surface, they saw a group of half-intelligent beings. Those creatures were actually competitors of the Balkan Olympiad in Informatics who were enjoying the excursion after intense contest. Aliens want to abduct all n (2<=n<=100000) competitors since they are very compassionate, and don’t want their creatures to feel lonely in the space zoo.
Aliens use tractor beam to take their prey. Tractor beam works in the following way: it projects a circle-shaped beam from the spacecraft to the ground vertically beneath it, and all beings that are found in that circle or on its boundary are taken. Projecting the tractor beam needs a certain amount of energy to be spent. As the radius of the tractor beam (radius of the circle on the ground) increases, more and more energy is required. Although extremely intelligent, aliens are much more advanced in social sciences than in programming. That’s why they are asking you to help them find the position of their spacecraft so that the energy required to take all of the n competitors is minimal.
Help our alien brothers! Write a program that will find the required minimal radius of tractor beam that contains all n competitors and the optimal spacecraft location - which is the same as the center of the circle on the ground.

Input

First line of input contains one integer c<=20 - number of test cases. Each test case begins with number n (2<=n<=100000). Then n lines follow and i-th of them contains two real numbers xi and yi (-10000.0<=xi,yi<=10000.0) representing coordinates of the i-th competitor.

Output

For each test case output radius of the tractor beam and coordinates of the spacecraft. Numbers should be rounded to two decimal places.

Example

Input:
1
6
8.0 9.0
4.0 7.5
1.0 2.0
5.1 8.7
9.0 2.0
4.5 1.0

Output:
5.00
5.00 5.00
Warning: large Input/Output data, be careful with certain languages
*/

#include <stdio.h>
#include <math.h>
#define MAX 999999999
#define MIN -999999999

int main(){
	int testCases;
	double minXXi, maxXXi, minYYi, maxYYi;
	double x, y, centerX, centerY, radius, maxDistanceFromCenter, temp;
	long long int i, n, j, k, l, m;
	double minXYi[100010],maxXYi[100010],minYXi[100010],maxYXi[100010];

	scanf("%d", &testCases);

	while(testCases--){
		minXXi = minYYi = MAX;
		maxXXi = maxYYi = MIN;
		j = k = l = m = 0;
		maxDistanceFromCenter = MIN;

		scanf("%lld", &n);

		for(i = 0 ; i < n ; i++){
			scanf("%lf %lf", &x, &y);

			if(minXXi >= x){
				if(minXXi == x){
					minXYi[j++] = y;
				}
				else{
					minXYi[0] = y;
					j = 1;
				}
				minXXi = x;

			}
			if(maxXXi <= x){
				if(maxXXi == x)
					maxXYi[k++] = y;
				else{
					maxXYi[0] = y;
					k = 1;
				}
				maxXXi = x;
			}
			if(minYYi >= y){
				if(minYYi == y)
					minYXi[l++] = x;
				else{
					minYXi[0] = x;
					l = 1;
				}
				minYYi = y;
			}
			if(maxYYi <= y){
				if(maxYYi == y)
					maxYXi[m++] = x;
				else{
					maxYXi[0] = x;
					m = 1;
				}
				maxYYi = y;
			}
		}
		/*printf("minX->%f %f\n", minXXi, minXYi);
		printf("maxX->%f %f\n", maxXXi, maxXYi);
		printf("minY->%f %f\n", minYXi, minYYi);
		printf("maxY->%f %f\n", maxYXi, maxYYi);
		*/
		centerX = (maxXXi + minXXi) / 2;
		centerY = (maxYYi + minYYi) / 2;

		for(i = 0 ; i < j ; i++){
			temp = sqrt(((minXXi - centerX) * (minXXi - centerX)) + ((minXYi[i] - centerY) * (minXYi[i] - centerY)));
			if(maxDistanceFromCenter < temp){
				maxDistanceFromCenter = temp;
				//printf("%f %f %f\n", minXXi, minXYi[i], maxDistanceFromCenter);
			}
		}
		for(i = 0 ; i < k ; i++){
			temp = sqrt(((maxXXi - centerX) * (maxXXi - centerX)) + ((maxXYi[i] - centerY) * (maxXYi[i] - centerY)));
			if(maxDistanceFromCenter < temp){
				maxDistanceFromCenter = temp;
				//printf("%f %f %f\n", maxXXi, maxXYi[i], maxDistanceFromCenter);
							}
		}
		for(i = 0 ; i < l ; i++){
			temp = sqrt(((minYXi[i] - centerX) * (minYXi[i] - centerX)) + ((minYYi - centerY) * (minYYi - centerY)));
			if(maxDistanceFromCenter < temp){
				maxDistanceFromCenter = temp;
				//printf("%f %f %f\n", minYXi[i], minYYi, maxDistanceFromCenter);
			}
		}
		for(i = 0 ; i < m ; i++){
			temp = sqrt(((maxYXi[i] - centerX) * (maxYXi[i] - centerX)) + ((maxYYi - centerY) * (maxYYi - centerY)));
			if(maxDistanceFromCenter < temp){
				maxDistanceFromCenter = temp;
				//printf("%f %f %f\n", maxYXi[i], maxYYi, maxDistanceFromCenter);
							}
		}
		radius = maxDistanceFromCenter;

		printf("%.2lf\n%.2lf %.2lf\n", radius, centerX, centerY);
	}


	return 0;
}