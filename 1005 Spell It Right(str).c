#include <stdio.h>
char * engDigit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void num2eng(int num);
int main(){
    char number[102];
    int sum = 0;
    scanf("%s", number);
    for(int i = 0; number[i] != '\0'; i++){
       sum += number[i] - '0';
    }
    num2eng(sum);
    return 0;
}
void num2eng(int num){
    if(num < 10){
        printf("%s", engDigit[num]);
    } else {
        num2eng(num/10);
        printf(" %s", engDigit[num%10]);
    }
}
