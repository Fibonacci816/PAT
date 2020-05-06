#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct NodeS{
    char name[5];
    vector<int> courses;
}StudentNode;
StudentNode students[40000];
int FindStudentIndex(int n, char * name)
{
    for(int i = 0; i < n; i++){
        if(strcmp(name, students[i].name) == 0){
            return i;
        }
    }
    return -1;
}
int main()
{
    int N, K;
    int i, Ni;
    int studentIndex, studentNum = 0;
    char name[5];
    scanf("%d %d", &N, &K);
    for(int k = 0; k < K; k++){
        scanf("%d %d", &i, &Ni);
        for(int ni = 0; ni < Ni; ni++){
            scanf("%s", name);
            studentIndex = FindStudentIndex(studentNum, name);
            if(studentIndex == -1){
                strcpy(students[studentNum].name, name);
                students[studentNum++].courses.push_back(i);
            } else {
                students[studentIndex].courses.push_back(i);
            }
        }
    }
    for(int n = 0; n < N; n++){
        scanf("%s", name);
        printf("%s ", name);
        studentIndex = FindStudentIndex(studentNum, name);
        if(students[studentIndex].courses.size() == 0){
            printf("0");
            continue;
        }
        printf("%d ", students[studentIndex].courses.size());
        sort(students[studentIndex].courses.begin(), students[studentIndex].courses.end());
        for(int i = 0; i < students[studentIndex].courses.size(); i++){
            if(i == students[studentIndex].courses.size()-1){
                printf("%d\n", students[studentIndex].courses[i]);
            } else {
                printf("%d ", students[studentIndex].courses[i]);
            }
        }
    }
}
