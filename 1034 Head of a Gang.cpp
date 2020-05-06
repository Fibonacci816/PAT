#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//index为实际输入节点的数量，memberWeight为cluster中每个成员的通话时长，maxWeight为cluster的head的通话时长，memberNum为cluster的成员数量，totalWeight为cluster通话总时长 
int N, K, index = 0, connectMap[2001][2001], nodeVisited[2001], edgeVisited[2001][2001], memberWeight[2001], maxWeight, memberNum, totalWeight;
string names[2001], memberWithMaxWeight;  //memberWithMaxWeight为cluster的head的名字 
map<string, int> name2index;

int GetIndex(string name)
{
	if(name2index.count(name) == 0){
		names[index] = name;
		name2index[name] = index++;  //每有一个新的节点，index自增1 
	}
	return name2index[name];
}
void DFS(int root)
{
	if(nodeVisited[root]==0){
		nodeVisited[root] = 1;
		memberNum++;
	}
	for(int i = 0; i < index; i++){
		if(edgeVisited[root][i]==0 && connectMap[root][i]!=0){
			edgeVisited[root][i] = edgeVisited[i][root] = 1;
			memberWeight[root] += connectMap[root][i];
			if(memberWeight[root] > maxWeight){
				maxWeight = memberWeight[root];
				memberWithMaxWeight = names[root];
			}
			memberWeight[i] += connectMap[i][root];	
			if(memberWeight[i] > maxWeight){
				maxWeight = memberWeight[i];
				memberWithMaxWeight = names[i];
			}
			totalWeight += connectMap[root][i];
			DFS(i);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	char name1[5], name2[5];
	int time;
	for(int i = 0; i < N; i++){
		scanf("%s %s %d", name1, name2, &time);
		connectMap[GetIndex(name1)][GetIndex(name2)] += time;
		connectMap[GetIndex(name2)][GetIndex(name1)] += time; 
	}
	int gangNum = 0;
	map<string, int> head;
	for(int i = 0; i < index; i++){
		if(nodeVisited[i] == 0){
			memberNum = 0;
			maxWeight = 0;
			totalWeight = 0;
			DFS(i);
			//cout << memberNum << " " << totalWeight << endl;
			if(memberNum>2 && totalWeight>K){
				head[memberWithMaxWeight] = memberNum;
				gangNum++;
			}
		}
	}
	printf("%d\n", gangNum);
	if(gangNum != 0){
		for(map<string, int>::iterator it = head.begin(); it != head.end(); it++){
			cout << it->first << " " << it->second << endl;
		}
	}
	return 0;
}
