/*
17110. Black Widow Rings

Problem code: BWIDOW

Black Widow has a collection of N(numbered 1 to N) Rings. She uses the rings to attack the enemies. She has decided to use one ring for distraction.She will first throw the distraction ring and then all the other rings will be thrown through it (one at a time). Each ring has an inner and outer radius. 
A ring R1 will pass through ring R2 only if the outer radius of R1 is less than the inner radius of R2.
If she can chose a distraction ring from the given collection print the index of the ring (1-based), else print -1.

Input

The first line of the input contains an integer T denoting the number of test cases.
The first line of each test case contains a single integer N denoting the number of Rings.
Next N lines consists of Inner and Outer Radius of the ith Ring - r, R.

1 ≤ T ≤ 100
2 ≤ N ≤ 1000
1 ≤ r, R ≤ 10^7
 

Output

For each test case print the desired result in separate line.

Example

Input:
2
3
2 3
6 8
3 5
3
4 5
5 8
3 10

Output:
2
-1
*/

#include <stdio.h>
#define MIN -9999999999

int main(){
	int testCases, smallRadiusMaxPos, n, i;
	long long int arr[1010][2];
	long long int smallRadiusMax, smallRadiusCorrespondingLargerRad, largeRadiusMax;

	scanf("%d", &testCases);

	while(testCases--){
		scanf("%d", &n);

		scanf("%lld %lld", &arr[0][0], &arr[0][1]);
		smallRadiusMax = arr[0][0];
		smallRadiusMaxPos = 0;
		smallRadiusCorrespondingLargerRad = arr[0][1];
		largeRadiusMax = MIN;

		for(i = 1 ; i < n ; i++){
			scanf("%lld %lld", &arr[i][0], &arr[i][1]);
			if(smallRadiusMax <= arr[i][0]){
				if(smallRadiusMax == arr[i][0]){
					if(smallRadiusCorrespondingLargerRad < arr[i][1]){
						smallRadiusCorrespondingLargerRad = arr[i][1];
						smallRadiusMaxPos = i;
					}
				}
				else{
					smallRadiusMax = arr[i][0];
					smallRadiusCorrespondingLargerRad = arr[i][1];
					smallRadiusMaxPos = i;
				}
			}
		}

		for(i = 0 ; i < n ; i++){
			if(i != smallRadiusMaxPos){
				if(largeRadiusMax < arr[i][1])
					largeRadiusMax = arr[i][1];
			}
		}

		if(smallRadiusMax > largeRadiusMax)
			printf("%d\n", smallRadiusMaxPos + 1);
		else
			printf("-1\n");
	}

	return 0;
}