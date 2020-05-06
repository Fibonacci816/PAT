#include<stdio.h>
#include<string.h>
int map[1001][1001], visited[1001], road[1001];
void DFS(int start, int n);
int main()
{
    int n, m, k, x, y, num;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<m;i++){
        scanf("%d %d", &x, &y);
        map[x][y] = map[y][x] = 1;
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &road[i]);
    }
    for(int i = 0; i < k; i++){
        num = 0; //num为连通分量个数
        memset(visited, 0, sizeof(visited));
        visited[road[i]] = 1;
        //当road不可再访问时，求连通分量个数
        for(int j = 1; j <= n; j++){
            if(visited[j] == 0){
                DFS(j, n);
                num++;
            }
        }
        //将num个连通分量连成一个连通分量需要num-1条边
        printf("%d", num - 1);
        if(i != k - 1){
            printf("\n");
        }
    }
    return 0;
}
void DFS(int start, int n)
{
    visited[start] = 1;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0 && map[start][i] == 1)
            DFS(i, n);
    }
}
