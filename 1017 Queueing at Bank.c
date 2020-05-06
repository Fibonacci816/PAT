#include <stdio.h>
typedef struct NodeS{
    int arrivingTime;
    int processingTime;
} Node;
Node nodes[10000]; //��¼ÿ��customer�ĵ���ʱ��ʹ���ʱ��
int lines[100]; //��¼ÿ������window�ĵ�ǰ�������ʱ��
int FindMinIndex(int n); //�ҵ��������������Ǹ�window
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
            //�ں��ʵ�λ�ò���customer���Ա�֤customer������ʱ������
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
    double totalWaitSecond = 0; //����customer�ȴ���ʱ��
    int servedNum = 0; //�������customer����
    for(int i = 0; i < n; i++){
        if(nodes[i].arrivingTime > 17 * 60 * 60){
            //17:00֮�󵽴��customer��������
            continue;
        }
        int j;
        for(j = 0; j < k; j++){
            if(lines[j] == 0){
                if(nodes[j].arrivingTime < 8 * 60 *60){
                    //08:00ǰ�����customer��Ҫ�ȵ�8:00���ܽ��ܷ���
                    totalWaitSecond += 8 * 60 *60 - nodes[j].arrivingTime;
                    lines[j] = 8 * 60 * 60 + nodes[j].processingTime;
                } else {
                    lines[j] = nodes[j].arrivingTime + nodes[j].processingTime;
                }
                break;
            }
        }
        if(j == k){
            //�������window����ռ�ã�����һ������ʱ�������window��ѡ���window����
            int index = FindMinIndex(k);
            if(nodes[i].arrivingTime < lines[index]){
                //���customer�ĵ���ʱ�����ڴ�����window�Ľ���ʱ������ȴ���window�������
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
