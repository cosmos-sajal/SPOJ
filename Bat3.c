/*
13643. BATMAN3

Problem code: BAT3

" Bruce Wayne: I do fear death. I fear dying in here while my city burns. 
 Blind Prisoner: Then make the climb.
 Bruce Wayne: How?
 Blind Prisoner: As the child did. Without the rope. Then fear will find you again. "

 



The Epic fight between BANE and BATMAN saw BATMAN on the losing side .Bane delivers a crippling blow to Batman's back, then takes him to a foreign, well-like prison where escape is virtually impossible .

The prison as we know is a place from where no man ever escaped , except for the child of Ra's al Ghul himself . 

The heroics of BATMAN saw him escape the prison , however after the prison came the Valleys . To reach the city , He needed to cross these valleys . Meanwhile , BANE's army has surrounded the city and trapped all the policemen underground . Each of these peaks contain exactly one policeman held captive by Bane's men. Since, BATMAN needs to build his own army , he decides to free some of the policemen on his way . 

Also BATMAN needed to save his energy before his battle with Bane ,so he decided to take only downhill (strictly) jumps .Detective John Blake ( now called as ROBIN ) is standing in one of these peaks with a mini-BAT . This will allow BATMAN to take a maximum one jump uphill ahead . BATMAN can choose to flee ROBIN and use the BAT or rather cross over without his help .

The task in hand is to maximize the army strength to face BANE as BATMAN crosses over.
(BATMAN can take his first jump on any of these peaks)

 

" Bane : So, you came back to die with your city. 
   Batman : No. I came back to stop you. " 



Input

 

t , number of testcases
n : number of peaks ,  m : (zero based)index of the peak where ROBIN is standing 
n intergers denoting the height of the peaks   

 

Output

 

The maximum strength of the army

 

Constraints :

1<=n<=1000

 

 

Example

Input:
1
6 4
6 3 5 2 4 5

Output:
4

*/

#include <stdio.h>
#define MIN -999999999

int dp[1010], arr[1010];

int maximum(int a, int b)
{
	int returnVal = a > b ? a : b;
	return returnVal;
}

int main()
{
	int testCases, n , m, i, j, max, maxIncludingM, maxAfterM;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d %d", &n, &m);

		for(i = 0 ; i < n ; i++)
		{
			scanf("%d", &arr[i]);
			dp[i] = 1;
		}

		for(i = 0 ; i < n ; i++)
			for(j = 0 ; j < i ; j++)
				if(arr[i] < arr[j] && dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;

		max = MIN;
		maxIncludingM = dp[m];
		for(i = 0 ; i < n ; i++)
		{
			if(max < dp[i])
				max = dp[i];
			dp[i] = 1;
		}
		for(i = m + 1 ; i < n ; i++)
			for(j = m + 1 ; j < i ; j++)
				if(arr[i] < arr[j] && dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
		maxAfterM = MIN;
		for(i = m + 1 ; i < n ; i++)
			if(maxAfterM < dp[i])
				maxAfterM = dp[i];

		printf("%d\n", maximum(max, maxIncludingM + maxAfterM));
	}

	return 0;
}