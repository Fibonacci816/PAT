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
    int road[n][n];//road��¼���������ڵ������·��
    int path[n][n];//path��¼�������ڵ�����·�������Ľڵ㣬���ⲻ��Ҫ�����·�������path�ǿ���û�е�
    int pathNum[n][n];//pathNum��¼�����������·��������
    int teamAccount[n][n];//teamAccount��¼�����������·���ϵ�����Ԯ������
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
