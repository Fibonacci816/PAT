#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, retailerNumWithLowestPrice = 0;
double P, r, lowestPrice = 10000000000;
vector<int> follows[100000];

void DFS(int root, double price)
{
	if(follows[root].empty()){
		if(price < lowestPrice){
			lowestPrice = price;
			retailerNumWithLowestPrice = 1;
		} else if(price == lowestPrice){
			retailerNumWithLowestPrice++;
		}
	} else {
		for(int i = 0; i < follows[root].size(); i++)
			DFS(follows[root][i], price*(1+r/100));
	}
}

int main()
{
	scanf("%d %lf %lf", &N, &P, &r);
	int follow, followNum;
	for(int i = 0; i < N; i++){
		scanf("%d", &followNum);
		for(int j = 0; j < followNum; j++){
			scanf("%d", &follow);
			follows[i].push_back(follow);
		}
	}
	DFS(0, P);
	printf("%.4lf %d", lowestPrice, retailerNumWithLowestPrice);
	return 0;
}
