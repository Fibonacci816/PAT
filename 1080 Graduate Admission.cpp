#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Student{
	int id;
	int gradeE, gradeI, finalGrade;
	int choices[5];
};
Student students[40000];
int schoolQuota[100];
vector<int> schoolAdmitted[100];

bool cmp(Student student1, Student student2)
{
	if(student1.finalGrade != student2.finalGrade){
		return student1.finalGrade > student2.finalGrade;
	} else {
		return student1.gradeE > student2.gradeE;
	}
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; i++){
		scanf("%d", &schoolQuota[i]);
	}
	for(int i = 0; i < N; i++){
		students[i].id = i;
		scanf("%d %d", &students[i].gradeE, &students[i].gradeI);
		students[i].finalGrade = students[i].gradeE + students[i].gradeI;
		for(int j = 0; j < K; j++){
			scanf("%d", &students[i].choices[j]);
		}
	}
	sort(students, students+N, cmp);
	map<int, int> idMap;
	for(int i = 0; i < N; i++){
		idMap[students[i].id] = i;  //保存学生id与其所在列表位置 
		for(int j = 0; j < K; j++){
			int choice = students[i].choices[j];
			if(schoolAdmitted[choice].size() < schoolQuota[choice]){
				schoolAdmitted[choice].push_back(students[i].id);
				break;
			} else {
				int lastAdmitted = schoolAdmitted[choice].back();  //上一个被学校录取的学生id 
				int lastAdmittedIndex = idMap[lastAdmitted];
				if(students[i].finalGrade == students[lastAdmittedIndex].finalGrade && students[i].gradeE == students[lastAdmittedIndex].gradeE){
					schoolAdmitted[choice].push_back(students[i].id);
					break;
				}
			}
		}
	}
	for(int i = 0; i < M; i++){
		sort(schoolAdmitted[i].begin(), schoolAdmitted[i].end());
		for(int j = 0; j < schoolAdmitted[i].size(); j++){
			printf("%d", schoolAdmitted[i][j]);
			if(j != schoolAdmitted[i].size()-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
