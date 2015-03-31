/*
18938. The angry professor

Problem code: VEXPROF

The professor was very angry that no students were inside the class when he entered. You are given an array of Time and an integer K. Time[i] is the time student i arrived to the class. As a punishment, the professor allowed the students inside the class only when at least K students waits outside the class. Find the sum of total time wasted for students.

Example Scenario:

Time[] = {1,5,11,12,12}, K=2

At time 1, student0 arrives and waits outside the class.

At time 5, student1 arrives. Student0 and student1 enters inside the class.

At time 11, student2 arrives and waits outside the class.

At time 12, student3 and student4 arrives. Student2,Student3 and Student4 enters inside the class.

Time wasted for student0 = 4

Time wasted for student1 = 0

Time wasted for student2 = 1

Time wasted for student3 = 0

Time wasted for student4 = 0

Total time wasted = 5

Test cases guarantee that all the students entered inside the class. 

Input:

The first line consists of an integer t, the number of test cases. For each test case, the first line consists of two integers N(number of students) and K(as defined in the problem statement) followed by N lines each denoting the arrival time of students. 

Output:

For each test case, find the total time wasted for the students. 

Input Constraints:

1<=t<=100

1<=n<=100000

1<=K<=n

1<=Time[i]<=100 

Sample Input:

3

4 4

1

2

2

3

5 4

3

1

2

3

1

4 2

4

3

1

1 

Sample Output:

4

5

1
*/

#include <stdio.h>
#include <queue>
#define ll long long

using namespace std;


/*
struct node
{
	int time, no;
};
*/

int map[110], arr[100010];

void init()
{
	int i;

	for(i = 0 ; i <= 100 ; i++)
		map[i] = 0;
}

/*
ll findWaitingTime(int k, int maxTime)
{
	int i;
	ll temp, totalWaitTime;
	queue <struct node> q;

	temp = totalWaitTime = 0;
	for(i = 1 ; i <= maxTime ; i++)
	{
		if(map[i] != 0)
		{
			temp += map[i];
			if(temp >= k)
			{
				temp = 0;
				while(!q.empty())
				{
					totalWaitTime += ((i - q.front().time) * q.front().no);
					q.pop();
				}
			}
			else
			{
				struct node t;
				t.time = i;
				t.no = map[i];
				q.push(t);
			}
		}
	}

	return totalWaitTime;
}
*/

ll findWaitingTime(int k , int maxTime)
{
	int i;
	ll temp, totalWaitTime;

	totalWaitTime = temp = 0;
	for(i = 1 ; i <= maxTime ; i++)
	{
		if(map[i])
		{
			if(temp + map[i] >= k)
			{
				totalWaitTime += temp;
				temp = 0;
			}
			else
			{
				totalWaitTime += temp;
				temp += map[i];
			}
		}
		else
			totalWaitTime += temp;
	}

	return totalWaitTime;
}

int main()
{
	int i, n, k, maxTime, testCases;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d %d", &n, &k);
		maxTime = -1;
		init();
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d", &arr[i]);
			if(maxTime < arr[i])
				maxTime = arr[i];
			map[arr[i]]++;
		}
		
		printf("%lld\n", findWaitingTime(k, maxTime));
	}

	return 0;
}