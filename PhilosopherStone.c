/*
3923. Philosophers Stone

Problem code: BYTESM2
One of the secret chambers in Hogwarts is full of philosopher’s stones. The floor of the chamber is covered by h × w square tiles, where there are h rows of tiles from front (first row) to back (last row) and w columns of tiles from left to right. Each tile has 1 to 100 stones on it. Harry has to grab as many philosopher’s stones as possible, subject to the following restrictions:

He starts by choosing any tile in the first row, and collects the philosopher’s stones on that tile. Then, he moves to a tile in the next row, collects the philosopher’s stones on the tile, and so on until he reaches the last row.
When he moves from one tile to a tile in the next row, he can only move to the tile just below it or diagonally to the left or right.
Given the values of h and w, and the number of philosopher’s stones on each tile, write a program to compute the maximum possible number of philosopher’s stones Harry can grab in one single trip from the first row to the last row.
Input

The first line consists of a single integer T, the number of test cases. In each of the test cases, the first line has two integers. The first integer h (1<=h<=100) is the number of rows of tiles on the floor. The second integer w (1<=w<=100) is the number of columns of tiles on the floor. Next, there are h lines of inputs. The ith line of these, specifies the number of philosopher’s stones in each tile of the ith row from the front. Each line has w integers, where each integer m (0<=m<=100) is the number of philosopher’s stones on that tile. The integers are separated by a space character.

Output

The output should consist of T lines, (1<=T<=100), one for each test case. Each line consists of a single integer, which is the maximum possible number of philosopher’s stones Harry can grab, in one single trip from the first row to the last row for the corresponding test case.

Example

Input:
1
6 5
3 1 7 4 2
2 1 3 1 1
1 2 2 1 8
2 2 1 5 3
2 1 4 4 4
5 2 7 5 1

Output:
32 	

//7+1+8+5+4+7=32
*/

#include <stdio.h>

long long int dpTable[110][110];
long long int mazeMatrix[110][110];
int rows, cols;

long long int max(long long int a, long long int b, long long int c){
	long long int max = a;
	
	if(max < b)
		max = b;
	if(max < c)
		max = c;

	return max;
}

long long int recFun(long long int i, long long int j){

	long long int a, b, c;

	if(j == 0){
		if(dpTable[i + 1][j] != 0)
			a = dpTable[i + 1][j];
		else
			a = recFun(i + 1, j);
		if(dpTable[i + 1][j + 1] != 0)
			b = dpTable[i + 1][j + 1];
		else
			b = recFun(i + 1, j + 1);
		dpTable[i][j] = max(a, b, -1) + mazeMatrix[i][j];
	}
	else if(j == cols - 1){
		if(dpTable[i + 1][j - 1] != 0)
			a = dpTable[i + 1][j - 1];
		else
			a = recFun(i + 1, j - 1);
		if(dpTable[i + 1][j] != 0)
			b = dpTable[i + 1][j];
		else
			b = recFun(i + 1, j);
		dpTable[i][j] = max(a, b, -1) + mazeMatrix[i][j];
	}
	else{
		if(dpTable[i + 1][j - 1] != 0)
			a = dpTable[i + 1][j - 1];
		else
			a = recFun(i + 1, j - 1);
		if(dpTable[i + 1][j] != 0)
			b = dpTable[i + 1][j];
		else
			b = recFun(i + 1, j);
		if(dpTable[i + 1][j + 1] != 0)
			c = dpTable[i + 1][j + 1];
		else
			c = recFun(i + 1, j + 1);
		dpTable[i][j] = max(a, b, c) + mazeMatrix[i][j];
	}

	return dpTable[i][j]; 
}

int main(){
	int testCases, i, j;
	long long int maxSum, temp;
	
	scanf("%d", &testCases);

	while(testCases--){
		maxSum =  -1;
		
		scanf("%d %d", &rows, &cols);

		for(i = 0 ; i < rows ; i++){
			for(j = 0 ; j < cols ; j++){
				scanf("%lld", &mazeMatrix[i][j]);
				if(i == rows - 1)
					dpTable[i][j] = mazeMatrix[i][j];
				else
					dpTable[i][j] = 0;
			}
		}

		for(i = 0 ; i < cols ; i++){
			temp = recFun(0, i);
			if(temp > maxSum)
				maxSum = temp;
		}

		printf("%lld\n", maxSum);
	}

	return 0;
}