#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

map<int, vector<string> > courses;

int main()
{
    int N, K;
    char studentName[5];
    int courseCount, courseNumber;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%s %d", studentName, &courseCount);
        for(int c = 0; c < courseCount; c++){
            scanf("%d", &courseNumber);
            courses[courseNumber].push_back(studentName);
        }
    }
    for(int i = 1; i <= K; i++){
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end());
        for(int j = 0; j < courses[i].size(); j++){
            cout << courses[i][j] << "\n";
        }
    }
    return 0;
}
