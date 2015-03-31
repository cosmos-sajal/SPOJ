/*
9655. Elevator Trouble

Problem code: ELEVTRBL

You are on your way to your rst job interview as a program tester, and you are already
late. The interview is in a skyscraper and you are currently in 
oor s, where you see an
elevator. Upon entering the elvator, you learn that it has only two buttons, marked UP
u" and DOWN d". You conclude that the UP-button takes the elevator u 
floors up
(if there aren't enough 
oors, pressing the UP-botton does nothing, or at least so you
assume), whereas the DOWN-button takes you d stories down (or none if there aren't
enough). Knowing that the interview is at 
floor g, and that there are only f 
floors in
the building, you quickly decide to write a program that gives you the amount of button
pushes you need to perform. If you simply cannot reach the correct 
floor, your program
halts with the message "use the stairs".
Given input f, s, g, u and d (
floors, start, goal, up, down), nd the shortest sequence
of button presses you must press in order to get from s to g, given a building of floors,
or output "use the stairs" if you cannot get from s to g by the given elevator.

Input

The input will consist of one line, namely f s g u d, where 1 <= s; g <= f <= 1000000 and
0 <= u; d <= 1000000. The 
floors are one-indexed, i.e. if there are 10 stories, s and g be in
[1; 10].

Output

You must reply with the minimum numbers of pushes you must make in order to get from
s to g, or output use the stairs if it is impossible given the conguration of the elvator.

Example

Input:
10 1 10 2 1
Output:
6
*/

#include <stdio.h>
#include <queue>

using namespace std;

int visited[1000010];

struct node
{
	int floorNo;
	int stepNo;
};

int main()
{
	int noOfFloors, start, goal, up, down, result;

	scanf("%d %d %d %d %d", &noOfFloors, &start, &goal, &up, &down);
	queue<struct node> q;
	struct node temp;
	temp.floorNo = start;
	temp.stepNo = 0;
	q.push(temp);
	visited[start] = 1;
	result = -1;
	if(start == goal)
	{
		printf("0\n");
		return 0;
	}
	while(!q.empty())
	{
		struct node * ptr = &(q.front());
		q.pop();
		if(!visited[ptr->floorNo + up])
		{
			if(ptr->floorNo + up == goal)
			{
				result = ptr->stepNo + 1;
				break;
			}
			else
			{
				visited[ptr->floorNo + up] = 1;
				temp.floorNo = ptr->floorNo + up;
				temp.stepNo = ptr->stepNo + 1;
				q.push(temp);
			}
		}
		if(!visited[ptr->floorNo - down])
		{
			if(ptr->floorNo - down == goal)
			{
				result = ptr->stepNo + 1;
				break;
			}
			else
			{
				visited[ptr->floorNo - down] = 1;
				temp.floorNo = ptr->floorNo - down;
				temp.stepNo = ptr->stepNo + 1;
				q.push(temp);
			}	
		}
	}

	if(result == -1)
		printf("use the stairs\n");
	else
		printf("%d\n", result);

	return 0;
}