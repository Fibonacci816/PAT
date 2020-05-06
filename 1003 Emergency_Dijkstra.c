#include<stdio.h>
#define INF 0x3f3f3f3f
#define MAX 501
int map[MAX][MAX], visited[MAX], path_number[MAX], dist[MAX], teams[MAX], team_account[MAX];//distΪc1������ľ���
int c1, c2, n, m;
void Dijkstra()
{
    int i, j, dmin, u;//uΪ��ǰ�ڵ㣬dminΪc1����ǰ�ڵ����̾���
    path_number[c1] = 1;
    team_account[c1] = teams[c1];
    dist[c1] = 0;
    for(i=0; i<n; i++){
        dmin = INF;
        //�ҵ�����c1�����δ�����ʵĽڵ�
        for(j=0; j<n; j++){
            if(dist[j]<dmin && visited[j]==0){
                dmin = dist[j];
                u = j;
            }
        }
        //�����ǰ�ڵ���c2�����ѭ��������������������
        if(dmin==INF || u==c2){
            break;
        }
        visited[u] = 1;
        for(j=0; j<n; j++){
            //�ڵ�u����󣬸�������δ�����ʵĽڵ����Ϣ
            if(visited[j] == 0){
                if(dist[j] > dist[u] + map[u][j]){
                   dist[j] = dist[u] + map[u][j];
                   path_number[j] = path_number[u];
                   team_account[j] = team_account[u] + teams[j];
                } else if(dist[j] == dist[u] + map[u][j]){
                    path_number[j] += path_number[u];
                    if(team_account[j] < team_account[u] + teams[j]){
                        team_account[j] = team_account[u] + teams[j];
                    }
                }
            }
        }
    }
}
int main()
{
    int i, j, p;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for(i=0; i<n; i++){
        scanf("%d", &teams[i]);
    }
    for(i=0; i<n; i++){
        dist[i] = INF;
        for(j=0; j<n; j++){
            map[i][j] = INF;
        }
    }
    for(int k=0; k<m; k++){
        scanf("%d %d %d", &i, &j, &p);
        map[i][j] = map[j][i] = p;
    }
    Dijkstra();
    printf("%d %d", path_number[c2], team_account[c2]);
    return 0;
}
