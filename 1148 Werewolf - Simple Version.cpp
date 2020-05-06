#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> statements(N+1);
	for(int i = 1; i <= N; i++){
		scanf("%d", &statements[i]);
	}
	for(int i = 1; i <= N; i++){
		for(int j = i+1; j <= N; j++){
			vector<int> liars, players(N+1, 1);
			players[i] = players[j] = -1;  //假设i，j为两个狼人 、
			for(int k = 1; k <= N; k++){
				if(statements[k] * players[abs(statements[k])] < 0)
					liars.push_back(k);
			}
			if(liars.size() == 2 && players[liars[0]] + players[liars[1]] == 0){  //若恰有两人说谎，并且一个是狼人一个是村民 
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
 } 
