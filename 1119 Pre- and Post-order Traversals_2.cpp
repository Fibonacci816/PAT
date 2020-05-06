#include<iostream>
#include<vector>
using namespace std;

int N, pre[30], post[30], flag = 1;
vector<int> in;

void GetIn(int preStart, int preEnd, int postStart, int postEnd)
{
	if(preStart == preEnd) {
		in.push_back(pre[preStart]);
		return;
	}
	int leftPostEnd;
	for(leftPostEnd = postStart; leftPostEnd < postEnd && post[leftPostEnd] != pre[preStart+1]; leftPostEnd++);
	GetIn(preStart+1, preStart+1+leftPostEnd-postStart, postStart, leftPostEnd);
	in.push_back(pre[preStart]);
	if(leftPostEnd+1 <= postEnd-1)  //条件成立说明只有一课子树，那么这棵子树既可以是左子树也可以是右子树（在这里把右子树做为空树） 
		GetIn(preStart+1+leftPostEnd-postStart+1, preEnd, leftPostEnd+1, postEnd-1);
	else
		flag = 0;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", &post[i]);
	}
	GetIn(0, N-1, 0, N-1);
	printf("%s\n", flag ? "Yes" : "No");
	for(int i = 0; i < in.size(); i++) {
		if(i != 0) printf(" ");
		printf("%d", in[i]);
	}
	printf("\n");
	return 0;
 } 
