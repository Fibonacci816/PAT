#include <stdio.h>
typedef struct NodeS{
    int arrivingTime;
    int processingTime;
} Node;
Node nodes[10000]; //记录每个customer的到达时间和处理时间
int lines[100]; //记录每个服务window的当前服务完成时间
int FindMinIndex(int n); //找到最早结束服务的那个window
int main()
{
    int n, k;
    int HH, MM, SS, totalSS, processingTime;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d:%d:%d %d", &HH, &MM, &SS, &processingTime);
        totalSS = HH * 60 * 60 + MM * 60 + SS;
        if(i == 0){
            nodes[0].arrivingTime = totalSS;
            nodes[0].processingTime = processingTime * 60;
        } else {
            int j;
            //在合适的位置插入customer，以保证customer按到达时间有序
            for(j = i; j > 0; j--){
                if(totalSS > nodes[j-1].arrivingTime){
                    break;
                }
                nodes[j] = nodes[j-1];
            }
            nodes[j].arrivingTime = totalSS;
            nodes[j].processingTime = processingTime * 60;
        }
    }
    double totalWaitSecond = 0; //所有customer等待总时长
    int servedNum = 0; //被服务的customer数量
    for(int i = 0; i < n; i++){
        if(nodes[i].arrivingTime > 17 * 60 * 60){
            //17:00之后到达的customer不被服务
            continue;
        }
        int j;
        for(j = 0; j < k; j++){
            if(lines[j] == 0){
                if(nodes[j].arrivingTime < 8 * 60 *60){
                    //08:00前到达的customer需要等到8:00才能接受服务
                    totalWaitSecond += 8 * 60 *60 - nodes[j].arrivingTime;
                    lines[j] = 8 * 60 * 60 + nodes[j].processingTime;
                } else {
                    lines[j] = nodes[j].arrivingTime + nodes[j].processingTime;
                }
                break;
            }
        }
        if(j == k){
            //如果所有window均被占用，则找一个结束时间最早的window，选择该window服务
            int index = FindMinIndex(k);
            if(nodes[i].arrivingTime < lines[index]){
                //如果customer的到达时间早于待服务window的结束时间则需等待该window服务完成
                totalWaitSecond += lines[index] - nodes[i].arrivingTime;
                lines[index] += nodes[i].processingTime;
            } else {
                lines[index] = nodes[i].arrivingTime + nodes[i].processingTime;
            }
        }
        servedNum++;
    }
    printf("%.1f", totalWaitSecond/60/servedNum);
    return 0;
}
int FindMinIndex(int n)
{
    int minIndex = 0;
    int minValue = lines[0];
    for(int i = 0; i < n; i++){
        if(lines[i] < minValue){
            minValue = lines[i];
            minIndex = i;
        }
    }
    return minIndex;
}
