#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fun(char*);
void push();
int pop(int);
int top=0;

char *stack,*ch;


int main()
{
	int a,i,val=0,arr[500];
	stack=(char*)malloc(sizeof(char)*1000000);
	ch=(char*)malloc(sizeof(char)*1000000);


	
	//printf("enter number of testcases");
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%s",ch);
		val=fun(ch);
		arr[i]=val;
	}
	for(i=0;i<a;i++)
		printf("\n%d",arr[i]);
	
	return 0;
}

int fun(char*ptr)
{
	int q=0;
	while(*ptr!='\0')
	{
		if(*ptr=='<')
		{
			push();
			++ptr;
		}
		else
		{
			q=pop(q);
			++ptr;
		}
	}
	return q;
}

void push()
{
	
	top=top+1;
	stack[top]='<';
}

int pop(int q)
{
	if(top!=0)
	{
		--top;
		q=q+2;
		return q;
	}
	else
		return q;
} 
