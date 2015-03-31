/*
10285. Why this kolaveri di

Problem code: WTK

Problem description:

                The percentage of Soup boys in India is increasing day by day. These soup boys finally got fed up with girls cheating on them. N girls are randomly chosen and they are now under investigation. Somehow the soup boys found out that, if there are N girls, then the ratio of the number of girls who cheat to the total number of girls is (N-1)/N. As these soup boys are very angry, they wanted to punish all the cheaters. But, obviously, during investigation all the girls claimed to be only one that is good. Soup boys had a plan to find the real good girl. They asked all the girls to form a circle. Then their eyes are tied.  Now the leader of the soup boys goes into the middle of circle, removes the first girl from the group and then turns one step clockwise. Then leaves one girl and removes the second one. Then he leaves two girls and removes the third one and so on. The girl who is left at the end is declared as a good one and is free to go. The rest will await their surprise punishment. Being in the position of a good intelligent girl, you initially want to stand in the position which will get you free. Find such a position.

Input Specification:

The first line contains an integer T denoting the number of test cases. Then T lines follow, each with one integer N, the number of girls soup boys will choose from.

Output Specification:

For each test case output the position the good girl has to stand initially so that will be free at the end.

Input Constraints:

t<=250

n<=100000

Sample Input:

3

2

1

5

Sample Output:

2

1

4

Explanation of third test case:

There are 5 girls arranged in a circle as 1, 2, 3  4, 5. Girl 1 stands right next to 5. Girl 1 is removed first. Then 2 is skipped and 3 removed. The remaining girls will stand in the order 4,5,2. 4 and 5 are skipped and 2 removed. Only 4 and 5 are left and we have to skip three girls this time. We skip 4-5-4 and finally 5 is removed. So the intelligent, good girl should stand initially at 4th position.
*/

#include <stdio.h>

long long int func(long long int n){
	long long int r = 1, i = 2, k = n - 2;

	while(i <= n){
		r = ((r + k) % i) + 1;
		i++;
		k--;
	}

	return r;
}

int main(){
	long long int n, w;
	int testCases;

	scanf("%d", &testCases);

	while(testCases--){
			scanf("%lld", &n);

			w = func(n);
			printf("%lld\n", w);
	}

	return 0;	
}