#include<stdio.h>
#include<queue>
using namespace std;
int weights[1001];
int ranks[1001];
int main()
{
    int i,j,n,m,k;
    queue<int > que;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&weights[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        que.push(k);
    }
    while(que.size()!=1)
    {
        int num=que.size()/m;
        if(que.size()%m!=0)
        {
            num+=1;
        }
        queue<int> tmp;
        for(i=0;i<num;i++)
        {
            int Max=-1;
            int index=-1;
            for(j=0;j<m&&que.size()>0;j++)
            {
                int t=que.front();
                ranks[t]=num+1;
                que.pop();
                if(weights[t]>Max)
                {
                    Max=weights[t];
                    index=t;
                }
            }
            tmp.push(index);
        }
        que=tmp;
    }
    ranks[que.front()]=1;
    for(i=0;i<n;i++)
    {
        printf("%d",ranks[i]);
        if(i != n-1){
        	printf(" ");
		}
    }
    return 0;
}

