/*
3410. Feynman

Problem code: SAMER08F

Richard Phillips Feynman was a well known American physicist and a recipient of the Nobel Prize in Physics. He worked in theoretical physics and also pioneered the field of quantum computing. He visited South America for ten months, giving lectures and enjoying life in the tropics. He is also known for his books "Surely You're Joking, Mr. Feynman!" and "What Do You Care What Other People Think?", which include some of his adventures below the equator.

His life-long addiction was solving and making puzzles, locks, and cyphers. Recently, an old farmer in South America, who was a host to the young physicist in 1949, found some papers and notes that is believed to have belonged to Feynman. Among notes about mesons and electromagnetism, there was a napkin where he wrote a simple puzzle: "how many different squares are there in a grid of N ×N squares?".

In the same napkin there was a drawing which is reproduced below, showing that, for N=2, the answer is 5.

Input

The input contains several test cases. Each test case is composed of a single line, containing only one integer N, representing the number of squares in each side of the grid (1 ≤ N ≤ 100).

The end of input is indicated by a line containing only one zero.

Output

For each test case in the input, your program must print a single line, containing the number of different squares for the corresponding input.

Example

Input:
2
1
8
0


Output:
5
1
204
*/

#include <stdio.h>

int main()
{
	int squares[100];
	int i, number;

	squares[0] = 1;

	for(i = 1 ; i < 100 ; i++)
		squares[i] = (i + 1)*(i + 1) + squares[i-1];
	
	while(1)
	{
		scanf("%d",&number);

		if(number == 0)
			break;

		printf("%d\n",squares[number-1]);
	}


	return 0;
}