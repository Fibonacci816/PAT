#include <iostream>
using namespace std;

int sequence[1001];
bool Judge(int n)
{
	int visited[n+1][n+1] = {0};
	for(int i = 1; i <= n; i++){
		if(visited[sequence[i]][i] == 1)
			return false;
		for(int offset = 0; i+offset <= n; offset++){
			visited[sequence[i]][i+offset] = 1;
		}
		for(int offset = 0; i+offset <= n && sequence[i]-offset >= 1; offset++){
			visited[sequence[i]-offset][i+offset] = 1;
		}
		for(int offset = 0; i+offset <= n && sequence[i]+offset <= n; offset++){
			visited[sequence[i]+offset][i+offset] = 1;
		}
	}
	return true;
}

int main()
{
	int K, N;
	scanf("%d", &K);
	for(int i = 0; i < K; i++){
		scanf("%d", &N);
		for(int j = 1; j <= N; j++)
			scanf("%d", &sequence[j]);
		if(Judge(N))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
