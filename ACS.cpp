/*
376. A concrete simulation

Problem code: ACS

You are given a matrix M of type 1234x5678. It is initially filled with integers 1...1234x5678 in row major order. Your task is to process a list of commands manipulating M. There are 4 types of commands: 
"R x y" swap the x-th and y-th row of M ;
"C x y" swap the x-th and y-th column of M ;
"Q x y" write out M(x,y) ;
"W z" write out x and y where z=M(x,y).

Input

A list of valid commands. Input terminated by EOF.

Output

For each "Q x y" write out one line with the current value of M(x,y), for each "W z" write out one line with the value of x and y ( interpreted as above ) separated by a space.

Input:
R 1 2
Q 1 1
Q 2 1
W 1
W 5679
C 1 2
Q 1 1
Q 2 1
W 1
W 5679

Output:
5679
1
2 1
1 1
5680
2
2 2
1 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	
	int i, j;
	int row[1235], col[5679];
	int row1 = -1, row2 = -1, col1 = -1, col2 = -1, rowNo = -1, colNo = -1;
	int num, temp;
	char c;

	for(i = 1 ; i < 1235 ; i++)
		row[i] = i;

	for(i = 1 ; i < 5679 ; i++)
		col[i] = i;

	
	while(cin >> c)
	{
	switch(c)
		{
			case 'R' : 
						{
							scanf("%d%d", &row1, &row2);
							temp = row[row1];
							row[row1] = row[row2];
							row[row2] = temp;
							
						break;
			case 'C' :
						{
							scanf("%d%d", &col1, &col2);
							temp = col[col1];
							col[col1] = col[col2];
							col[col2] = temp;
						}
						break;
			case 'Q' :
						{
							scanf("%d%d", &rowNo, &colNo);
							printf("%d\n", (row[rowNo] - 1) * 5678 + col[colNo]);
						}
						break;
			case 'W' :
						{
							
							scanf("%d", &num);
							if(num % 5678 == 0)
							{
								rowNo = num / 5678;
								colNo = num % 5678;
								if(colNo == 0)
									colNo = 5678;
							}
							else
							{
								rowNo = (num / 5678) + 1;
								colNo = num % 5678;
							}
							for(i = 1 ; i < 1235 ; i++)
							{
								if(row[i] == rowNo)
									break;
							}
							for(j = 0 ; j < 5679 ; j++)
							{
								if(col[j] == colNo)
									break;
							} 
							printf("%d %d\n",i,j);
						}
						break;
		}
	}
	
	return 0;
}