#include <stdio.h>
#include <string.h>
#define MAX 501
int main()
{
    char id[MAX];
    int h, m, s;
    int idNum;
    char minId[MAX], maxId[MAX];
    int minTime = 24*60*60, maxTime = 0;
    scanf("%d", &idNum);
    for(int i = 0; i < idNum; i++){
        scanf("%s", id);
        scanf("%d:%d:%d", &h, &m, &s);
        if(minTime > h*60*60 + m*60 + s){
            minTime = h*60*60 + m*60 + s;
            strcpy(minId, id);
        }
        scanf("%d:%d:%d", &h, &m, &s);
        if(maxTime < h*60*60 + m*60 + s){
            maxTime = h*60*60 + m*60 + s;
            strcpy(maxId, id);
        }
    }
    printf("%s %s", minId, maxId);
    return 0;
}
