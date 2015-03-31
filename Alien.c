/*
SPOJ Problem Set (classical)
10401. Aliens at the train
Problem code: ALIEN

The aliens have arrived to Earth and everything is in harmony, the two races can live together. However, one specific Female Alien does not want to see humans on her way to the university, the alien must use the train as every human does. But she can choose any train station such she doesn’t see more than B humans, however, the Alien wants to go as far as possible with the train. Please, help her in this task

                        INPUT:
You will receive one integer T denoting the number of test cases, then, the next line will contain two integers At Bt where At and Bt is the number of stations in the train (1<=At<=100,000) and the number of people that the alien wants to see as maximum (1<=Bt<=10,000,000), after that, one line containing At integers separated by a single space will denote the number of people the Alien can find in the At-i-th station. (For each station there will be as much 100 people)
                        OUTPUT:
Your output should consist on T pair of numbers denoting the number of people the alien will see and the number of stations she will pass respectively.

SAMPLE:


INPUT:
1
5 100
20 15 30 80 100


OUTPUT
65 3

 

Output note:
The alien takes the train at station 1 (with 20 people) and goes to station 2, then the 3rd station, at this point, she have seen 65 people, if she decides to go to station 4 she will see 145 people… Then she exits the station.

The alien, however, can start at station 2 with 15 people, then continue up to the 4th station, then, she would have seen 125 people, but, as she wants to see the minimum people possible and this number of people exceeds what she wants to see, she decides to choose the way from the 1st to the 3rd station.

Clarification: The alien will be moving always forward (remember, she can choose any station as a start), NEVER backwards, and you should choose the best path that satisfies the output specification.
*/



#include <stdio.h>

int main()
{
	int numOfTestCases;
	long long int maxPeople,numOfStations,stationsTravelled,maxStationsTravelled,peopleSeen,minPeopleSeen;
	long long int arr[100000],start,i;

	scanf("%d",&numOfTestCases);


	while(numOfTestCases--)
	{
		scanf("%lld %lld", &numOfStations, &maxPeople);

		stationsTravelled = 0;
		peopleSeen = 0;
		start = 0;
		maxStationsTravelled=0;

		for(i = 0 ; i < numOfStations ; i++)
			scanf("%lld",&arr[i]);

		for( i = 0 ; i < numOfStations ; i++ )
		{
			stationsTravelled++;
			peopleSeen += arr[i];

			while(peopleSeen > maxPeople)
			{
				peopleSeen -= arr[start];
				stationsTravelled--;
				start++;
			}
			if( stationsTravelled > maxStationsTravelled )
			{
				maxStationsTravelled = stationsTravelled;
				minPeopleSeen = peopleSeen;
			}
			else if (stationsTravelled == maxStationsTravelled)
			{
				if(minPeopleSeen > peopleSeen)
					minPeopleSeen = peopleSeen;
			}
 
		}

		printf("%lld %lld\n",minPeopleSeen,maxStationsTravelled );

	}

	return 0;

}