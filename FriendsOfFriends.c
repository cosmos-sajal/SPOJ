/*
9788. Friends of Friends

Problem code: FACEFRND

Bob uses a social networking site almost all the time. He was wondering what are Friends of Friends in that social networking site? If “X” is his friend, and “Y” is X’s friend but “Y” is not his friend, then “Y” is called his friend of friend. You have to find how many friends of friends Bob has. (Each user in that social networking site has a unique 4-digit ID number)

Input

First line contains a integer “N” (1<=N<=100) the number of friends in Bob's Profile. Then follow N lines.

First Integer in each line is the ID number of Bob's friend, then an integer “M” (1<=M<=100) is the number of people in his friend list. Then follow M integers in that line, denoting the ID number of friends in his friend list (excluding Bob). 

Output

Output a single integer denoting Bob's number of friends of friends.

Example

Input:
3

2334 5 1256 4323 7687 3244 5678

1256 2 2334 7687

4323 5 2334 5678 6547 9766 9543


Output:
6
*/

#include <stdio.h>
#define ll long long

int friendsMap[10010], friendsOfFreindsMap[10010];

int main()
{
	int numOfFriends, numOfFriendsOfFriends, i, j;
	int friendID, friendOfFriendID;
	ll result = 0;

	scanf("%d", &numOfFriends);

	for(i = 0 ; i < numOfFriends ; i++)
	{
		scanf("%d", &friendID);
		
		friendsMap[friendID] = 1;
		if(friendsOfFreindsMap[friendID])
		{
			result--;
			friendsOfFreindsMap[friendID] = 0;
		}

		scanf("%d", &numOfFriendsOfFriends);

		for(j = 0 ; j < numOfFriendsOfFriends ; j++)
		{
			scanf("%d", &friendOfFriendID);
			if(friendsMap[friendOfFriendID])
				continue;
			else if(!friendsOfFreindsMap[friendOfFriendID])
			{
				result++;
				friendsOfFreindsMap[friendOfFriendID] = 1;
			}
		}
	}

	printf("%lld\n", result);

	return 0;
}