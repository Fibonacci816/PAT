#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Student{
	int userId;
	map<int, int> scores;  //题目及其对应的分数 
	int totalScore; 
	int perfectNum;  //获得满分的题目数量 
	int flag;  //是否参与排名 
};
Student students[10001];
int points[6];

bool cmp(Student student1, Student student2)
{
	if(student1.flag != student2.flag){
		return student1.flag > student2.flag;
	} else if(student1.totalScore != student2.totalScore){
		return student1.totalScore > student2.totalScore;
	} else if(student1.perfectNum != student2.perfectNum) {
		return student1.perfectNum > student2.perfectNum;
	} else {
		return student1.userId < student2.userId;
	}
}

int main()
{
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	for(int i = 1; i <= K; i++){
		scanf("%d", &points[i]);
	}
	int userId, probId, score;
	for(int i = 1; i <= M; i++){
		scanf("%d %d %d", &userId, &probId, &score);
		students[userId].userId = userId;
		if(students[userId].scores.count(probId) == 0 || students[userId].scores[probId] < score){
			students[userId].scores[probId] = score;
		}
		if(score != -1){
			students[userId].flag = 1;
		}
	}
	for(int i = 1; i <= 10000; i++){
		if(students[i].flag == 1){
			int totalScore = 0, perfectNum = 0;
			for(map<int, int>::iterator it = students[i].scores.begin(); it != students[i].scores.end(); it++){
				if(it->second == -1)
					students[i].scores[it->first] = 0;
				else
					totalScore += it->second;
				if(it->second == points[it->first])
					perfectNum++;
			}
			students[i].totalScore = totalScore;
			students[i].perfectNum = perfectNum;
		}
	}
	sort(students+1, students+10001, cmp);
	int rank = 1;
	for(int i = 1; i <= 10000; i++){
		if(students[i].flag == 1){
			if(students[i].totalScore == students[i-1].totalScore){
				printf("%d ", rank);
			} else {
				printf("%d ", i);
				rank = i;
			}
			printf("%05d %d", students[i].userId, students[i].totalScore);
			for(int j = 1; j <= K; j++){
				if(students[i].scores.count(j) == 1){
					printf(" %d", students[i].scores[j]);
				} else {
					printf(" -");
				}
			}
			printf("\n");
		} else {
			break;
		}
	}
}
