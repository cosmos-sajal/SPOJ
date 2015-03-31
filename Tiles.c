/*
5450. Tiles of Tetris, Not!

Problem code: ANARC09B

You’ve really messed up this time. “Go buy some square tiles” your supervisor told you. But as usual, you were either busy reading that message, answering that e-email, or updating your wall status on facebook. “Go buy some tiles” was all that you could remember. Your supervisor is
now complaining that the tiles you bought were not squares and you’ll be fired if you don’t fix it! “Fix it? How am I supposed to fix it?” you say to yourself. “I’m a programmer, The only tiles I know are those of the game Tetris!” There is no way you can afford to be fired either. This is your third job in less than a month. “I have to fix it!” you keep repeating.You call the store you bought the tiles from, but they won’t take them back or even exchange. “We cannot cancel orders once the merchandise has left the store”, they tell you. You take a look at the tiles, they’re all rectangle- shaped and all of the same size. You’d be losing a lot if you cut them, not that you’d be able to cut them into perfect squares in the first place. “Wait a minute!” you say to yourself. You grab a bunch of tiles, put them in some arrangement and Voila, that’s a square. But that won’t convince your boss. Tiles are supposed to be small, and what you came-up with is rather big. You take another look at your arrangement, and it hits you again. “I’m on a roll today!” you say proudly to yourself. You just figured out how to find the smallest number of tiles needed to form the smallest possible square.

You rush and bring your supervisor to show him your discovery. He’s not that much impressed. You’re not making sense anyway (given all the blood rushing in your head trying to explain your algorithm.) You know that the calculation is definitely much simpler than what you’re saying, but you just can’t seem to think clearly. Finally, your supervisor shouts: “First of all, the tiles have to be laid-down in the same orientation. Second, I’m running a construction site here, not a software shop! How do you expect the workers to figure out that number! You either write me a program to do the calculation you’re describing, or you go collect your netbook, your cell, your ipod, and your blackberry, and you get out of here this minute!”

Input

Your program will be tested on one or more data sets. Each test set is described on a single line made of two positive numbers: (0 < W, H < 1, 000, 000) which are the width and height of each tile. The last line is made of two zeros.

Output

For each test case, write the answer on a separate line.

Example

Input:
2 3
1 2
0 0

Output:
6
2
*/

#include <stdio.h>
#define ll long long

ll GCD(ll w, ll h)
{
	ll r;
	while(h != 0)
	{
		r = w % h;
		w = h;
		h = r;
	}

	return w;
}

int main()
{
	ll w, h, gcd, lcm, prod, temp1, temp2;

	while(1)
	{
		scanf("%lld %lld", &w, &h);
		
		if(!w && !h)
			break;
		prod = w * h;
		gcd = GCD(w, h);
		lcm = prod / gcd;
		temp1 = lcm / w;
		temp2 = lcm / h;

		printf("%lld\n", temp1 * temp2);
	}

	return 0;
}