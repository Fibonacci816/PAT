#include <stdio.h>
#include <math.h>
void Format(int sum);
int main(void)
{
    int a, b, sum;
    scanf("%d %d", &a, &b);
    sum = a + b;
    Format(sum);
    return 0;
}
void Format(int sum)
{
    if(abs(sum)<1000){
        printf("%d", sum);
    } else {
        Format(sum/1000);
        printf(",%03d", abs(sum%1000));
    }
}
