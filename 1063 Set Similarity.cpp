#include <stdio.h>
#include <set>
using namespace std;

set<int> s[50];
int main()
{
	int N, M, K, value;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &M);
		for(int j = 0; j < M; j++){
			scanf("%d", &value);
			s[i].insert(value);
		}
	}
	scanf("%d", &K);
	int s1, s2;
	set<int> temp;
	float similarity = 0.0;
	for(int i = 0; i < K; i++){
		temp.clear();
		scanf("%d %d", &s1, &s2);
		temp.insert(s[s1-1].begin(), s[s1-1].end());
		temp.insert(s[s2-1].begin(), s[s2-1].end());
		similarity = (float)(s[s1-1].size()+s[s2-1].size()-temp.size()) / (temp.size());
		printf("%.1f%%\n", similarity*100);
	}
	return 0;
}
