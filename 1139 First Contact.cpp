#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

set<string> relations[10000];
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first != p2.first ? p1.first < p2.first : p1.second < p2.second;
}
vector<pair<int, int>> FindFriends(string person1, string person2)
{
	vector<pair<int, int>> result;
	for(auto it1 = relations[abs(stoi(person1))].begin(); it1 != relations[abs(stoi(person1))].end(); it1++){
		if((*it1).length() == person1.length() && *it1 != person2){
			for(auto it2 = relations[abs(stoi(person2))].begin(); it2 != relations[abs(stoi(person2))].end(); it2++){
				if((*it2).length() == person2.length() && *it2 != person1){
					auto it = relations[abs(stoi(*it1))].find(*it2);  //若在输入的时候存储了两个人是否有联系（如用flag[p1*10000+p2]标识p1和p2是否有联系），这里可以直接判断而不必查找 
					if(it != relations[abs(stoi(*it1))].end())
						result.push_back(make_pair(abs(stoi(*it1)), abs(stoi(*it2))));
				}
			}
		}
	}
	return result;
}

int main()
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	char person1[10], person2[10];
	for(int i = 0; i < M; i++){
        scanf("%s %s", person1, person2);
        relations[abs(atoi(person1))].insert(person2);
        relations[abs(atoi(person2))].insert(person1);
	}
	scanf("%d", &K);
	for(int i = 0; i < K; i++){
        scanf("%s %s", &person1, &person2);
        vector<pair<int, int>> result = FindFriends(person1, person2);
        sort(result.begin(), result.end(), cmp);
        printf("%d\n", result.size());
        for(int j = 0; j < result.size(); j++)
        	printf("%04d %04d\n", result[j].first, result[j].second);
	}
	return 0;
 } 
