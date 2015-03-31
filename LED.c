/*
7264. Digital LED Number

Problem code: DIGNUM

Given a digital LED pattern of a number. You have to find the number and print it. All inputs will be valid as shown.

Input

Input consists of LED patterns. Each pattern is given in set of fixed number of lines. You have to read input till EOF.

Output

Print the number corresponding to each pattern.

Example

Input:
     
 _  _  _  _  _  _ 
 _| _| _|| ||_||_ 
|_  _||_ |_|  | _|
    _     _     _ 
  ||_ |_||_   || |
  ||_|  ||_|  ||_|
 _  _  _  _     _ 
  ||_||_||_   ||_|
  |  |  | _|  ||_|


Output:

232095
164610
799518
*/

#include <stdio.h>

void detectNumber(char *a, char *b, char *c)
{
	int i;
	for(i = 0 ; a[i + 2] != '\0' ; i += 3)
	{
		if(a[i] == ' ' && a[i + 1] == ' ' && a[i + 2] == ' ' && b[i] == ' ' && b[i + 1] == ' ' && b[i + 2] == '|' && c[i] == ' ' &&  c[i + 1] == ' ' && c[i + 2] == '|')
			printf("1");
		else if(a[i] == ' ' && a[i + 1] == '_' && a[i + 2] == ' ' && b[i] == ' ' && b[i + 1] == '_' && b[i + 2] == '|' && c[i] == '|' &&  c[i + 1] == '_' && c[i + 2] == ' ')
			printf("2");
		else if(a[i] == ' ' && a[i + 1] == '_' && a[i + 2] == ' ' && b[i] == ' ' && b[i + 1] == '_' && b[i + 2] == '|' && c[i] == ' ' &&  c[i + 1] == '_' && c[i + 2] == '|')
			printf("3");
		else if(a[i] == ' ' && a[i + 1] == ' ' && a[i + 2] == ' ' && b[i] == '|' && b[i + 1] == '_' && b[i + 2] == '|' && c[i] == ' ' &&  c[i + 1] == ' ' && c[i + 2] == '|')
			printf("4");
		else if(a[i] == ' ' && a[i + 1] == '_' && a[i + 2] == ' ' && b[i] == '|' && b[i + 1] == '_' && b[i + 2] == ' ' && c[i] == ' ' &&  c[i + 1] == '_' && c[i + 2] == '|')
			printf("5");
		else if(a[i] == ' ' && a[i + 1] == '_' && a[i + 2] == ' ' && b[i] == '|' && b[i + 1] == '_' && b[i + 2] == ' ' && c[i] == '|' &&  c[i + 1] == '_' && c[i + 2] == '|')
			printf("6");
		else if(a[i] == ' ' && a[i + 1] == '_' && a[i + 2] == ' ' && b[i] == ' ' && b[i + 1] == ' ' && b[i + 2] == '|' && c[i] == ' ' &&  c[i + 1] == ' ' && c[i + 2] == '|')
			printf("7");
		else if(a[i] == ' ' && a[i + 1] == '_' && a[i + 2] == ' ' && b[i] == '|' && b[i + 1] == '_' && b[i + 2] == '|' && c[i] == '|' &&  c[i + 1] == '_' && c[i + 2] == '|')
			printf("8");
		else if(a[i] == ' ' && a[i + 1] == '_' && a[i + 2] == ' ' && b[i] == '|' && b[i + 1] == '_' && b[i + 2] == '|' && c[i] == ' ' &&  c[i + 1] == ' ' && c[i + 2] == '|')
			printf("9");
		else if(a[i] == ' ' && a[i + 1] == '_' && a[i + 2] == ' ' && b[i] == '|' && b[i + 1] == ' ' && b[i + 2] == '|' && c[i] == '|' &&  c[i + 1] == '_' && c[i + 2] == '|')
			printf("0");
	}
	printf("\n");
}

int main()
{
	char lineOne[1000], lineTwo[1000], lineThree[1000];

	while(gets(lineOne))
	{
		gets(lineTwo);
		gets(lineThree);

		detectNumber(lineOne, lineTwo, lineThree);
	}

	return 0;
}