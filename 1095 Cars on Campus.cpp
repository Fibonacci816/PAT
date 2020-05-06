#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

struct Car{
	char plate_number[10];
	int timeInSecond;
	char status[5]; 
};

bool cmp(Car car1, Car car2)
{
	if(strcmp(car1.plate_number, car2.plate_number) != 0){
		return strcmp(car1.plate_number, car2.plate_number) < 0 ? true : false;
	}
	return car1.timeInSecond < car2.timeInSecond;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	Car cars[N];
	int hh, mm, ss;
	for(int i = 0; i < N; i++){
		scanf("%s %d:%d:%d %s", cars[i].plate_number, &hh, &mm, &ss, cars[i].status);
		cars[i].timeInSecond = hh*60*60 + mm*60 + ss;
	}
	sort(cars, cars+N, cmp);
	int curTime = 0, longestTime = 0;
	vector<string> carsWithLongestTime;
	map<int, int> inAndOut;  //存放时间点对应的进出车辆数量 
	for(int i = 0; i < N-1; i++){
		if(strcmp(cars[i].status, "in")==0){
			if(strcmp(cars[i].plate_number, cars[i+1].plate_number)==0 && strcmp(cars[i+1].status, "out")==0){
				curTime += cars[i+1].timeInSecond - cars[i].timeInSecond;
				inAndOut[cars[i].timeInSecond] += 1;
				inAndOut[cars[i+1].timeInSecond] -= 1;
			}
		}
		if(i==N-2 || strcmp(cars[i].plate_number, cars[i+1].plate_number)!=0){
			if(longestTime < curTime){
				longestTime = curTime;
				carsWithLongestTime.clear();
				carsWithLongestTime.push_back(cars[i].plate_number);
			} else if(longestTime == curTime){
				carsWithLongestTime.push_back(cars[i].plate_number);
			}
			curTime = 0;
		}
	}
	map<int, int>::iterator it = inAndOut.begin(); 
	int carNum = 0;
	for(int i = 0; i < K; i++){
		scanf("%d:%d:%d", &hh, &mm, &ss);
		curTime = hh*60*60 + mm*60 + ss;
		for(; it != inAndOut.end(); it++){
			if(it->first <= curTime){
				carNum += it->second;
			} else {
				printf("%d\n", carNum);
				break;
			}
		}
		if(it == inAndOut.end())
			printf("%d\n", 0);  //此时所有进入车辆都已离开 
	}
	for(int i = 0; i < carsWithLongestTime.size(); i++)
		cout << carsWithLongestTime[i] << " ";
	printf("%02d:%02d:%02d", longestTime / 3600, (longestTime % 3600) / 60, (longestTime % 3600) % 60);
	return 0;
}
