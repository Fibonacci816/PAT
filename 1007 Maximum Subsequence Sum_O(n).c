#include <stdio.h>
int main()
{
    int num; //numΪ�������ֵĸ���
    int firstNumber, curNumber, startNumber, startNumber2, endNumber; //firstNumberΪ��һ����������֣�curNumberΪ��ǰ�������֣�startNumber2Ϊ��ȡ��startNumber��ֵ
    int ThisSum, MaxSum; //ThisSumΪ��ǰ�Ӵ��ĺͣ�MaxSumΪ����Ӵ��ĺ�
    int flag = 0; //flag���Ա������Ӵ��Ŀ�ͷ�����Ƿ�ᷢ���仯
    ThisSum = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &curNumber);
        //��ʼ��firstNumber,startNumber,startNumber2,endNumber,MaxSum
        if(i == 0){
            firstNumber = startNumber = startNumber2 = endNumber = MaxSum = curNumber;
        }
        if(curNumber > 0 && flag) {
            startNumber2 = curNumber;
            flag = 0;
        }
        //���֮ǰ�����ֶ�Ϊ��ֵ����ǰ����Ϊ0�����޸�startNumber��endNumber��MaxSum��Ϊ0
        if (curNumber == 0 && MaxSum < 0) {
            startNumber = endNumber = MaxSum = 0;
        }
        ThisSum += curNumber;
        if(ThisSum > MaxSum) {
            //��������Ӵ��Ŀ�ͷ���ֺͽ�β�����Լ�����Ӵ��ĺ�
            startNumber = startNumber2;
            MaxSum = ThisSum;
            endNumber = curNumber;
        } else if(ThisSum < 0) {
            //��ǰ�Ӵ��ĺ�Ϊ��ֵ��ThisSum����Ϊ0����ζ������֮ǰ���е�����
            //��ʱ����Ӵ��Ŀ�ͷ���ֿ��ܷ����仯���������仯����Ӵ��϶��ڵ�ǰ����֮��
            ThisSum = 0;
            flag = 1;
        }
    }
    //�������Ӵ���ֵΪ������˵���������־�Ϊ������ʱ����Ӵ���Ϊ0����startNumberΪ��һ�����֣�endNumberΪ���һ������
    if(MaxSum < 0){
        MaxSum = 0;
        startNumber = firstNumber;
        endNumber = curNumber;
    }
    printf("%d %d %d", MaxSum, startNumber, endNumber);
    return 0;
}
