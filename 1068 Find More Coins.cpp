#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int coins[10000];
vector<int> solutionQue;
unordered_map<int, int> Map;

int main()
{
	int N, M, count = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
        scanf("%d", &coins[i]);
    }
    sort(coins, coins+N);
    if(coins[0] > M){
    	printf("No Solution");
    	return 0;
	}
    for(int i = 0; i < N; i++){
        Map[coins[i]] = i;
    }
    int index = 0;
    while(1){
    	if(index == N){
    		printf("No Solution");
    		return 0;
		}
    	if(count+coins[index] <= M){
    		solutionQue.push_back(coins[index]);
    		count += coins[index];
    		if(count == M)
    			break;
		} else if(!solutionQue.empty()){
			count -= solutionQue.back();
			index = Map[solutionQue.back()];
			solutionQue.pop_back();
		}
		index++;
	}
	for(int i = 0; i < solutionQue.size(); i++){
        printf("%d", solutionQue[i]);
        if(i != solutionQue.size()-1){
        	printf(" ");
		}
    }
	return 0;
}
