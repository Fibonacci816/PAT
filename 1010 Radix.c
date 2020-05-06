#include<stdio.h>
#include<string.h>
#define MAX 15
//字符转为对应数字
long long int change(char c)
{
    if(c >= '0' && c <= '9'){
        return (c - '0');
    } else {
        return (c - 'a' + 10);
    }
}
//转为十进制
long long calculate_value(char a[], long long int radix)
{
    long long int n = 0;
    for(int i = 0; i < strlen(a); i++){
        n *= radix;
        n += change(a[i]);
        //n = n * radix + change(a[i]);
        //若n<0则说明发生了上溢
        if(n < 0){
            return -1;
        }
    }
    return n;
}
void swap(char * str1, char * str2)
{
    char t[MAX];
    strcpy(t, str1);
    strcpy(str1, str2);
    strcpy(str2, t);
}
int main()
{
    long long int radix, tag, sum, min_value, max_value, mildle, sum2; //min_value和max_value分别为进制的上下限
    char N1[MAX], N2[MAX];
    scanf("%s %s %lld %lld", N1, N2, &tag, &radix);
    if(tag == 2){
        swap(N1, N2);
    }
    sum = calculate_value(N1, radix);
    min_value = 0;
    //进制的下限为每一位数字中的最大数字+1（因为一个m进制的数的每一位数字必小于m）
    for(int i = 0; i < strlen(N2); i++)
    {
        if(min_value < change(N2[i])){
            min_value = change(N2[i]) + 1;
        }
    }
    //因为如果进制不唯一则找最小进制，所以进制的上限为该数对应的十进制数+1（因为对于任意十进制数n，它必为n+1进制数）
    max_value = sum + 1;
    //printf("%lld %lld", min_value, max_value);
    //二分法查找进制
    while(min_value <= max_value){
        mildle = (min_value + max_value) / 2;
        sum2 = calculate_value(N2, mildle);
        //printf("%lld %lld\n", sum, sum2);
        if(sum2 == -1 || sum2 > sum){
            max_value = mildle - 1;
        }
        else if(sum2 < sum){
            min_value = mildle + 1;
        }
        else if(sum2 == sum){
            printf("%lld", mildle);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}
