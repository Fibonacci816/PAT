#include <stdio.h>
int main()
{
    int num;
    int startNumber, endNumber, thisCount, maxCount; //thisCountΪ��ǰ�Ӵ��ĺͣ�maxCountΪ����Ӵ��ĺ�
    scanf("%d", &num);
    int numbers[num];
    for(int i = 0; i < num; i++) {
        scanf("%d", &numbers[i]);
    }
    //��ʼ��startNumber��endNumber��maxCount��Ϊ����ĵ�һ������
    maxCount = startNumber = endNumber = numbers[0];
    //������������
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
    //�������Ӵ���ֵΪ������˵���������־�Ϊ������ʱ����Ӵ���Ϊ0����startNumberΪ��һ�����֣�endNumberΪ���һ������
    if(maxCount < 0){
        maxCount = 0;
        startNumber = numbers[0];
        endNumber = numbers[num-1];
    }
    printf("%d %d %d", maxCount, startNumber, endNumber);
    return 0;
}
