#include <stdio.h>
#define UP_TIME 6 //��������һ�㻨�ѵ�ʱ��
#define DOWN_TIME 4 //�����½�һ�㻨�ѵ�ʱ��
#define STAY_TIME 5 //����ͣ��һ�λ��ѵ�ʱ��
int main()
{
    int count; //�������
    int curFloor, nextFloor; //curFloorΪ��ǰ����, nextFloor��һ������Ĳ���
    int totalTime = 0;
    curFloor = 0;
    scanf("%d", &count);
    for(int i = 0; i < count; i++) {
        scanf("%d", &nextFloor);
        if(nextFloor > curFloor){
            totalTime += (nextFloor - curFloor) * UP_TIME;
        }
        if(nextFloor < curFloor){
            totalTime += (curFloor - nextFloor) * DOWN_TIME;
        }
        totalTime += STAY_TIME;
        curFloor = nextFloor;
    }
    printf("%d", totalTime);
    return 0;
}
