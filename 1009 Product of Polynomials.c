#include <stdio.h>
double a[1001],b[1001],c[2001];
int main()
{
    int n,exp,count=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&exp);
        scanf("%lf",&a[exp]);
    }
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&exp);
        scanf("%lf",&b[exp]);
    }
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            c[i+j]+=a[i]*b[j];
        }
    }
    for(int i=2000; i>=0; i--){
        if(c[i]!=0){
            count++;
        }
    }
    printf("%d",count);
    for(int i=2000; i>=0; i--){
        if(c[i]!=0){
            printf(" %d %.1f",i,c[i]);
        }
    }
    return 0;
}
