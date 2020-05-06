#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Car {
	string id;
	int time;
	string status;
};
Car cars[10000];

bool cmp(Car car1, Car car2)
{
	return car1.id != car2.id ? car1.id < car2.id : car1.time < car2.time;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	char id[10], status[5];
	int hh, mm, ss;
	for(int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d %s", id, &hh, &mm, &ss, status);
		cars[i] = Car{id, hh*3600+mm*60+ss, status};
	}
	sort(cars, cars+N, cmp);
	map<int, int> carNumAtTime;
	map<string, int> carParkTime;
	int longestTime = 0;
	for(int i = 1; i < N; i++) {
		if(cars[i-1].id == cars[i].id && cars[i-1].status == "in" && cars[i].status == "out") {
			carNumAtTime[cars[i-1].time]++;
			carNumAtTime[cars[i].time]--;
			carParkTime[cars[i].id] += cars[i].time - cars[i-1].time;
			longestTime = max(carParkTime[cars[i].id], longestTime);
		}
	}
	auto it = carNumAtTime.begin();
	int count = 0;
	for(int i = 0; i < K; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		while(it != carNumAtTime.end() && it->first <= hh*3600+mm*60+ss)
			count += it++->second;
		printf("%d\n", count);
	}
	for(auto it = carParkTime.begin(); it != carParkTime.end(); it++){
		if(it->second == longestTime)
			printf("%s ", it->first.c_str());
	}
	printf("%02d:%02d:%02d", longestTime/3600, longestTime%3600/60, longestTime%60);
	return 0;
}
