#include <stdio.h>
#define START_HOUR 8
#define CLOSE_HOUR 17
typedef struct NodeS{
    int line;
    int minute;
} Node;
int processingTimes[1001]; //ÿ��customer�Ĵ���ʱ��
int finishTimes[1001]; //ÿ��customer�����ʱ��
int linesLen[20]; //ÿ��line�ĳ���
int linesTime[20]; //ÿ��line���ۼ�ʱ��
void printTime(int finishTime, int processingTime); //��ӡʱ���ʽ
int haveLine(int lineNum, int maxLineLen); //�ж��Ƿ���line�����Է���
int main()
{
    int N, M, K, Q;
    int minLen, minLenLine;
    int serveNum = 0;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    Node nodes[N * M]; //������У���ʱ��˳������
    for(int i = 1; i <= K; i++){
        scanf("%d", &processingTimes[i]);
    }
    int nodeIndex = 0;
    int i = 1;
    while(i <= K){
        if(haveLine(N, M) && serveNum < K){
            ++serveNum;
            minLen = linesLen[0];
            minLenLine = 0;
            for(int j = 1; j < N; j++){
                if(linesLen[j] < minLen){
                    minLen = linesLen[j];
                    minLenLine = j;
                }
            }
            ++linesLen[minLenLine];
            linesTime[minLenLine] += processingTimes[i];
            finishTimes[i] = linesTime[minLenLine];
            //printf("**%d %d %d**\n", processingTimes[i], finishTimes[i], minLenLine);
            if(serveNum == 1){
                nodes[0].line = minLenLine;
                nodes[0].minute = finishTimes[i];
            } else {
                ++nodeIndex;
                int k = nodeIndex;
                //����ʱ��˳��Ѱ�Һ��ʵĲ����
                for(; k > 0; k--){
                    if(finishTimes[i] >= nodes[k - 1].minute){
                        break;
                    }
                    nodes[k] = nodes[k - 1];
                }
                nodes[k].line = minLenLine;
                nodes[k].minute = finishTimes[i];
            }
            ++i;
        } else {
            //���д��ڶ�������������ʱ��������Ǹ��ͻ��뿪����Ӧ���ڵĳ���-1
            --linesLen[nodes[0].line];
            for(int l = 0; l < nodeIndex; l++){
                nodes[l] = nodes[l + 1];
            }
            --nodeIndex;
        }
    }
    int quest;
    for(int i = 0; i < Q; i++){
        scanf("%d", &quest);
        printTime(finishTimes[quest], processingTimes[quest]);
        if(i != Q - 1){
            printf("\n");
        }
    }
    return 0;
}
void printTime(int finishTime, int processingTime)
{
    //һ��customer��17��00֮ǰ��÷�����ô�������Ĵ���ʱ���ж೤��ҲҪΪ��������
    if(finishTime - processingTime < (CLOSE_HOUR - START_HOUR) * 60){
        printf("%02d:%02d", START_HOUR + finishTime / 60, finishTime % 60);
    } else {
        printf("Sorry");
    }
}
int haveLine(int lineNum, int maxLineLen)
{
    for(int i = 0; i < lineNum; i++){
        if(linesLen[i] < maxLineLen){
            return 1;
        }
    }
    return 0;
}
