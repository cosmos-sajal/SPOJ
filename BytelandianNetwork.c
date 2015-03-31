/*
30. Bytelandian Blingors Network

Problem code: BLINNET

We have discovered the fastest communication medium Bytelandian scientists announced, and they called it blingors. The blingors are incomparably better than other media known before. Many companies in Byteland started to build blingors networks, so the information society in the kingdom of Bytes is fact! The priority is to build the core of the blingors network, joinig main cities in the country. Assume there is some number of cities that will be connected at the beginning. The cost of building blingors connection between two cities depends on many elements, but it has been successfully estimated. Your task is to design the blingors network connections between some cities in this way that between any pair of cities is a communication route. The cost of this network should be as small as possible.

Remarks

The name of the city is a string of at most 10 letters from a,...,z.
The cost of the connection between two cities is a positive integer.
The sum of all connections is not greater than 232-1.
The number of cities is not greater than 10 000.
Input



s [number of test cases <= 10]
n [number of cities <= 10 000]
NAME [city name]
p [number of neigbouring cities to the city NAME]
neigh cost 
     [neigh - the unique number of  city from the main list
      cost - the cost of building the blingors connection from NAME to neigh]
[empty line between test cases]


Output

[separate lines] cost [the minimum cost of building the blingors network]

Example

Input:
2

4
gdansk
2
2 1
3 3
bydgoszcz
3
1 1
3 1
4 4
torun
3
1 3
2 1
4 1
warszawa
2
2 4
3 1

3
ixowo
2
2 1
3 3
iyekowo
2
1 1
3 7
zetowo
2
1 3 
2 7


Output:
3
4
Warning: large Input/Output data, be careful with certain languages
*/

#include <stdio.h>
#define ll long long

struct graphNode
{
	unsigned int source, destination;
	unsigned long long int cost;
};


struct subset
{
    int parent;
    int rank;
};
 
struct graphNode arr[10000010], b[1000000];
struct subset subsets[10010];

// A utility function to find set of an element i
// (uses path compression technique)
int find(int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
        subsets[yroot].rank++;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


void merge(struct graphNode *a, ll low, ll mid, ll high)
{
    ll i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i].cost <= a[j].cost)
        {   
        	b[k].source = a[i].source;
        	b[k].destination = a[i].destination;
        	b[k].cost = a[i].cost;
        	k++; i++;
        }
        else
        {
            b[k].source = a[j].source;
            b[k].destination = a[j].destination;
        	b[k].cost = a[j].cost;
        	k++; j++;
        }
    }
    while (i <= mid)
    {
        b[k].source = a[i].source;
        b[k].destination = a[i].destination;
        b[k].cost = a[i].cost;
        k++; i++;
    }
  
    while (j <= high)
    { 
       b[k].source = a[j].source;
       b[k].destination = a[j].destination;
       b[k].cost = a[j].cost;
       k++; j++;
    }
  
    k--;
    while (k >= 0) {
        a[low + k].source = b[k].source;
        a[low + k].destination = b[k].destination;
        a[low + k].cost = b[k].cost;
        k--;
    }
}
  
void mergesort(struct graphNode *a, ll low, ll high)
{
    if (low < high) {
        ll m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}


int main()
{
	int testCases, noOfCities, noOfNeigh, city, x, y;
	char cityName[20];
	ll cost, i, j, k, MSTCost, noOfEdgesInMST;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &noOfCities);

		k = 0;
		for(i = 0 ; i < 10010 ; i++)
		{
			subsets[i].rank = 0;
			subsets[i].parent = i;
		}	
		for(i = 1 ; i <= noOfCities ; i++)
		{
			scanf("%s %d", cityName, &noOfNeigh);
			
			for(j = 1 ; j <= noOfNeigh ; j++)
			{
				scanf("%d %lld", &city, &cost);
				
				if(city > i)
				{
					arr[k].source = i;
					arr[k].destination = city;
					arr[k].cost = cost;
					k++;
				}
			}
		}
		mergesort(arr, 0, k - 1);
		MSTCost = noOfEdgesInMST = 0;

		for(i = 0 ; i < k ; i++)
		{
			if(noOfEdgesInMST == noOfCities - 1)
				break;
			x = find(arr[i].source);
    	    y = find(arr[i].destination);
    	    if (x != y)
        	{
            	noOfEdgesInMST++;
            	MSTCost += arr[i].cost;
            	Union(x, y);
        	}
 	
		}

		printf("%lld\n", MSTCost);
	}

	return 0;
}