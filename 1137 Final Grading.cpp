#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

struct Student{
	char name[21];
	int Gp = -1, Gmid = -1, Gfinal = -1, G = -1;
};
bool cmp(Student student1, Student student2)
{
	return student1.G != student2.G ? student1.G > student2.G : string(student1.name) < string(student2.name);
}

int main()
{
	int P, M, N;
	scanf("%d %d %d", &P, &M, &N);
	map<string, Student> students;
	char name[21];
	int grade;
	for(int i = 0; i < P; i++){
        scanf("%s %d", name, &grade);
        strcpy(students[name].name, name);
        students[name].Gp = grade;
	}
	for(int i = 0; i < M; i++){
        scanf("%s %d", name, &grade);
        strcpy(students[name].name, name);
        students[name].Gmid = grade;
	}
	for(int i = 0; i < N; i++){
        scanf("%s %d", name, &grade);
        strcpy(students[name].name, name);
        students[name].G = students[name].Gfinal = grade;
	}
	vector<Student> qualifiedStudents;
	for(auto it = students.begin(); it != students.end(); it++){
		if(it->second.Gmid > it->second.Gfinal)
			it->second.G = round(it->second.Gmid * 0.4 + it->second.Gfinal * 0.6);
		if(it->second.Gp >= 200 && it->second.G >= 60)
			qualifiedStudents.push_back(it->second);
	}
	sort(qualifiedStudents.begin(), qualifiedStudents.end(), cmp);
	for(int i = 0; i < qualifiedStudents.size(); i++)
		printf("%s %d %d %d %d\n", qualifiedStudents[i].name, qualifiedStudents[i].Gp, qualifiedStudents[i].Gmid, qualifiedStudents[i].Gfinal, qualifiedStudents[i].G);
	return 0;
 } 
