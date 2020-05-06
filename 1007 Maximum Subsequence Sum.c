#include <stdio.h>
int main()
{
    int num;
    int startNumber, endNumber, thisCount, maxCount; //thisCount为当前子串的和，maxCount为最大子串的和
    scanf("%d", &num);
    int numbers[num];
    for(int i = 0; i < num; i++) {
        scanf("%d", &numbers[i]);
    }
    //初始化startNumber、endNumber、maxCount均为输入的第一个数字
    maxCount = startNumber = endNumber = numbers[0];
    //遍历所有子列
    for(int i = 0; i < num; i++){
        thisCount = 0;
        for(int j = i; j < num; j++){
            thisCount += numbers[j];
            if(thisCount > maxCount) {
                maxCount = thisCount;
                startNumber = numbers[i];
                endNumber = numbers[j];
            }
        }
    }
    //如果最大子串的值为负，则说明所有数字均为负，此时最大子串和为0，输startNumber为第一个数字，endNumber为最后一个数字
    if(maxCount < 0){
        maxCount = 0;
        startNumber = numbers[0];
        endNumber = numbers[num-1];
    }
    printf("%d %d %d", maxCount, startNumber, endNumber);
    return 0;
}
