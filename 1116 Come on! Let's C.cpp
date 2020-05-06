#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

bool IsPrime(int number)
{
	for(int i = 2; i <= sqrt(number); i++){
		if(number % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int N, K, ID;
	scanf("%d", &N);
	unordered_map<int, int> idMap;
	for(int i = 1; i <= N; i++){
		scanf("%d", &ID);
		idMap[ID] = i;
	}
	scanf("%d", &K);
	for(int i = 1; i <= K; i++){
		scanf("%d", &ID);
		if(idMap.count(ID)){
			if(idMap[ID] == 0){
				printf("%04d: Checked\n", ID);
			} else if(idMap[ID] == 1){
				printf("%04d: Mystery Award\n", ID);
				idMap[ID] = 0;
			} else if(IsPrime(idMap[ID])){
				printf("%04d: Minion\n", ID);
				idMap[ID] = 0;
			} else {
				printf("%04d: Chocolate\n", ID);
				idMap[ID] = 0;
			}
		} else {
			printf("%04d: Are you kidding?\n", ID);
		}
	}
	return 0;
} 
