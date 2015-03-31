/*
2727. Army Strength

Problem code: ARMY

The next MechaGodzilla invasion is on its way to Earth. And once again, Earth will be the battleground for an epic war.

MechaGodzilla's army consists of many nasty alien monsters, such as Space Godzilla, King Gidorah, and MechaGodzilla herself.

To stop them and defend Earth, Godzilla and her friends are preparing for the battle.

Problem specification

Each army consists of many different monsters. Each monster has a strength that can be described by a positive integer. (The larger the value, the stronger the monster.)

The war will consist of a series of battles. In each battle, the weakest of all the monsters that are still alive is killed.

If there are several weakest monsters, but all of them in the same army, one of them is killed at random. If both armies have at least one of the weakest monsters, a random weakest monster of MechaGodzilla's army is killed.

The war is over if in one of the armies all monsters are dead. The dead army lost, the other one won.

You are given the strengths of all the monsters. Find out who wins the war.

Input specification

The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.

Each test case starts with line containing two positive integers NG and NM – the number of monsters in Godzilla's and in MechaGodzilla's army. Two lines follow. The first one contains NG positive integers – the strengths of the monsters in Godzilla's army. Similarly, the second one contains NM positive integers – the strengths of the monsters in MechaGodzilla's army.

Output specification

For each test case, output a single line with a string that describes the outcome of the battle.

If it is sure that Godzilla's army wins, output the string "Godzilla".

If it is sure that MechaGodzilla's army wins, output the string "MechaGodzilla".

Otherwise, output the string "uncertain".

Example

input:
2

1 1
1
1

3 2
1 3 2
5 5

output:
Godzilla
MechaGodzilla
Hint

In the first test case, there are only two monsters, and they are equally strong. In this situation, MechaGodzilla's monster is killed and the war ends.

In the second test case, the war will consist of three battles, and in each of them one of Godzilla's monsters dies.

For all the test cases, int in C/C++/Java or longint in Pascal is enough.
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	long long int testCases, NG, NM, i;
	long long int temp;
	long long int maxGodzillaStrength = -1, maxMechaGodzillaStrength = -1;
	
	scanf("%lld",&testCases);

	while(testCases--)
	{
		scanf("%lld%lld",&NG,&NM);

		maxGodzillaStrength  = -1;
		maxMechaGodzillaStrength = -1;

		for(i = 0 ; i < NG ; i++)
		{
			scanf("%lld",&temp);
			if(temp > maxGodzillaStrength)
				maxGodzillaStrength = temp;
		}

		for(i = 0 ; i < NM ; i++)
		{
			scanf("%lld",&temp);
			if(temp > maxMechaGodzillaStrength)
				maxMechaGodzillaStrength = temp;	
		}
		
		if(maxGodzillaStrength >= maxMechaGodzillaStrength)
			printf("Godzilla\n");
		else 
   			printf("MechaGodzilla\n");

	}

	return 0;
}