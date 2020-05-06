#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, firstOneWithHobby[1001], father[1001];  //father[i]�洢i�ڵ�ĸ��ף������ֵΪ����ʾi�ڵ�Ϊ���ڵ㣬�����෴��Ϊ����Ϊ���ļ��ϵ��ܽ���� 

int FindFather(int node)
{
	for(; father[node] >= 0; node = father[node]);
	return node;
} 
void Combine(int a, int b)
{
	int fa = FindFather(a);
	int fb = FindFather(b);
	if(fa != fb){
		father[fa] += father[fb];  //�ϲ���ļ����ܽ����Ϊ�����ϵ��ܽ����֮�� 
		father[fb] = fa;
	}
}

int main()
{
	scanf("%d", &N);
	fill(father, father+N+1, -1);
	int hobbyNum, hobby;
	for(int i = 1; i <= N; i++){
		scanf("%d: ", &hobbyNum);
		for(int j = 0; j < hobbyNum; j++){
			scanf("%d", &hobby);
			if(firstOneWithHobby[hobby] == 0)
				firstOneWithHobby[hobby] = i;
			else
				Combine(firstOneWithHobby[hobby], i);
		}
	}
	sort(father+1, father+N+1);
	vector<int> ans;
	for(int i = 1; i <= N; i++){
		if(father[i] < 0)
			ans.push_back(-father[i]);
		else
			break;
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		if(i != 0)
			printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
