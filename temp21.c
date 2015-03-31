#include <stdio.h>
#define ll long long
ll pre[1000010],opp[1000010];
void p(){ll i,tempCount=1;pre[1]=opp[1]=1;for(i=2;i<=1000010;i++){tempCount+=i;pre[i]=tempCount+pre[i-1];opp[i]=tempCount;}}int main(){int i,n,testCases;ll triangleCount;scanf("%d", &testCases);p();while(testCases--){scanf("%d", &n);triangleCount=pre[n];if(n%2)for(i=2;i<=n;i+=2)			triangleCount+=opp[i];else for(i=1;i<=n;i+=2)triangleCount+=opp[i];printf("%lld\n",triangleCount);}return 0;}