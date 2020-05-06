#include <stdio.h>

// 计算某个数字中含有多少个1
int CountingStrOne(int number)
{
    int strOne = 0;
    while(number != 0){
        if(number%10 == 1){
            strOne++;
        }
        number /= 10;
    }
    return strOne;
}
//计算从1到某数字的所有数字中一共含有多少个1
int CountingOnes(int number)
{
    if(number == 0){
        return 0;
    } else if(number < 10){
        return 1;
    } else if(number%10 == 0){ //（1~number-1所有数字中：个位数字中出现1的总次数 + 其余位中出现1的总次数） + number这个数字中1的个数
        return number/10 + CountingOnes(number/10-1)*10 + CountingStrOne(number/10);
    } else { //1~number/10*10所有数字中1出现的总次数 + number/10*10+1~number所有数字中1出现的总次数
        return CountingOnes(number/10*10) + (CountingOnes(number%10) + CountingStrOne(number/10*10)*(number%10));
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d", CountingOnes(N));
    return 0;
}
