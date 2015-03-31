/*
10471. Aliens at the train, again!

Problem code: ALIEN2

The Alien who doesn’t like to see humans has moved to an Urban City (Yes, a little ironic) and now she’s facing a double-train system, but still, the alien hates humans, so she wants to see the minimum quantity of people possible in her way to the university at the two trains.

The Alien has some sort of anthropophobia, this means she has a phobia to the people or the society, knowing this, she tells you that can only see K persons in the train, if she sees more than that, she will have a panic attack.

With her special powers, the alien knows how much people is on every station of the train A and the train B, she asked you to make a program that, given the number of people in the stations of the train A and B and the maximum number of people she wants to see, you give her the number of stations she will have to cross and the minimum persons found in those stations. Knowing that:

The Alien starts from train A or B (she can choose where to start) but from the station 1.
She can switch from train A or B or viceversa, if she does this, she will see Ai+Bi people, being “i” the station she’s at that moment.
If she sees strictly more persons than the specified, she will automatically exit the train.
INPUT:

The input will contain two integers N (1<=N<=10,000) and K (1<=65,000) being the number of stations and the maximum number of people that the alien wants to see, then, 2 lines will follow, each containing N integers separated by a single space denoting the number of people found in the j-th station of the i-th train. (1<=Ni<=100)

OUTPUT:

Two single numbers denoting the number of stations passed and the people seen.

 

SAMPLE DATA:

INPUT:

3 10

9 2 4

1 2 9

OUTPUT:

3 9

INPUT2:

5 10

1 7 1 1 1

2 2 2 2 2

OUTPUT2:

5 9

 

Explanation I/O 1: The alien starts at the train B station 1, she sees 1 people, she continues to the station 2 and then decides to change the train, the alien have seen 4 more people, and then she continues at the train A up to the station 3. At this point the Alien will see (1+4+4) people (9) and has passed 3 stations.
*/

#include <stdio.h>

long long int A[10010], B[10010], AA[10010], B[10010], BB[10010];
long long int maxPeopleSeen = 0, maxStationTravelled = 1;

long long int min(long long int a, long long int b){
	if(a < b)
		return a;
	else
		return b;
}

void func(int n, int k){
	int flagA = 1, flagB = 1, i;

	for(i = 1 ; i < n ; i++){
		if(!flagA && !flagB)
			break;
		if(flagA){
			AA[i] = min(AA[i - 1] + A[i], BB[i - 1] + B[i] + A[i]);
			if(AA[i] > k){
				AA[i] = 9999999999;
				flagA = 0;
			}
		}
		if(flagB){
			BB[i] = min(BB[i - 1] + B[i], AA[i - 1] + A[i] + B[i]);
			if(BB[i] > k){
				BB[i] = 9999999999;
				flagB = 0;
			}
		}
		if(flagA || flagB)
			maxStationTravelled++;
	}
	
	maxPeopleSeen = min(AA[maxStationTravelled - 1], BB[maxStationTravelled - 1]);

}

int main(){
	int n, k, i;

	scanf("%d %d", &n, &k);
	for(i = 0 ; i < n ; i++){
		scanf("%lld", &A[i]);
		AA[i] = BB[i] = 9999999999;
	}
	for(i = 0 ; i < n ; i++)
		scanf("%lld", &B[i]);
	
	AA[0] = A[0];
	BB[0] = B[0];
	if(AA[0] > k && BB[0] > k)
		printf("0 0\n");
	else{
		func(n, k);
		printf("%lld %lld\n",maxStationTravelled, maxPeopleSeen);
	}


	return 0;
}