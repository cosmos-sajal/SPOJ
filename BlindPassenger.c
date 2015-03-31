/*
10639. The Blind Passenger

Problem code: MYQ1

The seats of an Ultra Deluxe Semi-sleeper bus in Thuvax country are numbered according to the following rules: 
 
1. Seat number 1 is reserved for the bus conductor. 
2. Remaining seats are numbered as shown in the figure below: 
 
The seating arrangement is as shown below 
 
RowNo Left   Right  
      W  A   A  M  W 
                  
      01 
1     02 03  04 05 06 
2     11 10  09 08 07 
3     12 13  14 15 16
4     21 20  19 18 17
5     22 ............ 
  
A blind person enters the bus with a reservation ticket mentioning his seat number. He meets you at the start of the passage and shows you his ticket. Based on the seat number, help him find his seat by telling him the row number (1,2,...), seat position(window or aisle or middle), and the direction(left or right).

Input

First line contains a positive integer t(t<=10^5) denoting the number of test cases. 
Each of the next t lines contain a positive integer n(n<=10^9) denoting the blind person's seat number.

Output

Output one line for every test case in the following format: 
If the seat number is same as the conductor's seat, print "poor conductor" else, 
print <row_number> <seat_position> <direction> 
row_number: represents the row number from the entrance (a positive integer)  
seat_position: can be one of "W" or "A" or "M" for window, aisle and middle respectively. 
direction: can be either "L" or "R" for left or right respectively.

Example

Input:
3 
1 
2 
3

Output:
poor conductor 
1 W L 
1 A L
*/

#include <stdio.h>
#define ll long long

int main()
{
	int testCases;
	ll seatNum, rowNum, seatPos;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%lld", &seatNum);

		if(seatNum == 1)
			printf("poor conductor\n");
		else
		{
			seatNum--;
			rowNum = seatNum / 5;
			if(seatNum % 5 != 0)
				rowNum++;
			printf("%lld ", rowNum);
			seatPos = seatNum - 5 * (rowNum - 1);
			if(rowNum % 2 != 0)
			{
				switch(seatPos)
				{
					case 1 : printf("W L\n"); break;
					case 2 : printf("A L\n"); break;
					case 3 : printf("A R\n"); break;
					case 4 : printf("M R\n"); break;
					case 5 : printf("W R\n"); break;
				}
			}
			else
			{
				switch(seatPos)
				{
					case 5 : printf("W L\n"); break;
					case 4 : printf("A L\n"); break;
					case 3 : printf("A R\n"); break;
					case 2 : printf("M R\n"); break;
					case 1 : printf("W R\n"); break;
				}
			}
		}
	}

	return 0;
}