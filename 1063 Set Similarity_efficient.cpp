#include <stdio.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m[51];

int main()
{
	int N, M, K, value;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &M);
		for(int j = 0; j < M; j++){
			scanf("%d", &value);
			m[i][value] = 1;
		}
	}
	scanf("%d", &K);
	int s1, s2;
	float similarity = 0.0;
	for(int i = 0; i < K; i++){
		scanf("%d %d", &s1, &s2);
		int commonNum = 0;
		unordered_map<int,int>::iterator it = m[s1].begin();
		while(it != m[s1].end()) {
			if(m[s2].count(it->first)==1){
				commonNum++;
			}
			it++;
		}
		similarity = (float)(commonNum) / (m[s1].size()+m[s2].size()-commonNum);
		printf("%.1f%%\n", similarity*100);
	}
	return 0;
}
