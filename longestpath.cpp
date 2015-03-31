/*


Another chapter of the municipal chronicles of a well known unbelievable lordly major town (if this town is not well known to you, you might want to solve problem CSTREET first) tells us the following story:
Once upon a time the citizens of the unbelievable lordly major town decided to elect a major. At that time this was a very new idea and election campaigns were completely unknown. But of course several citizens wanted to become major and it didn't took long for them to find out, that promising nice things that never will become real tends to be useful in such a situation. One candidate to be elected as a major was Ivo sometimes called the benefactor because of his valuable gifts to the unbelievably lordly major towns citizens.
One day before the election day Ivo the benefactor made a promise to the citizens of the town. In case of his victory in the elections he would ensure that on one of the paved streets of the town street lamps would be erected and that he would pay that with his own money. As thrifty as the citizens of the unbelievable lordly major town were, they elected him and one day after the elections they presented him their decision which street should have street lamps. Of course they chose not only the longest of all streets but renamed several streets so that a very long street in the town existed.
Can you find how long this street was? To be more specific, the situation is as follows. You are presented a list of all paved streets in the unbelievable lordly major town. As you might remember from problem CSTREET in the town the streets are paved in a way that between every two points of interest in the town exactly one paved connection exists. Your task is to find the longest distance that exists between any two places of interest in the city.
Input

The first line of input contains the number of testcases t.
The first line of each testcase contains the number of places (2 <=n<=50000) in the town. Each street is given at one line by two places (1<=a,b<=n) and the length of the street (0<=l<20000).
Output

For each testcase output one line which contains the maximum length of the longest street in the city.
Example

Input:
1
6
1 2 3
2 3 4 
2 6 2
6 4 6
6 5 5

Output:

12


*/

#include <stdio.h>
#include <stdlib.h>
#include <queue>


struct Node
{
long long int node;
int edgeWeight;
struct Node* next;
};


	long long int t,i,num_of_places,node1,node2,weight,max,pos,j,par_weight;

	int color[10010];

	long long int weights[10010];

	struct Node *start[10010],*end[10010],*ptr,*temp;

	std:: queue<struct Node*>q;

int main()
{

	

	scanf("%lld",&t);

	for(i=0;i<t;i++)
	{
		max=0;
	
		scanf("%lld",&num_of_places);
		
		//color=(int *)malloc(sizeof(int)*num_of_places);

		//start=(struct Node**)malloc(sizeof(struct Node*)*(num_of_places));
	
		//end=(struct Node**)malloc(sizeof(struct Node*)*(num_of_places));

		//weights=(long long int*)malloc(sizeof(long long int)*num_of_places);

		for(j = 0 ; j < 10010 ; j++)
		{
			start[j] = NULL;
			end[j] = NULL;
		}

		for(j=0;j<num_of_places;j++)
		{
			
			start[j]=(struct Node*)malloc(sizeof(struct Node));
			start[j]->node=j;
			start[j]->edgeWeight=0;		
			start[j]->next=NULL;
			end[j]=start[j];
				
			color[j]=0;

			weights[j]=0;
	
		}

		weights[0]=0;

		for(j=0;j<num_of_places-1;j++)
		{
			scanf("%lld %lld",&node1,&node2);

			ptr=(struct Node*)malloc(sizeof(struct Node));
			ptr->next=NULL;
			ptr->node=node2-1;
			ptr->edgeWeight=1;

			end[node1-1]->next=ptr;
			end[node1-1]=ptr;

			ptr=(struct Node*)malloc(sizeof(struct Node));
			ptr->next=NULL;
			ptr->node=node1-1;
			ptr->edgeWeight=1;

			end[node2-1]->next=ptr;
			end[node2-1]=ptr;

			
		}

	/*	for(j=0;j<num_of_places;j++)
		{
			temp=start[j];
			
			while(temp!=NULL)
			{
				printf("%d ",temp->node);
				temp=temp->next;		
			}

			printf("\n");
		
		}*/

		q.push(start[0]);
		pos=0;

		while(!q.empty())
		{
			temp=q.front();
			par_weight=weights[temp->node];
			q.pop();
			color[temp->node]=1;
			temp=temp->next;

			while(temp!=NULL)
			{
				if(color[temp->node]==0)
				{	
					q.push(start[temp->node]);
					color[temp->node]=1;

					if(weights[temp->node] < (par_weight + temp-> edgeWeight ) )
					{
						weights[temp->node] = par_weight + temp->edgeWeight ;

						if(weights[temp->node] > max)
						{
							max = weights[temp->node];
							pos = temp->node;
						}
					} 
				}
		
				temp=temp->next;

			}

			

		}
		
		for(j=0;j<num_of_places;j++)
		{
			weights[j] = 0;
			color[j]=0;
		}

		weights[pos]=0;
		q.push(start[pos]);

		while(!q.empty())
		{
			temp=q.front();
			par_weight=weights[temp->node];
			q.pop();
			color[temp->node]=1;
			temp=temp->next;

			while(temp!=NULL)
			{
				if(color[temp->node]==0)
				{	
					q.push(start[temp->node]);
					color[temp->node]=1;

					if(weights[temp->node] < (par_weight + temp-> edgeWeight ) )
					{
						weights[temp->node] = par_weight + temp->edgeWeight ;

						if(weights[temp->node] > max)
						{
							max = weights[temp->node];
							pos = temp->node;
						}
					} 
				}
		
				temp=temp->next;

			}

			

		}

		printf("%lld\n",max);
		

		

		
	}

}