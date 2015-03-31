#include <stdio.h> 
int main()
{
	long long s=0;
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n>0)s+=n;}printf("%lld\n",s);return 0;
}