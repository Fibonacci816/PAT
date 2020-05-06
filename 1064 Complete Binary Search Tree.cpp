#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int CBTNodes[1001];
int N, i = 0;

void Create(int root)
{
	if(2*root <= N){
		Create(2*root);
	}
	CBTNodes[root] = v[i++];
	if(2*root+1 <= N){
		Create(2*root+1);
	}
}

int main()
{
	scanf("%d", &N);
	int value;
	for(int i = 0; i < N; i++){
		scanf("%d", &value);
		v.push_back(value);
	}
	sort(v.begin(), v.end());
	Create(1);
	for(int i = 1; i <= N; i++){
		printf("%d", CBTNodes[i]);
		if(i != N){
			printf(" ");
		}
	}
	return 0;
}
