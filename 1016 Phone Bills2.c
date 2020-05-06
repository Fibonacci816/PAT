#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[21];
    int month;
    int date;
    int hour;
    int minute;
    int T;
    int tag;
    char state[10];
}customer[1001];
int cmp(const void *a,const void *b)
{
    if(strcmp((*(struct node *)a).name ,(*(struct node *)b).name)!=0)
    return  strcmp((*(struct node *)a).name ,(*(struct node *)b).name)>0 ? 1 : -1;
    else
       return (*(struct node *)a).T >(*(struct node *)b).T ? 1 : -1;
}
int time[25];
double caculate(int t)
{
    int i,j;
    double sum=0;
    for(i=0;i<t/60;i++)
    {
        sum+=time[i%24]*60/100.0;
    }
    sum+=time[i%24]*(t%60)/100.0;
    return sum;
}
int main()
{
    int i,j,n,m,k,t,cmonth,flag=0;
    double charge,total;
    char cname[21];
    for(i=0;i<24;i++)
    {
        scanf("%d",&time[i]);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s%d%*c%d%*c%d%*c%d%s",customer[i].name,&customer[i].month,&customer[i].date,&customer[i].hour,&customer[i].minute,customer[i].state);
        if(strcmp(customer[i].state,"on-line")==0)
        {
            customer[i].tag=0;
        }
        else
        {
          customer[i].tag=1;
        }
        customer[i].T=customer[i].date*24*60+customer[i].hour*60+customer[i].minute;
    }
    qsort(customer,n,sizeof(customer[0]),cmp);
    for(i=0;i<n;i++)
    {
        if(i+1>=n)
            break;
        if(customer[i].tag==0&&customer[i+1].tag==1&&strcmp(customer[i].name,customer[i+1].name)==0)
        {
            if(flag==0)
           {
               strcpy(cname,customer[i].name);
               printf("%s %02d\n",cname,customer[i].month);
               flag=1;
               total=0;
           }
           if(strcmp(cname,customer[i].name)==0)
           {
               charge=caculate(customer[i+1].T)-caculate(customer[i].T);
             printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",customer[i].date,customer[i].hour,customer[i].minute,
                    customer[i+1].date,customer[i+1].hour,customer[i+1].minute,customer[i+1].T-customer[i].T,charge);
                    total+=charge;
           }
           else
           {
               printf("Total amount: $%.2lf\n",total);
               strcpy(cname,customer[i].name);
               printf("%s %02d\n",cname,customer[i].month);
               total=0;
               charge=caculate(customer[i+1].T)-caculate(customer[i].T);
             printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",customer[i].date,customer[i].hour,customer[i].minute,
                    customer[i+1].date,customer[i+1].hour,customer[i+1].minute,customer[i+1].T-customer[i].T,charge);
                    total+=charge;
           }
        }
    }
    printf("Total amount: $%.2lf",total);
    return 0;
}
