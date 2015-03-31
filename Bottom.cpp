/*
1799. The Bottom of a Graph

Problem code: BOTTOM

We will use the following (standard) definitions from graph theory. Let V be a nonempty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,...,en) be a sequence of length n of edges ei∈ E such that ei=(vi,vi+1) for a sequence of vertices (v1,...,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V|∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.

Input Specification

The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E), where the vertices will be identified by the integer numbers in the set V={1,...,v}. You may assume that 1<=v<=5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,...,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.

Output Specification

For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.

Sample Input

3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output

1 3
2
*/

// can be done using strongly connected components

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> graph[5010], graphT[5010], list;
int sol[5010], completionTime[5010], visited[5010];

void init(int n)
{
	int i;

	for(i = 0 ; i <= n ; i++)
	{
		graph[i].clear();
		graphT[i].clear();
		visited[i] = 0;
		sol[i] = 0;
		completionTime[i] = 0;
	}
	list.clear();
}

void dfs1(int u)
{
	int i;

	visited[u] = 1;
	for(i = 0 ; i < (signed int)graph[u].size() ; i++)
		if(!visited[graph[u][i]])
			dfs1(graph[u][i]);
	list.push_back(u);
}

void dfs2(int u, int t)
{
	int i;

	visited[u] = 0;
	completionTime[u] = t;
	for(i = 0 ; i < (signed int)graphT[u].size() ; i++)
		if(visited[graphT[u][i]])
			dfs2(graphT[u][i], t);
}

int main()
{
	int noOfVertex, noOfEdges, u, v, i, j, completedOn;

	while(1)
	{
		scanf("%d", &noOfVertex);
		
		if(noOfVertex == 0)
			break;

		scanf("%d", &noOfEdges);
		init(noOfVertex);
		for(i = 0 ; i < noOfEdges ; i++)
		{
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graphT[v].push_back(u);
		}

		for(i = 1 ; i <= noOfVertex ; i++)
			if(!visited[i])
				dfs1(i);
		completedOn = 0;
		for(i = list.size() - 1 ; i >= 0 ; i--)
		{	
			if(visited[list[i]])
			{
				dfs2(list[i], completedOn);
				sol[completedOn] = 1;
				completedOn++;
			}
			//printf("%d\n", list[i]);
		}
		for(i = 1 ; i <= noOfVertex ; i++)
			for(j = 0 ; j < (signed int)graph[i].size() ; j++)
				if(completionTime[i] != completionTime[graph[i][j]])
				{
					sol[completionTime[i]] = 0;
					break;
				}
		
		for(i = 1 ; i <= noOfVertex ; i++)
			if(sol[completionTime[i]])
				printf("%d ", i);
		printf("\n");

	}
		
	return 0;
}