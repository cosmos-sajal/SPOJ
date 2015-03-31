/*
15436. Slick

Problem code: UCV2013H

A maritime accident has caused oil to spill onto the seas of Felipistonia, which is a major natural disaster. The Felipistonia's government wants to clean up this mess before more damage occurs. To do this, they first have to know how serious was the accident and the amount of oil that has been spilled into the sea. The only instrument the Felipistonia's government has to get
information of the magnitude of this disaster, is the use of satellite images. With these images they can estimate how much money they have to spend to clean this mess. For this, the number of slicks in the seas and the size of each slick must be know. A slick is a patch of oil floating on water. Unfortunately, the Felipistonia's people are not very bright, so they have hired you
to help them process the image.


An example of an image obtained by the satellites is shown in Figure 1(a). This image can be transformed to 0's and 1's as seen in Figure 1(b). Given this binary matrix, your job is to count the number of slicks in the ocean and their corresponding size. Two adjacent pixels in the image are considered to be in the same slick if they are in the same row or the same column.

Input

The input contains several test cases, each one corresponding to a dierent satellite image. The first line of each case contains two integers that indicate the number of rows (N) and columns (M) in the image (1 <= N,M <= 250). Then N lines follows with M integers each, containing the information of the image.


The end of input is indicated by a test case with N = M = 0. This case should not be processed.

Output

For each image, output the number of slicks in the sea. Additionally, output the size of each slick in ascending order and the number of slicks of that size.

Example

Input:
10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 1 1 1
1 1 0 0 1 0 0 1 1 1
1 0 1 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0

Output:
7
1 2
2 1
6 1
10 2
20 1

URL : http://www.spoj.com/problems/UCV2013H/
*/

#include <stdio.h>

int oceanMatrix[260][260], visitedMatrix[260][260];
long long int countMatrix[62510], pathLength;
int rows, cols;
long long int countMatrixArr[62510], numOfPathlengths, numOfPaths;
void recFun(int, int);

void right(int x, int y){
	if(y + 1 <= cols - 1 && oceanMatrix[x][y + 1] == 1 && visitedMatrix[x][y + 1] == 0){
		pathLength++;
		recFun(x, y + 1);
	}
}

void down(int x, int y){
	if(x + 1 <= rows - 1 && oceanMatrix[x + 1][y] == 1 && visitedMatrix[x + 1][y] == 0){
		pathLength++;
		recFun(x + 1, y);
	}	
}

void left(int x, int y){
	if(y - 1 >= 0 && oceanMatrix[x][y - 1] == 1 && visitedMatrix[x][y - 1] == 0){
		pathLength++;
		recFun(x, y - 1);
	}	
}

void up(int x, int y){
	if(x - 1 >= 0 && oceanMatrix[x - 1][y] == 1 && visitedMatrix[x - 1][y] == 0){
		pathLength++;
		recFun(x - 1, y);
	}	
}

void recFun(int x, int y){
	visitedMatrix[x][y] = 1;

	if(x == 0){
		if(y == 0){
			right(x, y);
			down(x, y);
		}
		else if(y == cols - 1){
			left(x, y);
			down(x, y);
		}
		else{
			left(x, y);
			right(x, y);
			down(x, y);
		}
	}
	else if(x == rows - 1){
		if(y == 0){
			up(x, y);
			right(x, y);
		}
		else if(y == cols - 1){
			up(x, y);
			left(x, y);
		}
		else{
			up(x, y);
			left(x, y);
			right(x, y);
		}
	}
	else{
		if(y == 0){
			up(x, y);
			down(x, y);
			right(x, y);
		}
		else if(y == cols - 1){
			up(x, y);
			down(x, y);
			left(x, y);
		}
		else{
			up(x, y);
			down(x, y);
			left(x, y);
			right(x, y);
		}	
	}
}

void calculate(){
	int i, j;

	numOfPathlengths = numOfPaths = 0;
	for(i = 0 ; i < rows; i++){
		for(j = 0 ; j < cols ; j++){
			if(oceanMatrix[i][j] == 1 && visitedMatrix[i][j] == 0){
				pathLength = 1;
				numOfPaths++;
				recFun(i, j);
				countMatrix[pathLength]++;
				if(countMatrix[pathLength] == 1)
					countMatrixArr[numOfPathlengths++] = pathLength;
			}
		}
	}
}

void merge(long long int *a, int low, int mid, int high)
{
    int b[62510];
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

int main(){

	int i, j;

	while(1){
		scanf("%d %d", &rows, &cols);

		if(rows == 0 || cols == 0)
			break;

		for(i = 0; i < rows ; i++)
			for(j = 0 ; j < cols ; j++){
				scanf("%d", &oceanMatrix[i][j]);
				visitedMatrix[i][j] = 0;
			}

		for(i = 0 ; i < (rows * cols + 10) ; i++)
			countMatrix[i] = 0;

		calculate();
		mergesort(countMatrixArr, 0 , numOfPathlengths - 1);

		printf("%lld\n", numOfPaths);
		for(i = 0 ; i < numOfPathlengths ; i++)
			printf("%lld %lld\n", countMatrixArr[i], countMatrix[countMatrixArr[i]]);
	}

	return 0;
}