#include <stdio.h>

// ����ĳ�������к��ж��ٸ�1
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
//�����1��ĳ���ֵ�����������һ�����ж��ٸ�1
int CountingOnes(int number)
{
    if(number == 0){
        return 0;
    } else if(number < 10){
        return 1;
    } else if(number%10 == 0){ //��1~number-1���������У���λ�����г���1���ܴ��� + ����λ�г���1���ܴ����� + number���������1�ĸ���
        return number/10 + CountingOnes(number/10-1)*10 + CountingStrOne(number/10);
    } else { //1~number/10*10����������1���ֵ��ܴ��� + number/10*10+1~number����������1���ֵ��ܴ���
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
