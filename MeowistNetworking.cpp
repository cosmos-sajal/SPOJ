/*
4897. Meowist Networking

Problem code: MEOWIST

Kat Mandu has been living in seclusion for several years, practicing martial arts and meditating. As a consequence, he missed the take-off of social networking. He was therefore surprised upon his return to society that countless many are standing with signs at every street corner, eager to be followed on Twitter; his grandmother runs one of the world's top blogs; and chances are, even your mom has Facebook.

Reluctantly, he joined the craze, but he quickly discovered that many of these services are lacking in their friend sorting facilities: they will usually only allow listing friends in alphabetical order by name. Kat Mandu would prefer sorting his friends by age, with the oldest at the top of the list. If two friends have the same age, only then sort alphabetically. Help Kat Mandu by writing a program which implements this functionality.

Input

Each line of input will contain a name and an age, separated by a space. Names will be unique and consist of at most 10 uppercase letters. Ages will be between 1 and 100 inclusive.

Output

Print out the same names that were given in the input, but sorted according to Kat Mandu's requirements.

Example

Input:
DUCHESS 26
MARIE 8
BERLIOZ 8
TOULOUSE 7
THOMAS 28

Output:
THOMAS
DUCHESS
BERLIOZ
MARIE
TOULOUSE
*/

#include <stdio.h>
#include <string.h>

char nameArr[5000][20];
int ageArr[5000];

void merge(int low, int mid, int high)
{
    int b[10000], val;
    char c[5000][20];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (ageArr[i] >= ageArr[j])
        {
            if(ageArr[i] == ageArr[j])
            {
            	val = strcmp(nameArr[i], nameArr[j]);
            	if(val < 0)
            	{
            		strcpy(c[k], nameArr[i]);
            		b[k] = ageArr[i];
            		k++; i++;	
            	}
            	else
            	{
            		strcpy(c[k], nameArr[j]);
            		b[k] = ageArr[j];
            		k++; j++;	
            	}
            	
            }
            else
            {
            	b[k] = ageArr[i];
            	strcpy(c[k], nameArr[i]);
            	k++; i++;
           	}

        }
        else
        {
            b[k] = ageArr[j];
            strcpy(c[k], nameArr[j]);
            k++; j++;
        }
    }
    while (i <= mid)
    {
        b[k] = ageArr[i];
        strcpy(c[k], nameArr[i]);
        k++; i++;
    }
  
    while (j <= high)
    {
        b[k] = ageArr[j];
        strcpy(c[k], nameArr[j]);
        k++; j++;
    }
  
    k--;
    while (k >= 0) {
        ageArr[low + k] = b[k];
        strcpy(nameArr[low + k], c[k]);
        k--;
    }
}
  
void mergesort(int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(low, m);
        mergesort(m + 1, high);
        merge(low, m, high);
    }
}

int main()
{
	int i = 0, n;

	while(1)
  	{
    	if(scanf("%s %d",nameArr[i], &ageArr[i])==-1) break;
    	i++;
  	}
	n = i;
	mergesort(0, n - 1);
	for(i = 0 ; i < n ; i++)
		printf("%s\n", nameArr[i]);

	return 0;
}