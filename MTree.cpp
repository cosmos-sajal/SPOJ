/*
3974. Another Tree Problem

Problem code: MTREE

As  you  are  bound  to  know  by  now,  a  tree  is  a  connected  graph
consisting  of N  vertices  and N−1 edges. Trees  also  have  the  property
of  there  being  exactly  a  single  unique path  between  any  pair  of 
vertices. 
You will be given a tree in which every edge is assigned a weight – 
a non negative integer. The weight of a path is the product of the
weights of all edges on the path. The weight of the tree is the sum of 
the  weights  of  all  paths  in  the  tree.  Paths  going  in  opposite
directions  (A  to  B  and  B  to  A)  are considered the same and, when 
calculating the weight of a tree, are counted only once. 
Write a program that, given a tree, calculates its weight modulo 1000000007. 
Input

The first line contains the integer N (2 ≤ N ≤ 100 000), the number of vertices
in the tree. The vertices are numbered 1 to N. Each  of  the  following N−1
contains  three  integers A,  B  and W  (1 ≤ A,  B ≤ N,  0 ≤ W ≤  1000) 
describing one edge. The edge connects vertices A and B, and its weight is W.
Output

Output the weight of the tree, modulo 1000000007. 
Sample

input 
 
3 
3 2 100 
2 1 100 
 
output 
 
10200 

input 
 
4 
1 2 5 
1 3 5 
1 4 5 
 
output 
 
90 

input 
 
5 
1 2 2 
2 3 3 
4 3 2 
5 3 2 
 
output 
 
55
*/

#include <stdio.h>
#include <queue>
#include <stdlib.h>
#define ll long long

using namespace std;

struct node
{
	int u;
	int v;
	int weight;
	struct node * next;
};

int numOfVertices;
struct node * start[100010], * end[100010], temp, sum = 0;

void add(int u, int v, int w)
{
	if(start[u] == NULL)
	{
		temp = (struct node *)malloc(sizeof(node));
		start[u] = temp;
		temp->u = u;
		temp->v = v;
		temp->weight = w;
		temp->next = NULL;
		end[u] = temp;
	}
	else
	{
		temp = (struct node *)malloc(sizeof(node));
		temp->u = u;
		temp->v = v;
		temp->weight = w;
		temp->next = NULL;
		end[u]->next = temp;
		end[u] = temp;	
	}

	if(start[v] == NULL)
	{
		temp = (struct node *)malloc(sizeof(node));
		start[v] = temp;
		temp->u = u;
		temp->v = v;
		temp->weight = w;
		temp->next = NULL;
		end[v] = temp;
	}
	else
	{
		temp = (struct node *)malloc(sizeof(node));
		temp->u = u;
		temp->v
		temp->weight = w;
		temp->next = NULL;
		end[v]->next = temp;
		end[v] = temp;	
	}

}

void bfs(queue<int> q, ll prod)
{
	while(!q.empty())
	{
		struct node * ptr = &(q.front());
		q.pop();

	}
}

int main()
{
	int i, u, v, w;
	queue<int> q;

	scanf("%d", &numOfVertices);

	for(i = 0 ; i < n - 1 ; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	
	for(i = 0 ; i < numOfVertices ; i++)
		if(start[i] != NULL)
		{
			q.insert(i);
			break;
		}
	bfs(q, 1);

	return 0;
}
