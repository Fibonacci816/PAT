#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct Institution{
	double TWS; 
    int testeeNum;
};
bool cmp(pair<string, Institution> p1, pair<string, Institution> p2)
{
	if((int)p1.second.TWS != (int)p2.second.TWS)
		return (int)p1.second.TWS > (int)p2.second.TWS;
	else if(p1.second.testeeNum != p2.second.testeeNum)
		return p1.second.testeeNum < p2.second.testeeNum;
	else
		return p1.first < p2.first;
}

int main()
{
	int N;
	scanf("%d", &N);
	char id[10], school[10];
	int score; 
	map<string, Institution> institutions;
	for(int i = 0; i < N; i++){
		scanf("%s %d %s", id, &score, school);
		string school_str = school;
		transform(school_str.begin(), school_str.end(), school_str.begin(), ::tolower);
		if(id[0] == 'B'){
			institutions[school_str].TWS += score / 1.5;
		} else if(id[0] == 'A'){
			institutions[school_str].TWS += score;
		} else if(id[0] == 'T'){
			institutions[school_str].TWS += score * 1.5;
		}
        institutions[school_str].testeeNum++;
	}
	vector<pair<string, Institution>> vec(institutions.begin(), institutions.end());
	sort(vec.begin(), vec.end(), cmp);
	printf("%d\n", vec.size());
	printf("%d %s %d %d\n", 1, vec[0].first.c_str(), (int)vec[0].second.TWS, vec[0].second.testeeNum);
	int rank = 1;
	for(int i = 1; i < vec.size(); i++){
		if((int)vec[i].second.TWS != (int)vec[i-1].second.TWS)
			rank = i + 1;
		printf("%d %s %d %d\n", rank, vec[i].first.c_str(), (int)vec[i].second.TWS, vec[i].second.testeeNum);
	}
	return 0;
 } 
