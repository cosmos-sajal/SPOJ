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

long long int arr[1235][5679];


int main()
{
	
	long long int i, j;
	long long int row[1235], col[5679];
	char option;
	long long int row1 = -1, row2 = -1, col1 = -1, col2 = -1, rowNo = -1, colNo = -1;
	long long int num, temp;
	char line[50];
	char c;

	for(i = 1 ; i < 1235 ; i++)
		for(j = 1 ; j < 5679 ; j++)
			arr[i][j] = (i - 1) * 5678 + j;

	for(i = 1 ; i < 1235 ; i++)
		row[i] = i;

	for(i = 1 ; i < 5679 ; i++)
		col[i] = i;

	//while(scanf("%s",line) != -1)
	while(cin >> c)
	{
		//if(line[0] == ' ')
//			continue;

//		if(line[0] == 'R' || line[0] == 'Q' || line[0] == 'W' || line[0] == 'C')
//		{
//			option = line[0];
//			continue;
//		}

//		switch(option)
		switch(c)
		{
			case 'R' : 
						{
							//if(row1 == -1)
							//	row1 = atoi(line);
							//else
							//{
							//	row2 = atoi(line);
								scanf("%lld%lld", &row1, &col1);
								temp = row[row1];
								row[row1] = row[row2];
								row[row2] = temp;
								//row1 = row2 = -1;
							//}
						}
						break;
			case 'C' :
						{
							//if(col1 == -1)
							//	col1 = atoi(line);
							//else
							//{
							//	col2 = atoi(line);
								scanf("%lld%lld", &row1, &col1);
								temp = col[col1];
								col[col1] = col[col2];
								col[col2] = temp;
								col1 = col2 = -1;
							//}	
						}
						break;
			case 'Q' :
						{
							//if(rowNo == -1)
							//	rowNo = atoi(line);
							//else
							//{
							//	colNo = atoi(line);
								scanf("%lld%lld", &rowNo, &colNo);
								printf("%lld\n",arr[row[rowNo]][col[colNo]]);
								rowNo = colNo = -1;
							//}
						}
						break;
			case 'W' :
						{
							//num = atoi(line);
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
							printf("%lld %lld\n", row[rowNo], col[colNo]);
							rowNo = colNo = -1;
						}
						break;
		}
	}
	
	return 0;
}