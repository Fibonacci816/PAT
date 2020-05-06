#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, in[30], post[30], maxLevel = 0;
vector<int> nodesAtLevel[30];  //nodesAtLevel[i]��ŵ�i�����нڵ�

void Create(int root, int start, int end, int level)
{
	if(start > end) return;
	if(level > maxLevel) maxLevel = level;
	nodesAtLevel[level].push_back(post[root]);  //��������˳���Žڵ㵽��Ӧ�Ĳ㣬ÿ���Žڵ��˳��һ���Ǵ����ҵ� 
	int i = start;
	for(; i<end && in[i]!=post[root]; i++);
	Create(root-(end-i)-1, start, i-1, level+1);
	Create(root-1, i+1, end, level+1);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &in[i]);
	} 
	for(int i = 0; i < N; i++){
		scanf("%d", &post[i]);
	} 
	Create(N-1, 0, N-1, 0);
    printf("%d", nodesAtLevel[0][0]);
	for(int i = 1; i <= maxLevel; i++){
		if(i % 2 == 0)
			reverse(nodesAtLevel[i].begin(), nodesAtLevel[i].end());
		for(int j = 0; j < nodesAtLevel[i].size(); j++)
			printf(" %d", nodesAtLevel[i][j]);
	}
	return 0;
 } 
