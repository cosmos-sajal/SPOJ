/*
8406. Temple Queues

Problem code: TEMPLEQ

The Tirumala temple is the most visited place of worship in the world. As the number of pilgrims who visit the temple each day is very high, the head of the temple should keep monitoring the queue system. Today is another lovely day and he has started his work. There are N queues at the entrance of the temple and some of them are already filled with pilgrims. Each queue has a metal door at the beginning, which leads to the temple. When the door is opened, it allows only one pilgrim to get through it and it gets closed immediately after that.

New pilgrims are rushing in to the queues and the head needs to monitor the current sizes of the queues and decide which doors to be opened. At any time, he wants to know how many queues currently have at least X pilgrims. He also decides an integer Y and wants to open the doors of all the queues having at least Y pilgrims at that time. You are the controller of the queue system and are following his instructions. Respond quickly and win yourself a big laddu (sweet) from him :) .


Read the input section for rest of the details. 


Input

The first line contains two integers N and Q. N - The number of queues [ 1 <= N <= 100,000 ], Q - The number of queries [ 0 <= Q <= 500,000 ] . The second line contains N integers, which are the initial sizes of the queues. ith integer ( 1-based ) is the initial size of queue i [ 0 <= initial size <= 100,000,000 ] 

Each of the next Q lines is one of the following 

1 A [ One pilgrim enters the queue# A ( 1 <= A <= N ) ] 

2 X [ Find the number of queues having atleast X pilgrims currently ( 0 <= X <= 1,000,000,000 ) ] 

3 Y [ Open the doors of all the queues having atleast Y pilgrims ( 1 <= Y <= 1,000,000,000 ), and thus allowing only one pilgrim to enter the temple from each of them ] 


Output

For each query of type "2 X" , print the answer in a new line. 


Example

Input:
5 6
20 30 10 50 40
2 31
1 2
2 31
3 11
2 20
2 50

Output:
2
3
3
0

Note : Ideal time limit should be 2s. It has been increased to 7s, to let Java solutions pass, as the i/o is huge.

* There are multiple test sets, and the judge shows the sum of the time taken over all test sets of your submission, if Accepted.
*/

#include <stdio.h>
#include <algorithm>
#define ll long long
#define gc getchar_unlocked

void scanlong(ll &x)
{
register ll int c = gc();
x = 0;
ll int neg = 0;
for(;((c<48 || c>57) && c != '-');c = gc());
if(c=='-') {neg=1;c=gc();}
for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
if(neg) x=-x;
}

void scanint(int &x)
{
register int c = gc();
x = 0;
int neg = 0;
for(;((c<48 || c>57) && c != '-');c = gc());
if(c=='-') {neg=1;c=gc();}
for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
if(neg) x=-x;
}

struct queueInfo
{
	ll size;
	int pos;
};

struct queueInfo queue[100010];
int queuePos[100010];

void merge(struct queueInfo *a, int low, int mid, int high)
{
    struct queueInfo b[100010];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i].size <= a[j].size)
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
  
    while (j <= high)
        b[k++] = a[j++];
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}
  
void mergesort(struct queueInfo *a, int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

void assignQueuePos(ll n)
{
	ll i;
	for(i = 0 ; i < n ; i++)
		queuePos[queue[i].pos] = i;
}

void pilgrimEnter(ll queueNum, ll n)
{
	ll pos = queuePos[queueNum - 1];
	ll i;

	struct queueInfo temp = queue[pos];
	temp.size++;
	queue[pos].size++;
	for(i = pos ; i < n && queue[i].size > queue[i + 1].size ; i++)
	{	
		queue[i] = queue[i + 1];
		queue[i + 1] = temp;
	}
}

ll noOfQueuesHavingXPilgrims(ll num, ll n)
{
	ll low = 0, high = n - 1, mid;
	while(low < high)
	{
		mid = (low + high) / 2;
		if(queue[mid].size >= num)
		{
			if(queue[mid].size == num)
				return (n - mid);
			else
			{
				if(queue[mid].size > num && queue[mid - 1].size < num)
					return (n - mid);
				else
					high = mid - 1;
			}
		}
		else if(queue[mid].size < num)
			low = mid + 1;
	}

	if(low == high)
	{
		if(queue[low].size >= num)
			return 1;
	}
	return 0;
}

ll startingPos(ll num, ll n)
{
	ll low = 0, high = n - 1, mid;
	while(low < high)
	{
		mid = (low + high) / 2;
		if(queue[mid].size >= num)
		{
			if(queue[mid].size == num)
				return mid;
			else
			{
				if(queue[mid].size > num && queue[mid - 1].size < num)
					return mid;
				else
					high = mid - 1;
			}
		}
		else if(queue[mid].size < num)
			low = mid + 1;
	}

	if(low == high)
	{
		if(queue[low].size >= num)
			return low;
	}
	return -1;
}

void openTheGates(ll num, ll n)
{
	ll pos = startingPos(num, n);
	ll i;
	if(pos == -1)
		return;
	for(i = pos ; i < n ; i++)
		queue[i].size--;
}

void print(ll n)
{
	ll i;
	for(i = 0 ; i < n ; i++)
		printf("%lld %d\n", queue[i].size, queue[i].pos);
	printf("\n");
}

int main()
{
	ll i, n, q, num;
	int queryType;

	scanf("%lld %lld", &n, &q);
	for(i = 0 ; i < n ; i++)
	{
		scanlong(queue[i].size);
		queue[i].pos = i;
	}
	mergesort(queue, 0, n - 1);
	assignQueuePos(n);
	for(i = 0 ; i < q ; i++)
	{
		scanint(queryType);
		scanlong(num);
		switch(queryType)
		{
			case 1 : pilgrimEnter(num, n); break;
			case 2 : printf("%lld\n", noOfQueuesHavingXPilgrims(num, n)); break;
			case 3 : openTheGates(num, n); break;
		}
		//print(n);
	}

	return 0;
}