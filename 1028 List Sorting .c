#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NodeS{
    char ID[7];
    char name[9];
    int grade;
} Node;
Node nodes[100000];
int cmp1(const void * a, const void *b)
{
    return strcmp((*(Node *)a).ID, (*(Node *)b).ID);
}
int cmp2(const void * a, const void *b)
{
    int cmp = strcmp((*(Node *)a).name, (*(Node *)b).name);
    return cmp != 0 ? cmp : strcmp((*(Node *)a).ID, (*(Node *)b).ID);
}
int cmp3(const void * a, const void *b)
{
    int cmp = (*(Node *)a).grade - (*(Node *)b).grade;
    return cmp != 0 ? cmp : strcmp((*(Node *)a).ID, (*(Node *)b).ID);
}
int main()
{
    int N, C;
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++){
        scanf("%s %s %d", nodes[i].ID, nodes[i].name, &nodes[i].grade);
    }
    switch(C){
        case 1:
            qsort(nodes, N, sizeof(Node), cmp1);
            break;
        case 2:
            qsort(nodes, N, sizeof(Node), cmp2);
            break;
        case 3:
            qsort(nodes, N, sizeof(Node), cmp3);
    }
    for(int i = 0; i < N; i++){
        printf("%s %s %d\n", nodes[i].ID, nodes[i].name, nodes[i].grade);
    }
    return 0;
}
