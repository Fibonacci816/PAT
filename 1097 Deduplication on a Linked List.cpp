#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Node{
	int value;
	int next;
};
Node nodes[100000];

int main()
{
	int N, firstAddress, firstAddress2 = -1, curAddress, lastAddress, separateAddress = -1;
	scanf("%d %d", &firstAddress, &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &curAddress);
		scanf("%d %d", &nodes[curAddress].value, &nodes[curAddress].next);
	}
	map<int, int> Map;
	curAddress = firstAddress;
	while(curAddress != -1){
		if(Map.count(abs(nodes[curAddress].value))){
			if(firstAddress2 == -1){
				firstAddress2 = curAddress;
			} else {
				nodes[separateAddress].next = curAddress;
			}
            separateAddress = curAddress;
			nodes[lastAddress].next = nodes[curAddress].next;
		} else {
			Map[abs(nodes[curAddress].value)] = 1;
			lastAddress = curAddress;
		}
		curAddress = nodes[curAddress].next;
	}
    if(separateAddress != -1)
		nodes[separateAddress].next = -1; 
	curAddress = firstAddress;
	while(curAddress != -1){
		if(nodes[curAddress].next != -1)
			printf("%05d %d %05d\n", curAddress, nodes[curAddress].value, nodes[curAddress].next);
		else
			printf("%05d %d %d\n", curAddress, nodes[curAddress].value, nodes[curAddress].next);
		curAddress = nodes[curAddress].next;
	}
	separateAddress = firstAddress2;
	while(separateAddress != -1){
		if(nodes[separateAddress].next != -1)
			printf("%05d %d %05d\n", separateAddress, nodes[separateAddress].value, nodes[separateAddress].next);
		else
			printf("%05d %d %d\n", separateAddress, nodes[separateAddress].value, nodes[separateAddress].next);
		separateAddress = nodes[separateAddress].next;
	}
	return 0;
}
