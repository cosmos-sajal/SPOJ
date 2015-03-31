#include<cstdio>
#include<cstring>
int R,C,t;int x[] = {-1,0,1,0,-1,1,1,-1};
int y[] = {0,-1,0,1,-1,-1,1,1};
char g[106][106];char txt[20]="ALLIZZWELL";int f;bool vis[106][106];
int dfs(int i,int j,int l)
{
    //if(l==10){{puts("found");return 1;}}
    f=0;
    if(l==9)return 1;
    for(int k=0;k<8;k++)
    {
        int xx,yy;
        xx=i+x[k];yy=j+y[k];
        if(xx>=0 && yy>=0 && yy<C && xx<R && !vis[xx][yy] &&g[xx][yy]==txt[l+1])
        {vis[xx][yy]=1;f=dfs(xx,yy,l+1);vis[xx][yy]=0;}
        if(f==1)break;
    }
    //if(f)putchar(g[i][j]);
    return f;
}
int main()
{
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&R,&C);f=0;
        for(i=0;i<R;i++)scanf("%s",g[i]);
        memset(vis,0,sizeof(vis));
 
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                if(g[i][j]=='A'&& (f=dfs(i,j,0)==1))
                    break;
        //printf("%d ",i);
        printf("%s\n",(!f)?"NO":"YES");
        puts("");
    }
    return 0;
}