#include <stdio.h>
#define UP_TIME 6 //电梯上升一层花费的时间
#define DOWN_TIME 4 //电梯下降一层花费的时间
#define STAY_TIME 5 //电梯停留一次花费的时间
int main()
{
    int count; //请求次数
    int curFloor, nextFloor; //curFloor为当前层数, nextFloor下一次请求的层数
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
