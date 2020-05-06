#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pre[30], post[30], flag = 1;
vector<int> in;

void GetIn(int preLeft, int preRight, int postLeft, int postRight)
{
	if(preLeft == preRight){
		in.push_back(pre[preLeft]);
		return;
	}
	int i = preLeft+1;
	for(; i <= preRight && pre[i] != post[postRight-1]; i++);
	if((i-1)-(preLeft+1)>=0)
		GetIn(preLeft+1, i-1, postLeft, postLeft+(i-1)-(preLeft+1));
	else
		flag = 0;
	in.push_back(pre[preLeft]);
	GetIn(i, preRight, postLeft+(i-1)-(preLeft+1)+1, postRight-1);
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < N; i++){
		scanf("%d", &post[i]);
	}
	GetIn(0, N-1, 0, N-1);
	printf("%s\n", flag ? "Yes" : "No");
	for(int i = 0; i < in.size(); i++){
		if(i != 0)
			printf(" ");
		printf("%d", in[i]);
	}
	printf("\n");  //以防莫名其妙的格式错误 
	return 0;
}
