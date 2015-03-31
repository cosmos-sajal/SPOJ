/*
4557. Musical Chairs

Problem code: ANARC08H

In the traditional game of Musical Chairs, N + 1 children run around N chairs (placed in a circle) as long as music is playing. The moment the music stops, children run and try to sit on an available chair. The child still standing leaves the game, a chair is removed, and the game continues with N children. The last child to sit is the winner. 

In an attempt to create a similar game on these days' game consoles, you modify the game in the following manner: N Children are seated on N chairs arranged around a circle. The chairs are numbered from 1 to N . Your program pre-selects a positive number D . The program starts going in circles counting the children starting with the first chair. Once the count reaches D , that child leaves the game, removing his/her chair. The program starts counting again, beginning with the next chair in the circle. The last child remaining in the circle is the winner.

For example, consider the game illustrated in the figure above for N = 5 and D = 3 . In the figure, the dot indicates where counting starts and × indicates the child leaving. Starting off, child #3 leaves the game, and counting restarts with child #4. Child #1 is the second child to leave and counting restart with child #2 resulting in child #5 leaving. Child #2 is the last to leave, and child #4 is the winner. Write a program to determine the winning child given both N and D .

Input

Your program will be tested on one or more test cases. Each test case specifies two positive integers N and D on a single line, separated by one or more spaces, where N, D < 1,000,000 . 

The last line of the input file contains two 0's and is not part of the test cases.

Output

For each test case, write the winner using the following format: 

N D W 

Where N and D are as above, is a space character, and W is the winner of that game.

Example

Input:
5 3
7 4
0 0

Output:
5 3 4
7 4 2

URL: http://www.spoj.com/problems/ANARC08H/
*/

#include <stdio.h>

long long int func(long long int n, long long int k){
	long long int r = 1, i = 2;
	k--;

	while(i <= n){
		r = ((r + k) % i) + 1;
		i++;
	}

	return r;
}

int main(){
	long long int n, k, w;

	while(1){
		scanf("%lld %lld", &n, &k);

		if(n == 0 && k == 0)
			break;
		w = func(n, k);

		printf("%lld %lld %lld\n", n, k, w);
	}

	return 0;	
}