#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int address, val, next;
};
Node nodes[100000];

int main()
{
	int firstAddress, N, K, address;
	scanf("%d %d %d", &firstAddress, &N, &K);
	for(int i = 0; i < N; i++) {
		scanf("%d", &address);
		nodes[address].address = address;
		scanf("%d %d", &nodes[address].val, &nodes[address].next);
	}
	vector<Node> list;
	for(address = firstAddress; address != -1; address = nodes[address].next) {
		list.push_back(nodes[address]);
	}
	for(int i = 0; i < list.size()/K; i++) {
		for(int j = K-1; j >= 0; j--) {
			if(i == 0 && j == K-1) 
				printf("%05d %d", list[K-1].address, list[K-1].val);
			else 
				printf(" %05d\n%05d %d", list[i*K+j].address, list[i*K+j].address, list[i*K+j].val);
		}
	}
	for(int i = list.size()/K*K; i < list.size(); i++) {
		printf(" %05d\n%05d %d", list[i].address, list[i].address, list[i].val);
	}
	printf(" %d", -1);
	return 0;
 } 
