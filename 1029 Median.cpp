#include<stdio.h>
#include<algorithm>
using namespace std;
long arr[400000];
int main()
{
    int n, num = 0;
    long k;
    scanf("%d", &n);
    for(int i=0; i < n; i++){
        scanf("%ld", &arr[num++]);
    }
    scanf("%d",&n);
    for(int i=0; i < n; i++){
        scanf("%ld",&arr[num++]);
    }
    sort(arr, arr + num);
    k = arr[(num-1)/2];
    printf("%ld", k);
    return 0;
}
