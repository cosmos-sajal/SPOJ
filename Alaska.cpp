/*
9756. Alaska
Problem code: SCPC11B

 
The Alaska Highway runs 1422 miles from Dawson Creek, British Columbia to Delta Junction, Alaska. 
Brenda would like to be the first person to drive her new electric car the length of the highway. Her car can travel up to 200 miles once charged at a special charging station. There is a charging station in Dawson Creek, where she begins her journey, and also several charging stations along the way. Can Brenda drive her car from Dawson City to Delta Juntion and back?

 

The Alaska Highway runs 1422 miles from Dawson Creek, British Columbia to Delta Junction, Alaska. 

Brenda would like to be the first person to drive her new electric car the length of the highway. Her car can travel up to 200 miles once charged at a special charging station. There is a charging station in Dawson Creek, where she begins her journey, and also several charging stations along the way. Can Brenda drive her car from Dawson City to Delta Juntion and back?

 

 
Input

The input contains several scenario. Each scenario begins with a line containing n, a positive number indicating the number of charging stations. n lines follow, each giving the location of a filling station on the highway, including the one in Dawson City. The location is an integer between 0 and 1422, inclusive, indicating the distance in miles from Dawson Creek. No two filling stations are at the same location. A line containing 0 follows the last scenario.
Output

 

For each scenario, output a line containing POSSIBLE if Brenda can make the trip.

Otherwise, output a line containing the word IMPOSSIBLE.

 
Example

Input:
2
0
900
8
1400
1200
1000
800
600
400
200
0
0

Output:
IMPOSSIBLE
POSSIBLE
*/

#include <stdio.h>
#include <algorithm>

int main()
{
	int n, i, arr[1500], flag;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
			break;
		for(i = 0 ; i < n ; i++)
			scanf("%d", &arr[i]);

		std :: sort(arr, arr + n);
		flag = 0;
		for(i = 1 ; i < n ; i++)
		{
			if(arr[i] - arr[i - 1] > 200)
			{
				flag = 1;
				break;
			}
		}
		if(arr[n - 1] < 1322)
			flag = 1;
		if(flag)
			printf("IMPOSSIBLE\n");
		else
			printf("POSSIBLE\n");

	}

	return 0;
}