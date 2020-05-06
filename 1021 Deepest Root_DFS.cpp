#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
vector<int> map[10001];
int visited[10001], deeps[10001];
int DFS(int start);
int main()
{
    int i, j, N;
    scanf("%d", &N);
    for(int k = 0; k < N - 1; k++){
        scanf("%d %d", &i, &j);
        map[i].push_back(j);
        map[j].push_back(i);
    }
    int connectionNum = 0; //连通分量个数
    int maxDeep = 0;
    for(int k = 1; k <= N; k++){
        if(visited[k] == 0){
            deeps[k] = DFS(k);
            if(maxDeep < deeps[k]){
                maxDeep = deeps[k];
            }
            connectionNum++;
        }
    }
    if(connectionNum > 1){
        printf("Error: %d components", connectionNum);
    } else {
        for(int k = 1; k <= N; k++){
            if(deeps[k]){
                continue;
            }
            memset(visited, 0, sizeof(visited));
            deeps[k] = DFS(k);
            if(maxDeep < deeps[k]){
                maxDeep = deeps[k];
            }
        }
        for(int k = 1; k <= N; k++){
            if(deeps[k] == maxDeep){
                printf("%d\n", k);
            }
        }
    }
    return 0;
}
int DFS(int start)
{
    int curDeep, maxDeep = 0;
    visited[start] = 1;
    for(int i = 0; i < map[start].size(); i++){
        if(visited[map[start][i]] == 0){
            curDeep = DFS(map[start][i]);
            if(maxDeep < curDeep){
                maxDeep = curDeep;
            }
        }
    }
    return maxDeep + 1;
}
