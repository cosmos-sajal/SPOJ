/*
13404. The Encrypted Password

Problem code: ICPC12C

Encrypting passwords is one of the most important problems nowadays, and you trust only the encryption algorithms which you invented, and you have just made a new encryption algorithm.

Given a password which consists of only lower case English letters, your algorithm encrypts this password using the following 3 steps (in this given order):

Swap two different characters of the given password (you can do this step zero or more times).
Append zero or more lower case English letters at the beginning of the output of step one.
Append zero or more lower case English letters to the end of the output of step two.
And the encrypted password is the output of step three.

You have just finished implementing the above algorithm and applied it on many passwords. Now you want to make sure that there are no bugs in your implementation, so you decided to write another program which validates the output of the encryption program. Given the encrypted password and the original password, your job is to check whether the encrypted password may be the result of applying your algorithm on the original password or not.

Input

Your program will be tested on one or more test cases. The first line of the input will be a single integer T, the number of test cases (1$ \le$T$ \le$100). Followed by the test cases, each test case is on two lines. The first line of each test case contains the encrypted password. The second line of each test case contains the original password. Both the encrypted password and the original password are at least 1 and at most 100,000 lower case English letters (from a' to z'), and the length of the original password is less than or equal the length of the encrypted password.

Output

For each test case, print on a single line one word, YES' (without the quotes) if applying the algorithm on the original password may generate the encrypted password, otherwise print NO' (without the quotes).

Example

Input:
3

abcdef

ecd

cde

ecd

abcdef

fcd

Output:
YES
YES
NO
*/

#include <stdio.h>
#include <string.h>

long long int originalPassMap[26], encryptedPassMap[26];
char originalPass[100010], encryptedPass[100010];

int main()
{
	long long int testCases, i, j, originalPassLen, encryptedPassLen, flag;

	scanf("%lld", &testCases);

	while(testCases--)
	{
		scanf("%s %s", encryptedPass, originalPass);

		originalPassLen = strlen(originalPass);
		encryptedPassLen = strlen(encryptedPass);
		for(i = 0 ; i < 26 ; i++)
			originalPassMap[i] = encryptedPassMap[i] = 0;

		for(i = 0 ; i < originalPassLen ; i++)
			originalPassMap[originalPass[i] - 'a']++;

		for(i = 0 ; i < originalPassLen ; i++)
			encryptedPassMap[encryptedPass[i] - 'a']++;

		flag = 0;

		for(i = 0 ; i < 26 ; i++)
			if(originalPassMap[i] != encryptedPassMap[i])
			{
				flag = 1;
				break;
			}

		if(!flag)
		{
			printf("YES\n");
			continue;
		}

		if(originalPassLen == encryptedPassLen)
		{
			flag = 0;
			for(i = 0 ; i < 26 ; i++)
				if(originalPassMap[i] != encryptedPassMap[i])
				{
					flag = 1;
					break;
				}
			if(!flag)
				printf("YES\n");
			else
				printf("NO\n");
			continue;
		}

		flag = 0;

		for(i = 1 ; i <= encryptedPassLen - originalPassLen ; i++)
		{
			encryptedPassMap[encryptedPass[i - 1] - 'a']--;
			encryptedPassMap[encryptedPass[i + originalPassLen - 1] - 'a']++;
			flag = 0;
			for(j = 0 ; j < 26 ; j++)
				if(originalPassMap[j] != encryptedPassMap[j])
				{
					flag = 1;
					break;
				}
			if(!flag)
				break;
		}

		if(!flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}