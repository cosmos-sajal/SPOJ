/*
4033. Phone List

Problem code: PHONELST

Phone List Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another. Let’s say the phone catalogue listed these numbers:

• Emergency 911

• Alice 97 625 999

• Bob 91 12 54 26

In this case, it’s not possible to call Bob, because the central would direct your call to the emergency line as soon as you had dialled the first three digits of Bob’s phone number. So this list would not be consistent.

Input

The first line of input gives a single integer, 1 <= t <= 40, the number of test cases. Each test case starts with n, the number of phone numbers, on a separate line, 1 <= n <= 10000. Then follows n lines with one unique phone number on each line. A phone number is a sequence of at most ten digits.

Output

For each test case, output “YES” if the list is consistent, or “NO” otherwise.

Example

Input:
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346

Output:
NO
YES
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node *link[10];
	int endOfNumber[10];
};

struct node *start = NULL, *ptr = NULL, *temp = NULL, *prev = NULL;
int flagForPrefix = 0;

void init()
{
	flagForPrefix = 0;
	start = ptr = temp = prev = NULL;
}

void insert(char *phoneNo)
{
	int i, j;

	if(start == NULL)
	{
		start = (struct node *)malloc(sizeof(struct node));
		start->data = ' ';
		for(i = 0 ; i < 10 ; i++)
		{	
			start->link[i] = NULL;
			start->endOfNumber[i] = 0;
		}
		prev = start;
		for(i = 0 ; phoneNo[i] != '\0' ; i++)
		{
			ptr = (struct node *)malloc(sizeof(struct node));
			ptr->data = phoneNo[i];
			for(j = 0 ; j < 10 ; j++)
			{
				ptr->link[j] = NULL;
				ptr->endOfNumber[j] = 0;
			}
			if(phoneNo[i + 1] == '\0')
				ptr->endOfNumber[phoneNo[i] - '0'] = 1;
			prev->link[phoneNo[i] - '0'] = ptr;
			prev = ptr;
		}
	}
	else
	{
		prev = start;
		ptr = start->link[phoneNo[0] - '0'];
		for(i = 0 ; phoneNo[i] != '\0' ; i++)
		{
			if(ptr == NULL)
			{
				ptr = (struct node *)malloc(sizeof(struct node));
				ptr->data = phoneNo[i];
				for(j = 0 ; j < 10 ; j++)
				{
					ptr->link[j] = NULL;
					ptr->endOfNumber[j] = 0;
				}
				if(phoneNo[i + 1] == '\0')
					ptr->endOfNumber[phoneNo[i] - '0'] = 1;
				prev->link[phoneNo[i] - '0'] = ptr;
				prev = ptr;
				if(phoneNo[i + 1] != '\0')
					ptr = ptr->link[phoneNo[i + 1] - '0'];
			}
			else
			{
				if(ptr->endOfNumber[phoneNo[i] - '0'] == 1)
					flagForPrefix = 1;
				else
				{
					if(phoneNo[i + 1] == '\0')
					{
						flagForPrefix = 1;
						ptr->endOfNumber[phoneNo[i] - '0'] = 1;
						break;
					}
					else
						ptr->endOfNumber[phoneNo[i] - '0'] = 0;
				}
				if(phoneNo[i + 1] != '\0')
				{
					prev = ptr;
					ptr = ptr->link[phoneNo[i + 1] - '0'];
				}
			}
		}
	}
}

int main()
{
	int i, n, testCases;
	char phoneNo[15];

	scanf("%d", &testCases);

	while(testCases--)
	{
		init();
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++)
		{
			scanf("%s", phoneNo);
			if(!flagForPrefix)
				insert(phoneNo);
		}
		if(!flagForPrefix)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}