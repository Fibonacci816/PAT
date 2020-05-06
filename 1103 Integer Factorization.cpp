#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, K, P, maxFactorSum = -1;
vector<int> powers, ans, tempAns;

void DFS(int index, int curK, int powerSum, int factorSum)
{
	if(curK == K){
		if(powerSum == N && factorSum > maxFactorSum){
			maxFactorSum = factorSum;
			ans = tempAns;
		}
		return;
	}
	while(index > 0){
		if(powerSum+powers[index] <= N){
			tempAns[curK] = index;
			DFS(index, curK+1, powerSum+powers[index], factorSum+index);
		}
		//if(index == 1)return;  //在这里返回虽然递归次数没变，但是效率也会有提升 
		index--;
	}
}

int main()
{
	scanf("%d %d %d", &N, &K, &P);
	tempAns.resize(K);
	int power = 0, factor = 0;
	while(power <= N){
		powers.push_back(power);
		power = pow(++factor, P);	
	}
	DFS(powers.size()-1, 0, 0, 0);
	if(maxFactorSum == -1){
		printf("Impossible");
	} else {
		printf("%d = ", N);
		for(int i = 0; i < K; i++){
			if(i != 0)
				printf(" + ");
			printf("%d^%d", ans[i], P);
		}
	}
	return 0;
}
