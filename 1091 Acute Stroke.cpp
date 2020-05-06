#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int x, y, z;
	Node(int _x, int _y, int _z): x(_x), y(_y), z(_z){}
};
int M, N, L, T;
int Map[1300][130][60], visited[1300][130][60];
int dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};

bool Judge(int x, int y, int z)
{
	return (x>=0&&x<M) && (y>=0&&y<N) && (z>=0&&z<L) && !visited[x][y][z] && Map[x][y][z];
}
int BFS(int x, int y, int z)
{
	int volume = 0;
	queue<Node> q;
	q.push(Node(x, y, z));
	visited[x][y][z] = 1;
	volume++;
	while(!q.empty()){
		Node node = q.front();
		q.pop();
		for(int i = 0; i < 6; i++){
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			int nz = node.z + dz[i];
			if(Judge(nx, ny, nz)){
				q.push(Node(nx, ny, nz));
				visited[nx][ny][nz] = 1;
				volume++;
			}
		}
	}
	return volume >= T ? volume : 0;
}

int main()
{
	scanf("%d %d %d %d", &M, &N, &L, &T);
	for(int k = 0; k < L; k++){
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				scanf("%d", &Map[i][j][k]);
			}
		}
	}
	int totalVolume = 0;
	for(int k = 0; k < L; k++){
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(Map[i][j][k] && !visited[i][j][k]){
					totalVolume += BFS(i, j, k);
				}
			}
		}
	}
	printf("%d",totalVolume);
	return 0;
}
