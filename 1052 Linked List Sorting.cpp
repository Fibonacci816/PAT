#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Node{
	int address;
	int key;
	int next;
	int flag; //标记节点是否在list上 
} Node; 
Node nodes[100000];

bool cmp(Node node1, Node node2)
{
	if(node1.flag != node2.flag){
		return node1.flag > node2.flag;
	} 
	return node1.key < node2.key;
}

int main()
{
	int N, firstAddress, address;
	scanf("%d %d", &N, &firstAddress);
	for(int i = 0; i < N; i++){
		scanf("%d", &address);
		nodes[address].address = address;
		scanf("%d %d", &nodes[address].key, &nodes[address].next);
	}
	if(firstAddress == -1){
        printf("0 -1\n");
        return 0;
    }
	int listNodeNum = 0; //list上的节点数量 
	address = firstAddress;
	while(address != -1){
		nodes[address].flag = 1;
		listNodeNum++;
		address = nodes[address].next;
	}
	sort(nodes, nodes+100000, cmp);
	printf("%d %05d\n", listNodeNum, nodes[0].address);
	for(int i = 0; i < listNodeNum; i++){
		if(i != listNodeNum-1){
			nodes[i].next = nodes[i+1].address;
            printf("%05d %d %05d\n", nodes[i].address, nodes[i].key, nodes[i].next);
		} else {
			nodes[i].next = -1;
		    printf("%05d %d -1\n", nodes[i].address, nodes[i].key);
		}
	}
	return 0;
}
