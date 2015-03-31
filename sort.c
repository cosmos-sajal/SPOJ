#include<stdio.h>

int main()
{
	int arr[500];
	int i,j;
	int min,pos,temp;

	for( i = 0 ; i < 317 ; i++ )
	{
		scanf("%d",&arr[i]);
	}

	for( i = 0 ; i < 317 ; i++ )
	{
		min = arr[i];
		pos = i;

		for( j = i ; j < 317 ; j++ )
		{
			if( arr[j] > min )
			{
				pos = j;
				min = arr[j];
			}
		}

		temp = arr[pos];
		arr[pos] = arr[i];
		arr[i] = temp;
	}

	for( i = 0 ; i < 317 ; i++ )
	{
		printf("%d-->%d\n",i,arr[i]);
	}


	return 0;
}