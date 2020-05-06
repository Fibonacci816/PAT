#include <stdio.h>
#define INF 0x3f3f3f3f
#define MAX 500
int map[MAX][MAX], cost[MAX][MAX], visited[MAX], dist[MAX], totalCost[MAX], path[MAX];
int N, M, S, D;
int FindMinDist(); //返回未被收录节点中dist最小者，这样的节点不存在则返回-1
void Dijkstra();
void PrintPathes(int v); //打印从开始节点S到节点v的最短路径
int main()
{
    int i, j, cur_dist, cur_cost;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    //初始化
    for(i = 0; i < N; i++){
        dist[i] = INF;
        totalCost[i] = INF;
        for(j = 0; j < N; j++){
            map[i][j] = INF;
            cost[i][j] = INF;
        }
    }
    for(int k = 0; k < M; k++){
        scanf("%d %d %d %d", &i, &j, &cur_dist, &cur_cost);
        map[i][j] = map[j][i] = cur_dist;
        cost[i][j] = cost[j][i] = cur_cost;
    }
    Dijkstra();
    PrintPathes(D);
    printf("%d %d", dist[D], totalCost[D]);
    return 0;
}
int FindMinDist()
{
    int MinDist = INF;
    int MinV = -1;
    for(int i = 0; i < N; i++){
        if(visited[i] == 0 && dist[i] < MinDist){
            MinDist = dist[i];
            MinV = i;
        }
    }
    return MinV;
}
void Dijkstra()
{
    //将起始节点的dist和totalCost更新为0
    dist[S] = 0;
    totalCost[S] = 0;
    int minV;
    while(1){
        minV = FindMinDist();
        if(minV == -1 || minV == D){
            break;
        }
        //收录未被收录节点中dist最小者
        visited[minV] = 1;
        for(int i = 0; i < N; i++){
            //更新未被收录节点的信息
            if(visited[i] == 0){
                if(dist[minV] + map[minV][i] < dist[i]){
                    dist[i] = dist[minV] + map[minV][i];
                    totalCost[i] = totalCost[minV] + cost[minV][i];
                    path[i] = minV;
                } else if(dist[minV] + map[minV][i] == dist[i]){
                    if(totalCost[minV] + cost[minV][i] < totalCost[i]){
                        totalCost[i] = totalCost[minV] + cost[minV][i];
                        path[i] = minV;
                    }
                }
            }
        }
    }
}
void PrintPathes(int v)
{
    if(v != S){
        PrintPathes(path[v]);
    }
    printf("%d ", v);

}
