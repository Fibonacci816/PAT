#include <stdio.h>
char * engDigit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void num2eng(int num);
int main(){
    int number;
    int sum = 0;
    scanf("%d", &number);
    while(number != 0){
        sum += number % 10;
        number /= 10;
    }
    num2eng(sum);
    return 0;
}
void num2eng(int num){
    if(num <= 9){
        printf("%s", engDigit[num]);
    } else {
        num2eng(num/10);
        printf(" %s", engDigit[num%10]);
    }
}
