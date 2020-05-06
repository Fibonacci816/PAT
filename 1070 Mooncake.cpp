#include <stdio.h>
#include <algorithm>
#define MAX 1000
using namespace std;

struct Node{
	double inventoryAmount;
	double price;
	double perPrice;
};
Node nodes[MAX];

bool cmp(Node node1, Node node2)
{
	return node1.perPrice > node2.perPrice;
}

int main()
{
	int N, D;
	double totalProfit = 0;
	scanf("%d %d", &N, &D);
	for(int i = 0; i < N; i++){
		scanf("%lf", &nodes[i].inventoryAmount);
	}
	for(int i = 0; i < N; i++){
		scanf("%lf", &nodes[i].price);
		nodes[i].perPrice = nodes[i].price / nodes[i].inventoryAmount;
	}
	sort(nodes, nodes+N, cmp);
	for(int i = 0; i < N; i++){
		if(nodes[i].inventoryAmount >= D){
			totalProfit += nodes[i].perPrice * D;
			break;
		} else {
			totalProfit += nodes[i].price;
			D -= nodes[i].inventoryAmount;
		}
	}
	printf("%.2lf", totalProfit);
	return 0;
}
