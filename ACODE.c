/*

SPOJ Problem Set (classical)

394. Alphacode

Problem code: ACODE

Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:

Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”
Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”
Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”
Alice: “How many different decodings?”
Bob: “Jillions!”

For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.

Input

Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.

Output

For each input set, output the number of possible decodings for the input string. All answers will be within the range of a 64 bit signed integer.

Example

Input:

25114
1111111111
3333333333
0

Output:

6
89
1
*/

#include <stdio.h>

int canCombine(char currNum,char prevNum)
{
	if(prevNum == '1')
		return 1;
	else if(prevNum == '2' && (currNum > '0' && currNum < '7'))
		return 1;
	else
		return 0;	
}


int main()
{
	char number[5001];
	int i;
	long long int curr = 1, prev = 0,temp;
	int flag = 0;
	int invalidFlag = 0;
	int canCombineFlag = 0;

	while(1)
	{
		curr = 1;
		prev = flag = invalidFlag = canCombineFlag = 0;

		scanf("%s",number);

		if(number[0] == '0')
		{
			break;
		}

		for(i = 1 ; number[i] != '\0' ; i++)
		{
			if(number[i] == '0' && (number[i-1] > '2' || number[i-1] == '0'))
			{
				invalidFlag = 1;
				break;
			}

			if(number[i] == '0' && (number[i-1] == '1' || number[i-1] == '2'))
			{	
				if(flag)
				{
					flag = 0;
					curr = curr - (curr-prev);
				}
				continue;
			}
			

			if(number[i-1] == '0')
				continue;
			

			canCombineFlag = canCombine(number[i],number[i-1]);

			//printf("%c %c %d\n",number[i-1],number[i],canCombineFlag);

			if(!flag && canCombineFlag)
			{
				prev = curr;
				curr = curr * 2;
				flag = 1;
			}
			else if(flag && canCombineFlag)
			{
				temp = prev;
				prev = curr;
				curr = curr + temp;
				flag = 1;
			}
			else
			{
				flag = 0;
				continue;
			}

		}

		if(invalidFlag)
			printf("0\n");
		else
			printf("%lld\n",curr);

	}

	return 0;
}