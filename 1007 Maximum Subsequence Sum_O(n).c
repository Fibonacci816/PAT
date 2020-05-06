#include <stdio.h>
int main()
{
    int num; //num为输入数字的个数
    int firstNumber, curNumber, startNumber, startNumber2, endNumber; //firstNumber为第一个输入的数字，curNumber为当前输入数字，startNumber2为待取代startNumber的值
    int ThisSum, MaxSum; //ThisSum为当前子串的和，MaxSum为最大子串的和
    int flag = 0; //flag用以标记最大子串的开头数字是否会发生变化
    ThisSum = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &curNumber);
        //初始化firstNumber,startNumber,startNumber2,endNumber,MaxSum
        if(i == 0){
            firstNumber = startNumber = startNumber2 = endNumber = MaxSum = curNumber;
        }
        if(curNumber > 0 && flag) {
            startNumber2 = curNumber;
            flag = 0;
        }
        //如果之前的数字都为负值，当前数字为0，则修改startNumber、endNumber、MaxSum均为0
        if (curNumber == 0 && MaxSum < 0) {
            startNumber = endNumber = MaxSum = 0;
        }
        ThisSum += curNumber;
        if(ThisSum > MaxSum) {
            //更新最大子串的开头数字和结尾数字以及最大子串的和
            startNumber = startNumber2;
            MaxSum = ThisSum;
            endNumber = curNumber;
        } else if(ThisSum < 0) {
            //当前子串的和为负值则ThisSum重置为0，意味着舍弃之前所有的数字
            //此时最大子串的开头数字可能发生变化，若发生变化最大子串肯定在当前数字之后
            ThisSum = 0;
            flag = 1;
        }
    }
    //如果最大子串的值为负，则说明所有数字均为负，此时最大子串和为0，输startNumber为第一个数字，endNumber为最后一个数字
    if(MaxSum < 0){
        MaxSum = 0;
        startNumber = firstNumber;
        endNumber = curNumber;
    }
    printf("%d %d %d", MaxSum, startNumber, endNumber);
    return 0;
}
