#include <stdio.h>
#include <string.h>
char characters[81];
int main()
{
    int len, subLen, spaceLen;
    scanf("%s", characters);
    len = strlen(characters);
    subLen = (len + 2) / 3; //计算U的高度
    spaceLen = len - 2 * subLen; //计算中间空格的长度
    for(int i = 0; i < subLen; i++){
        printf("%c", characters[i]);
        for(int j = 1; j <= spaceLen; j++){
            if(i == subLen - 1){
                printf("%c", characters[i+j]);
            } else {
                printf(" ");
            }
        }
        printf("%c\n", characters[len - 1 - i]);
    }
    return 0;
}
