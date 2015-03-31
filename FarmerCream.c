/*
15431. Farmer Cream

Problem code: UCV2013C

Farmer Cream is a businessman that wants to live in the suburbs. He recently bought a little farm in Creamville and wants to earn money from it. After the sell, Farmer Cream has D money a remaining to spend. He's in negotiations with an important firm of farming but he thinks they're not being honest (they're trying to steal some money). He knows the number of fences F in the farm but he doesn't know the number of plots P to farm. The firm is offering a budget B per plot, so he needs to multiply the budget per the number of plots to know the total amount of money to spend. He needs to know if he accepts the contract, for that, he
needs to have at least M money to live after the buy. Otherwise, the firm is trying to bankrupt Farmer Cream and take over the farm.

In order to do this. Farmer Cream needs your help. Assuming the fences are lines y = ax + b he only knows three things about them.

 

There is no point in the farm where 3 or more fences collides. So, in one point of the farm there'll be zero, one or two fences.
There are no parallel fences in the farm. So if we have two fences represented by y1 = a1x1 + b1 and y2 = a2x2 + b2 we assume that a1 <> a2.
All the fences collide with each other

In the example, there are 3 fences and 7 plots.

Input

The input contains several test cases, each one corresponding to a different situation. Each test case consists of a single line with four integers D F B M (1 <= F,B,M <= 10^6) and (1 <= D <= 10^18) separated by a single space. D represents the remaining money of Farmer Cream, F represents the number of fences, B represents the budget in Bsf per plot and M represents the minimum amount of money that Farmer Cream needs to live.


The end of input is indicated by a test case with D = F = B = M = 0.

Output

For each test case, you'll print: "The firm is trying to bankrupt Farmer Cream by X Bsf." where X represents the difference between money to spend plus the money he needs to survive and the money Farmer Cream has. Otherwise, you'll print "Farmer Cream will have Y Bsf to spend." where Y represents the money Farmer Cream will have to spend.

Example

Input:
160 1 70 30
500 3 50 100
250000 40 300 5000
0 0 0 0

Output:
The firm is trying to bankrupt Farmer Cream by 10 Bsf.
Farmer Cream will have 150 Bsf to spend.
The firm is trying to bankrupt Farmer Cream by 1300 Bsf.

URL : http://www.spoj.com/problems/UCV2013C/
*/

#include <stdio.h>
#define ll long long
#define SIZE 1000010

void init(ll *plotsArr)
{
	int i;
	
	plotsArr[1] = 2;
	for(i = 2 ; i < SIZE ; i++)
		plotsArr[i] = plotsArr[i - 1] + i;
}

int main()
{
	ll D, F, B, M;
	ll plotsArr[SIZE], moneyLeft;

	init(plotsArr);
	while(1)
	{
		scanf("%lld %lld %lld %lld", &D, &F, &B, &M);

		if(!D && !F && !B && !M)
			break;
		moneyLeft = D - (plotsArr[F] * B);
		if(moneyLeft >= M)
			printf("Farmer Cream will have %lld Bsf to spend.\n", moneyLeft);
		else
			printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", M - moneyLeft);
	}

	return 0;
}