/*
660. Dungeon of Death

Problem code: QUEST4

To reach the treasure, Jones has to pass through the "Room of Death". The floor of this room is a square with side 120 units. It is laid with square tiles of dimensions {1 X 1} arranged into a grid. But, at some places in the grid tiles are missing. As soon as the door to this room is opened poisonous gas starts coming out of these missing grid locations. The only escape from this gas is to completely cover these locations with planks lying outside the room. Each plank has dimensions {120 X 1} and can only be placed parallel to either sides of the floor. Now Jones wants to minimize the damage to his health so that he has enough of it left for the treasure. He figures out that in order to achieve this he has to use the minimum number of planks possible. He also realises that even if the planks overlap, poisonous gas from the missing tiles can still be successfully blocked. Please help Jones in this task.

Dungeon of Death: Tiles Uncovered
Dungeon of Death: Tiles Covered
Input

The first line of the input is a positive integer t <= 20, denoting the number of rooms.
The descriptions for the t rooms follow one after the other.
Room Description:
The first line of the room description is a positive integer n (n <= 10010), denoting the number of missing tile locations.
This is followed by the n lines, one for each missing tile location.
Each line contains two integers x y (0 <= x, y < 120), separated by a single space, representing the co-ordinates of the missing tile location.
Output

The output should consist of t lines, one for each room. The kth line in the output should be an integer mk, the minimum number of planks needed for the kth room.

Example

Input: 
2 
3 
1 0 
2 0 
3 0 
4 
1 1 
2 2 
3 3 
4 4

Output: 
1 
4

URL : http://www.spoj.com/problems/QUEST4/
*/

#include <stdio.h>
#include <list>

using namespace std;
int map[130][130];

int main()
{
	long long int testCases, numberOfMissingTiles, x, y, i, planksUsed1, planksUsed2, j;

	scanf("%lld", &testCases);

	while(testCases--)
	{
		list<long long int> rows1[120], cols1[120], rows2[120], cols2[120];
		long long int rowCount[130], colsCount[130];
		
		for(i = 0 ; i < 120 ; i++)
			for(j = 0 ; j < 120 ; j++)
				map[i][j] = 0;

		for(i = 0 ; i < 120 ; i++)
		{
			rowCount[i] = 0;
			colsCount[i] = 0;
		}
		planksUsed1 = 0;
		planksUsed2 = 0;

		scanf("%lld", &numberOfMissingTiles);
		for(i = 0 ; i < numberOfMissingTiles ; i++)
		{
			scanf("%lld %lld", &x, &y);
			if(!map[x][y])
			{
				map[x][y] = 1;
				rows1[x].push_front(y);
				cols1[y].push_front(x);
				rows2[x].push_front(y);
				cols2[y].push_front(x);
				rowCount[x]++;
				colsCount[y]++;
			}
		}

		for(i = 0 ; i < 120 ; i++)
		{
			//printf("rowCount[%lld]=%lld\n", i, rowCount[i]);
			if(rowCount[i] > 1)
			{
				planksUsed1++;
				list<long long int>::iterator it1 = rows1[i].begin();
				for(; it1 != rows1[i].end() ; it1++)
				{
					long long int colNo = *it1;
					list<long long int>::iterator it2 = cols1[colNo].begin();
					for(; it2 != cols1[colNo].end() ; it2++)
					{
						if(*it2 == i)
						{
							cols1[colNo].erase(it2);
							break;
						}
					}
				}
			}
		}
		for(i = 0 ; i < 120 ; i++)
		{
			if(cols1[i].size() > 0)
				planksUsed1++;
		}
		for(i = 0 ; i < 120 ; i++)
		{
			if(colsCount[i] > 1)
			{
				planksUsed2++;
				list<long long int>::iterator it1 = cols2[i].begin();
				for(; it1 != cols2[i].end() ; it1++)
				{
					long long int rowNo = *it1;
					list<long long int>::iterator it2 = rows2[rowNo].begin();
					for(; it2 != rows2[rowNo].end() ; it2++)
					{
						if(*it2 == i)
						{
							rows2[rowNo].erase(it2);
							break;
						}
					}
				}
			}
		}
		for(i = 0 ; i < 120 ; i++)
		{
			if(rows2[i].size() > 0)
				planksUsed2++;
		}

		printf("--%lld %lld\n", planksUsed1, planksUsed2);

		if(planksUsed1 < planksUsed2)
			printf("1.%lld\n", planksUsed1);
		else
			printf("2.%lld\n", planksUsed2);
		
	}

	return 0;
}