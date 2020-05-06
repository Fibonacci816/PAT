#include<stdio.h>
#include<limits.h>
#define MAX 501
int map[MAX][MAX],visited[MAX],teams[MAX];
int pathaccount,maxaccount,mind,n,m;
void DFS(int start,int end,int pathlength,int teamaccount)
{
    int i,j;
    if(start==end)
    {
        if(pathlength<mind)
        {
            pathaccount=1;
            mind=pathlength;
            maxaccount=teamaccount;
        }else if(pathlength==mind)
        {
            pathaccount++;
            if(maxaccount<teamaccount)
            {
                maxaccount=teamaccount;
            }
        }
        else
        {
            return ;
        }
    }
    if(pathlength>mind)
    {
        return ;
    }

    for(i=0;i<n;i++)
    {
        if(visited[i]==0&&map[start][i]<INT_MAX)
        {
            visited[i]=1;
            DFS(i,end,pathlength+map[start][i],teamaccount+teams[i]);
            visited[i]=0;
        }
    }

}
int main()
{
    int i,j,k,t,c1,c2,l;
    mind=INT_MAX;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           map[i][j]=INT_MAX;
        }
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&teams[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&k,&t,&l);
        map[k][t]=map[t][k]=l;
    }
    DFS(c1,c2,0,teams[c1]);
    printf("%d %d",pathaccount,maxaccount);
}
