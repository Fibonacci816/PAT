#include <iostream>
#include <vector>
using namespace std;

int N, pre[1000], isPreOrder = 1;
vector<int> post;

//isMirrorΪtrue��ʾ������С�ڸ����������������ڸ���
//ע��������һ������ǰ�������������Ϊ�գ���Ŀ���ῼ��ֻ��һ���������������Ϊ�⽫�޷�ȷ�����е�һ�������������������������������ì��
void GetPost(int start, int end, bool isMirror) 
{
	if(!isPreOrder || start > end) return;
	int i = start+1;
	//�˳�ѭ��ʱ��iΪ�������������±� 
	for(; i <= end; i++) {
		if(isMirror && pre[i] < pre[start]) break;
		else if(!isMirror && pre[i] >= pre[start]) break;
	}
	//�ж����������н���Ƿ񶼴��ڻ�С�ڸ��ڵ�
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
