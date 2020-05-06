#include <iostream>
#include <algorithm>
using namespace std;

struct Person{
	string name;
	int height;
};
Person people[10000];
bool cmp(Person p1, Person p2)
{
	return p1.height != p2.height ? p1.height > p2.height : p1.name < p2.name;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++){
		cin >> people[i].name >> people[i].height;
	}
	sort(people, people+N, cmp);
	int index = 0, flag;
	for(int i = 0; i < K; i++){
		int curNum = N / K;
		if(i == 0)
			curNum += N % K;
		string ansPerRow = people[index++].name;
		flag = 0;  //flagΪ0��ʾ����߲��룬Ϊ1��ʾ���ұ߲��� 
		for(int j = 1; j < curNum; j++){
			if(flag == 0){
				ansPerRow = people[index++].name + " " + ansPerRow;
				flag = 1;
			} else {
				ansPerRow = ansPerRow + " " + people[index++].name;
				flag = 0;
			}
		}
		cout << ansPerRow << endl;
	}
	return 0;
}
