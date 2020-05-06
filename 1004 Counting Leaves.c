#include <stdio.h>
typedef struct Node{
    int childNum;
    int level;
}node;
int main()
{
    int m, n;
    int ID;
    int childNum;
    int child;
    int maxLevel = 0;
    scanf("%d %d", &n, &m);
    node nodes[n];
    for(int i = 1; i <= n; i++){
        nodes[i].childNum = 0;
    }
    nodes[1].level = 0;
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &ID, &childNum);
        nodes[ID].childNum = childNum;
        for(int j = 0; j < childNum; j++){
            scanf("%d", &child);
            nodes[child].level = nodes[ID].level + 1;
        }
        maxLevel = nodes[ID].level + 1;
    }
    int leafNum[maxLevel+1];
    for(int i = 0; i <= maxLevel; i++){
        leafNum[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(nodes[i].childNum == 0){
            ++leafNum[nodes[i].level];
        }
    }
    for(int i = 0; i <= maxLevel; i++){
        if(i != maxLevel)
            printf("%d ", leafNum[i]);
        else
            printf("%d", leafNum[i]);
    }
    return 0;
}
