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
	int linkedNum = 0;  //���׵�ַ�ڵ�Ϊͷ�ڵ�������ܽڵ��� 
	addr = firstAddr;
	while(addr != -1){
		linkedNum++;
		addr = nodes[addr].next;
	}
	int p, q, r;
	addr = firstAddr;
	for(int i = 0; i < linkedNum/K; i++){ //�ֶ���ת���� 
		p = addr;
		q = addr;
		r = nodes[q].next;
		//һ����ת����ʱp��ʼ��Ϊ-1(NULL)��������pҪ��ʼ����һ����ת�����ͷ�ڵ� 
		for(int j = 0; j < K; j++){
			p = nodes[p].next;
		}
		if(i < linkedNum/K-1){
			for(int j = 1; j < K; j++){
				p = nodes[p].next;
			}	
		}
		//��ת�˶����� 
		for(int j = 0; j < K; j++){
			nodes[q].next = p;
			p = q;
			q = r;
			r = nodes[r].next;
		}
		if(i == 0){
			firstAddr = p; //��ת�����ͷ�����ս�����׵�ַ�� 
		}
		addr = q; //��һ�������ͷ 
	}
	addr = firstAddr;
	while(nodes[addr].next != -1){
		printf("%05d %d %05d\n", addr, nodes[addr].data, nodes[addr].next);
		addr = nodes[addr].next;
	}
	printf("%05d %d -1\n", addr, nodes[addr].data);
	return 0;
}
