#include <iostream>
using namespace std;

struct Node{
	int data;
	int next;
};
Node nodes[100000];

int main()
{
	int firstAddr, N, K;
	int addr, data, next;
	scanf("%d %d %d", &firstAddr, &N, &K);
	for(int i = 0; i < N; i++){
		scanf("%d %d %d", &addr, &data, &next);
		nodes[addr].data = data;
		nodes[addr].next = next;
	}
	int linkedNum = 0;  //以首地址节点为头节点的链表总节点数 
	addr = firstAddr;
	while(addr != -1){
		linkedNum++;
		addr = nodes[addr].next;
	}
	int p, q, r;
	addr = firstAddr;
	for(int i = 0; i < linkedNum/K; i++){ //分段逆转链表 
		p = addr;
		q = addr;
		r = nodes[q].next;
		//一般逆转链表时p初始化为-1(NULL)，在这里p要初始化下一段逆转链表的头节点 
		for(int j = 0; j < K; j++){
			p = nodes[p].next;
		}
		if(i < linkedNum/K-1){
			for(int j = 1; j < K; j++){
				p = nodes[p].next;
			}	
		}
		//逆转此段链表 
		for(int j = 0; j < K; j++){
			nodes[q].next = p;
			p = q;
			q = r;
			r = nodes[r].next;
		}
		if(i == 0){
			firstAddr = p; //逆转链表的头（最终结果的首地址） 
		}
		addr = q; //下一段链表的头 
	}
	addr = firstAddr;
	while(nodes[addr].next != -1){
		printf("%05d %d %05d\n", addr, nodes[addr].data, nodes[addr].next);
		addr = nodes[addr].next;
	}
	printf("%05d %d -1\n", addr, nodes[addr].data);
	return 0;
}
