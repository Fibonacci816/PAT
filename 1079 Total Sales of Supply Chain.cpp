#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
double P, r;
vector<int> members[100000];
double prices[100000];
vector<pair<int, int>> retailers;

void DFS(int root, double price)
{
	prices[root] = price;
	for(int i = 0; i < members[root].size(); i++){
		DFS(members[root][i], price*(1+r/100));
	}
}

int main()
{
	int followNum, followed, amount;
	scanf("%d %lf %lf", &N, &P, &r);
	for(int i = 0; i < N; i++){
		scanf("%d", &followNum);
		if(followNum == 0){
			scanf("%d", &amount);
			retailers.push_back(make_pair(i, amount));
		} else {
			for(int j = 0; j < followNum; j++){
				scanf("%d", &followed);
				members[i].push_back(followed);
			}
		}		
	}
	DFS(0, P);
	double totalSales = 0;
	for(int i = 0; i < retailers.size(); i++){
		totalSales += prices[retailers[i].first] * retailers[i].second;
	}
	printf("%.1lf", totalSales);
}
