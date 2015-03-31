/*
370. Ones and zeros

Problem code: ONEZERO

Certain positive integers have their decimal representation consisting only of ones and zeros, and having at least one digit one, e.g. 101. If a positive integer does not have such a property, one can try to multiply it by some positive integer to find out whether the product has this property.

Input

Number K of test cases (K is approximately 1000);
in each of the next K lines there is one integer n (1 <= n <= 20000)
Output

For each test case, your program should compute the smallest multiple of the number n consisting only of digits 1 and 0 (beginning with 1).

Example

Input:
3
17
11011
17
Output:
11101
11011
11101
*/

#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool visited[20010];

struct node
{
	char str[100];
};

void init(int n)
{
	int i;

	for(i = 0 ; i < n ; i++)
		visited[i] = false;
}

void bfs(int n)
{
	int rem, val;
	queue<struct node>q;
	queue<int> remQueue;
	struct node t, temp;
	strcpy(t.str, "1");

	q.push(t);
	remQueue.push(1);
	visited[1] = true;
	while(!q.empty())
	{
		t = q.front();
		rem = remQueue.front();
		q.pop();
		remQueue.pop();

		val = (rem * 10);
		if(val % n == 0)
		{
			strcat(t.str, "0");
			printf("%s\n", t.str);
			break;
		}
		else if(visited[val % n] != true)
		{
			visited[val % n] = true;
			temp = t;
			strcat(temp.str , "0");
			q.push(temp);
			remQueue.push(val % n);
		}

		val++;
		if(val % n == 0)
		{
			strcat(t.str, "1");
			printf("%s\n", t.str);
			break;
		}
		else if(visited[val % n] != true)
		{
			visited[val % n] = true;
			temp = t;
			strcat(temp.str, "1");
			q.push(temp);
			remQueue.push(val % n);
		}		
	}
}

int main()
{
	int n, testCases;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);

		init(n);
		bfs(n);
	}

	return 0;
}