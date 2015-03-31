/*
SPOJ Problem Set (classical)
14156. Movie Theatre Madness
Problem code: THEATRE

Problem Statement

A group of friends have gone to watch the first day first show of an awesome new movie. However, since they did not book the tickets well in advance, they have ended up with crazy seats. To be more specific, rather than getting seats such that all the friends are seated in the same row, they have ended up with seats such that all of them are seated in the same column! Now this is very inconvenient since they won't be able to chat with each other during the movie or have any kind of fun, but they are okay with this since they'd rather watch the movie like this, than not watch the movie at all.

But there is another problem apart from this. Now we know that all the friends are seated in a single column, one behind the other. Since all of them reached the theatre just in time for the movie, they rushed and occupied the first of the booked seats that they could find. However all the friends have different heights, and due to the lack of planning, there is no guarantee that a shorter person is always seated in front of a taller person. But this would mean that the shorter person would struggle to see the screen throughout the movie !

But the movie has started and it's too late now to do anything.

What you need to do is the following : For every person, find the height of the closest person seated in front of him/her who is blocking his/her view ( that is, the person closest in front with a greater height ). If no such person exists, take this height as 1. Print the product of all such values modulo 1000000007.

 
Input

On the first line you have a single integer N ( 2<=N<=105 ), the total number of friends.

This is followed by N space separated integers a1 a2.... aN, which correspond to the height of the people from back to front.That is, a1 is the height of the person seated on the last row, a2 is the height of the person seated on the second last row ( just in front of a1 ) and so on... uptil aN which is the height of the person seated right at the very front ( 1<=ai<=109 ). Note that all these integers are distinct.
Output

On a single line, output the result. ( For every person, find the height of the closest blocking person. This value is 1 if no such person exists. Print the product of all these values modulo 1000000007 ).

NOTE : By closest blocking person to ai we mean find aj, such that aj>ai, j>i, and ( j-i ) is minimum. ( Please look at sample test cases for further clarity )

 
Example

Input #1:
5
5 2 1 4 3
 
Output #1:
16


Input #2:
5
9 8 3 5 7

Output #2:
35


Input #3:
10
30 10 50 70 11 60 20 80 31 12

Output #3: 
999962375

Explanation :

Input #1 :

blockingHeight( 5 ) = 1 ( since 5 is the tallest, no one is blocking him )
blockingHeight( 2 ) = 4
blockingHeight( 1 ) = 4 ( Note that although 3 is also taller that 1, 4 is closer to 1 )
blockingHeight( 4 ) = 1 ( No one blocking 4 )
blockingHeight( 3 ) = 1 ( No one blocking 3 )

Answer=1*4*4*1*1=16
*/

#include <stdio.h>
#include <stack>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
	int n, i;
	ll prod;
	ll arr[100010];
	stack <ll> st;

	scanf("%d", &n);
	for(i = 0 ; i < n ; i++)
		scanf("%lld", &arr[i]);

	prod = 1;
	st.push(arr[0]);
	for(i = 1 ; i < n ; i++)
	{
		if(st.top() > arr[i])
			st.push(arr[i]);
		else
		{
			while(!st.empty() && st.top() < arr[i])
			{
				prod = (prod * arr[i]) % MOD;
				st.pop();
			}
			st.push(arr[i]);
		}
	}

	printf("%lld\n", prod);

	return 0;
}