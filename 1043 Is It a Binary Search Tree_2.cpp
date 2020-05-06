#include <iostream>
#include <vector>
using namespace std;

int N, pre[1000], isPreOrder = 1;
vector<int> post;

//isMirror为true表示左子树小于根，否则左子树大于根。
//注：这里有一个假设前提就是左子树不为空，题目不会考察只有一棵子树的情况，因为这将无法确定仅有的一棵子树是左子树还是右子树，会产生矛盾
void GetPost(int start, int end, bool isMirror) 
{
	if(!isPreOrder || start > end) return;
	int i = start+1;
	//退出循环时，i为右子树根结点的下标 
	for(; i <= end; i++) {
		if(isMirror && pre[i] < pre[start]) break;
		else if(!isMirror && pre[i] >= pre[start]) break;
	}
	//判断右子树所有结点是否都大于或都小于根节点
	for(int j = i; j <= end; j++) {
		if((isMirror && pre[j] >= pre[start]) || (!isMirror && pre[j] < pre[start])) {
			isPreOrder = 0;
			return;
		} 
	}
	GetPost(start+1, i-1, isMirror);
	GetPost(i, end, isMirror);
	post.push_back(pre[start]);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &pre[i]);
	if(pre[0] > pre[1]) GetPost(0, N-1, false);
	else GetPost(0, N-1, true);
	if(isPreOrder) {
		printf("YES\n%d", post[0]);
		for(int i = 1; i < post.size(); i++)
			printf(" %d", post[i]);
	} else {
		printf("NO");
	}
	return 0;
 } 
