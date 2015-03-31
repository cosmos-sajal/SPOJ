/*
13043. The Mirror of Galadriel

Problem code: AMR12D

With water from the stream Galadriel filled the basin to the brim, and breathed on it, and when the water was still again she spoke. 'Here is the Mirror of Galadriel,' she said. 'I have brought you here so that you may look in it, if you will. For this is what your folk would call magic, I believe; though I do not understand clearly what they mean; and they seem also to use the same word of the deceits of the Enemy. But this, if you will, is the magic of Galadriel. Did you not say that you wished to see Elf-magic?' - Galadriel to Frodo and Sam, describing her Mirror.

We call a string S magical if every substring of S appears in Galadriel's Mirror (under lateral inversion). In other words, a magical string is a string where every substring has its reverse in the string.

Given a string S, determine if it is magical or not.

 

Input (STDIN):

The first line contains T, the number of test cases. The next T lines contain a string each. 

 

Output (STDOUT):

For each test case, output "YES" if the string is magical, and "NO" otherwise.

 

Constraints:

1 <= T <= 100

1 <= |S| <= 10

S contains only lower-case characters.

 

Sample Input:

2

aba

ab

 

Sample Output:

YES

NO

 

Notes/Explanation of Sample Input:

For the first test case, the list of substrings are : a, b, ab, ba, aba. The reverse of each of these strings is present as a substring of S too.

For the second test case, the list of substring are : a, b, ab. The reverse of "ab", which is "ba" is not present as a substring of the string
*/

#include <stdio.h>
#include <set>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int testCases, len, i, j, k, l;
	char str[20], tempWord[20], revWord[20], flag;

	scanf("%d", &testCases);
	getc(stdin);

	while(testCases--)
	{
		gets(str);

		flag = 0;
		set<string> s;
		len = strlen(str);
		for(i = 0 ; i < len ; i++)
		{
			for(j = i ; j < len ; j++)
			{
				for(k = i, l= 0 ; k <= j ; k++, l++)
					tempWord[l] = str[k];
				tempWord[l] = '\0';
				s.insert(tempWord);
			}
		}
		/*set<string> :: iterator it;
		for(it = s.begin() ; it != s.end() ; it++)
			cout<< *it<<endl;
*/
		for(i = 0 ; i < len ; i++)
		{
			for(j = i ; j < len ; j++)
			{
				for(k = i, l= 0 ; k <= j ; k++, l++)
					tempWord[l] = str[k];
				tempWord[l] = '\0';
				l--;
				for(k = 0 ; l >= 0 ; k++, l--)
					revWord[k] = tempWord[l];
				revWord[k] = '\0';
				set<string> :: iterator it = s.find(revWord);
				if(it == s.end())
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}

		if(flag)
			printf("NO\n");
		else
			printf("YES\n");

	}

	return 0;
}