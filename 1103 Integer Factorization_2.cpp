#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P, M, powers[401], maxFactorSum = 0;
vector<int> path, tempPath;

void DFS(int root, int powerSum, int factorSum)
{
	if(tempPath.size() == K || powerSum >= N) {
		if(tempPath.size() == K && powerSum == N && factorSum > maxFactorSum) {
			maxFactorSum = factorSum;
			path = tempPath;
		}
		return;
	}
	for(int i = root; i > 0; i--) {
		tempPath.push_back(i);
		DFS(i, powerSum+powers[i], factorSum+i);
		tempPath.pop_back();
	}
} 

int main()
{
	scanf("%d %d %d", &N, &K, &P);
	for(M = 1; pow(M, P) <= N; M++) {
		powers[M] = pow(M, P);
	}
	DFS(M-1, 0, 0);
	if(path.empty()) {
		printf("Impossible");
	} else {
		printf("%d = %d^%d", N, path[0], P);
		for(int i = 1; i < K; i++) 
			printf(" + %d^%d", path[i], P);
	}
	return 0;
 } 
