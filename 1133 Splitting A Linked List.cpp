#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int address;
	int data;
	int next;
};
Node nodes[100000];

int main()
{
	int firstAddress, N, K, address;
	scanf("%d %d %d", &firstAddress, &N, &K);
	for(int i = 0; i < N; i++){
		scanf("%d", &address);
		nodes[address].address = address;
		scanf("%d %d", &nodes[address].data, &nodes[address].next);
	}
	vector<Node> negative, toK, gtK;
	for(address = firstAddress; address != -1; address = nodes[address].next){
		if(nodes[address].data < 0)
			negative.push_back(nodes[address]);
		else if(nodes[address].data <= K)
			toK.push_back(nodes[address]);
		else
			gtK.push_back(nodes[address]);
	}
	vector<Node> ans = negative;
	ans.insert(ans.end(), toK.begin(), toK.end());
	ans.insert(ans.end(), gtK.begin(), gtK.end());
	for(int i = 1; i < ans.size(); i++){
		printf("%05d %d %05d\n", ans[i-1].address, ans[i-1].data, ans[i].address);
	}
	printf("%05d %d %d\n", ans[ans.size()-1].address, ans[ans.size()-1].data, -1);
	return 0;
 } 
