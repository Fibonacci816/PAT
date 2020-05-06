#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
	char name[11];
	char id[11];
	int grade;
}; 

bool cmp(Student student1, Student student2)
{
	return student1.grade > student2.grade;
}

int main(){
	int N;
	scanf("%d", &N);
	Student students[N];
	for(int i = 0; i < N; i++){
		scanf("%s %s %d", students[i].name, students[i].id, &students[i].grade);
	}
	sort(students, students+N, cmp);
	int low, high, flag = 0;
	scanf("%d %d", &low, &high);
	for(int i = 0; i < N; i++){
		if(students[i].grade >= low && students[i].grade <= high){
			printf("%s %s\n", students[i].name, students[i].id);
			flag = 1;
		}
	}
	if(flag == 0){
		printf("NONE");
	}
	return 0;
}
