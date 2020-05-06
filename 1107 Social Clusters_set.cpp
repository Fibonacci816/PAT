#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, firstOneWithHobby[1001], father[1001];  //father[i]存储i节点的父亲，如果其值为负表示i节点为根节点，且其相反数为以他为根的集合的总结点数 

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
		father[fa] += father[fb];  //合并后的集合总结点数为两集合的总结点数之和 
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
