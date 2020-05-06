#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> &p1, pair<string, int> &p2)
{
	return p1.second != p2.second ? p1.second > p2.second : p1.first < p2.first;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	char cardNumber[20];
	int score;
	unordered_map<string, vector<pair<string, int>>> levelMap;
	unordered_map<string, pair<int, int>> siteMap;
	unordered_map<string, unordered_map<string, int>> dateMap;
	for(int i = 0; i < N; i++){
		scanf("%s %d", cardNumber, &score);
		levelMap[string(cardNumber).substr(0, 1)].push_back(make_pair(cardNumber, score));
		siteMap[string(cardNumber).substr(1, 3)].first++;
		siteMap[string(cardNumber).substr(1, 3)].second += score;
		dateMap[string(cardNumber).substr(4, 6)][string(cardNumber).substr(1, 3)]++;
	}
	for(auto it = levelMap.begin(); it != levelMap.end(); it++){
		sort(it->second.begin(), it->second.end(), cmp);
	}
	int type;
	char typeKey[10];
	for(int i = 1; i <= M; i++){
		scanf("%d %s", &type, typeKey);
		printf("Case %d: %d %s\n", i, type, typeKey);
		switch (type) {
			case 1:
				if(levelMap.count(typeKey)){
					//sort(levelMap[typeKey].begin(), levelMap[typeKey].end(), cmp);  //前面提前排好序这里就不用再排了 
					for(int j = 0; j < levelMap[typeKey].size(); j++){
						printf("%s %d\n", levelMap[typeKey][j].first.c_str(), levelMap[typeKey][j].second);
					}
				} else {
					printf("NA\n");
				}
				break;
			case 2:
				if(siteMap.count(typeKey)){
					printf("%d %d\n", siteMap[typeKey].first, siteMap[typeKey].second);
				} else {
					printf("NA\n");
				}
				break;
			case 3:
				if(dateMap.count(typeKey)){
					vector<pair<string, int>> temp(dateMap[typeKey].begin(), dateMap[typeKey].end());
					sort(temp.begin(), temp.end(), cmp);
					for(int j = 0; j < temp.size(); j++){
						printf("%s %d\n", temp[j].first.c_str(), temp[j].second);
					}
				} else {
					printf("NA\n");
				}
				break;	
		}
	}
	return 0;
 } 
