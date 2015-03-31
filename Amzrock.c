/*
11932. Amz Rock

Problem code: AMZRCK

To many people in many cultures, music is an important part of their way of life.

 

AmzMohammad is a fan of rock music. and he have n rock tracks (labled from 1 to n) now he wanna select a playlist.in his opinion a good playlist is one that have no two successive tracks.in how many ways?
 

AmzMohammad is a fan of rock music. and he have n rock tracks (labled from 1 to n) now he wanna select a playlist.

in his opinion a good playlist is one that have no two successive tracks.

in how many ways?

 

 

 

Input

first line = number of test cases

each testcase in an integer n(number of tracks)

Output

Output number of good playlists he can make.

answer is less than 1000000000. it is the only constraint :)

Example

Input:
 2
1
2

Output:
2
3
note: a good play list may consist 0 track :)
note 2: how many persian rock tracks we have?
*/

#include <stdio.h>

long long int arr[10000010];

void precomputation()
{
	long long int i;

	arr[0] = 1;
	arr[1] = 2;

	for(i = 2 ; arr[i - 1] < 1000000000 ; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

}

int main()
{
	long long int testCases;
	int num;

	scanf("%lld",&testCases);

	precomputation();

	while(testCases--)
	{
		scanf("%d", &num);
		printf("%lld\n", arr[num]);
	}

	return 0;
}