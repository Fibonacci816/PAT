#include <stdio.h>
#include <limits.h>
#define INF 0x3f3f3f3f
int main(){
    int m, n;
    int c1, c2;
    int i, j, len;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    int teamNum[n];
    for(i = 0; i < n; i++){
        scanf("%d", &teamNum[i]);
    }
    int road[n][n];//road记录任意两个节点间的最短路径
    int path[n][n];//path记录任意两节点的最短路径经过的节点，此题不需要求具体路径，因此path是可以没有的
    int pathNum[n][n];//pathNum记录任意两点最短路径的条数
    int teamAccount[n][n];//teamAccount记录任意两点最短路径上的最大救援队数量
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            if(i == j){
               road[i][j] = 0;
            } else {
                road[i][j] = INF;
            }
            path[i][j] = -1;
            pathNum[i][j] = 0;
            teamAccount[i][j] = 0;
        }
    for(int k = 0; k < m; k++){
        scanf("%d %d %d", &i, &j, &len);
        road[i][j] = road[j][i] = len;
        pathNum[i][j] = 1;
        teamAccount[i][j] = teamAccount[j][i] = teamNum[i] + teamNum[j];
    }
    for(int k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(road[i][k]+road[k][j] < road[i][j]){
                    road[i][j] = road[i][k] + road[k][j];
                    path[i][j] = k;
                    pathNum[i][j] = pathNum[i][k] * pathNum[k][j];
                    teamAccount[i][j] = teamAccount[i][k] + teamAccount[k][j] - teamNum[k];
                } else if(road[i][k]+road[k][j] == road[i][j]){
                    pathNum[i][j] += pathNum[i][k] * pathNum[k][j];
                    if(teamAccount[i][j] < teamAccount[i][k] + teamAccount[k][j] - teamNum[k]){
                        teamAccount[i][j] = teamAccount[i][k] + teamAccount[k][j] - teamNum[k];
                        path[i][j] = k;
                    }
                }
            }
        }
    }
    printf("%d %d", pathNum[c1][c2], teamAccount[c1][c2]);
    return 0;
}
