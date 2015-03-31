/*
2178. He is offside!

Problem code: OFFSIDE

Hemisphere Network is the largest television network in Tumbolia, a small country located east of South America (or south of East America). The most popular sport in Tumbolia, unsurprisingly, is soccer; many games are broadcast every week in Tumbolia.

Hemisphere Network receives many requests to replay dubious plays; usually, these happen when a player is deemed to be offside by the referee. An attacking player is offside if he is nearer to his opponents’ goal line than the second last opponent. A player is not offside if

he is level with the second last opponent or
he is level with the last two opponents.
Through the use of computer graphics technology, Hemisphere Network can take an image of the field and determine the distances of the players to the defending team’s goal line, but they still need a program that, given these distances, decides whether a player is offside.

Input

The input file contains several test cases. The first line of each test case contains two integers A and D separated by a single space indicating, respectively, the number of attacking and defending players involved in the play (2 <= A,D <= 11). The next line contains A integers Bi separated by single spaces, indicating the distances of the attacking players to the goal line (1 <= Bi <= 104). The next line contains D integers Cj separated by single spaces, indicating the distances of the defending players to the goal line (1 <= Cj <= 104). The end of input is indicated by A = D = 0.

Output

For each test case in the input print a line containing a single character: “Y” (uppercase) if there is an attacking player offside, and “N” (uppercase) otherwise.

Example

Input:
2 3
500 700
700 500 500
2 2
200 400
200 1000
3 4
530 510 490
480 470 50 310
0 0

Output:
N
Y
N
*/

#include <stdio.h>
#define ll long long

ll attackerArr[11], defenderArr[11];

void merge(long long int *a, int low, int mid, int high)
{
    int b[10000];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
  
    while (j <= high)
        b[k++] = a[j++];
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}
  
void mergesort(long long int *a, int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

int main()
{
	int attackers, defenders, i, offsideFlag;
	ll secondlastDefenderPos, attackerPos;

	while(1)
	{
		scanf("%d %d", &attackers, &defenders);
		if(!attackers && !defenders)
			break;
		for(i = 0 ; i < attackers ; i++)
			scanf("%lld", &attackerArr[i]);
		for(i = 0 ; i < defenders ; i++)
			scanf("%lld", &defenderArr[i]);
		
		offsideFlag = 1;
		mergesort(attackerArr, 0 , attackers - 1);
		mergesort(defenderArr, 0, defenders - 1);
		secondlastDefenderPos = defenderArr[1];
		attackerPos = attackerArr[0];
		if(attackerPos >= secondlastDefenderPos)
			offsideFlag = 0;
		
		if(offsideFlag)
			printf("Y\n");
		else
			printf("N\n");
	}

	return 0;
}