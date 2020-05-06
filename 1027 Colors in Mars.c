#include <stdio.h>
char ToRadix13(int number);
int main()
{
    int a[3];
    for(int i = 0; i < 3; i++){
        scanf("%d", a+i);
    }
    printf("#");
    for(int i = 0; i < 3; i++){
        printf("%c", ToRadix13(a[i]/13));
        printf("%c", ToRadix13(a[i]%13));
    }
    return 0;
}
char ToRadix13(int number)
{
    if(number < 10){
        return number + '0';
    } else {
        return number - 10 + 'A';
    }
}

