#include <iostream>
#include <unordered_map>
#define INF 0x3f3f3f3f
using namespace std;

unordered_map<string, int> happinessAtCities, visited, totalCost, totalHappiness, pathNum, cityNum;
unordered_map<string, unordered_map<string, int>> costBetweenCities;
unordered_map<string, string> path;

string FindMin()
{
	string minCity = "None";
	int minDist = INF;
	for(auto it = totalCost.begin(); it != totalCost.end(); it++) {
		if(visited[it->first] == 0 && it->second < minDist) {
			minDist = it->second;
			minCity = it->first;
		}
	}
	return minCity;
}
void Dijkstra(string start)
{
	totalCost[start] = 0;
	pathNum[start] = 1;
	while(true) {
		string minCity = FindMin();
		if(minCity == "None" || minCity == "ROM") break;
		visited[minCity] = 1;
		for(auto it = totalCost.begin(); it != totalCost.end(); it++) {
			if(visited[it->first] == 0 && costBetweenCities[minCity].count(it->first)) {
				if(it->second > totalCost[minCity] + costBetweenCities[minCity][it->first]) {
					it->second = totalCost[minCity] + costBetweenCities[minCity][it->first];
					pathNum[it->first] = pathNum[minCity];
					totalHappiness[it->first] = totalHappiness[minCity] + happinessAtCities[it->first];
					path[it->first] = minCity;
					cityNum[it->first] = cityNum[minCity] + 1;
				} else if(it->second == totalCost[minCity] + costBetweenCities[minCity][it->first]) {
					pathNum[it->first] += pathNum[minCity];
					if(totalHappiness[it->first] < totalHappiness[minCity] + happinessAtCities[it->first] || (totalHappiness[it->first] == totalHappiness[minCity] + happinessAtCities[it->first] && cityNum[it->first] > cityNum[minCity] + 1)) {
						totalHappiness[it->first] = totalHappiness[minCity] + happinessAtCities[it->first];
						path[it->first] = minCity;
						cityNum[it->first] = cityNum[minCity] + 1;
					}
				}
			}
		}
	}
}
void PrintPath(string city, string startCity)
{
	if(path.count(city)) {
		PrintPath(path[city], startCity);
	}
	if(city != startCity) printf("->");
	printf("%s", city.c_str());
}

int main()
{
	int N, K, happiness, cost;
	char startCityName[5], cityName[5], cityName2[5];
	scanf("%d %d %s", &N, &K, startCityName);
	for(int i = 0; i < N-1; i++) {
		scanf("%s %d", cityName, &happiness);
		happinessAtCities[cityName] = happiness;
		totalCost[cityName] = INF;
	}
	for(int i = 0; i < K; i++) {
		scanf("%s %s %d", cityName, cityName2, &cost);
		costBetweenCities[cityName][cityName2] = costBetweenCities[cityName2][cityName] = cost;
	}
	Dijkstra(startCityName);
	printf("%d %d %d %d\n", pathNum["ROM"], totalCost["ROM"], totalHappiness["ROM"], totalHappiness["ROM"]/cityNum["ROM"]);
	PrintPath("ROM", startCityName);
	return 0;
 } 
