#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
map<string, vector<int> > students;
int main()
{
    int N, K;
    int i, Ni;
    char name[5];
    scanf("%d %d", &N, &K);
    for(int k = 0; k < K; k++){
        scanf("%d %d", &i, &Ni);
        for(int ni = 0; ni < Ni; ni++){
            scanf("%s", name);
            students[name].push_back(i);
        }
    }
    for(int n = 0; n < N; n++){
        scanf("%s", name);
        printf("%s ", name);
        if(students[name].size() == 0){
            printf("0\n");
            continue;
        }
        printf("%d ", students[name].size());
        sort(students[name].begin(), students[name].end());
        for(int i = 0; i < students[name].size(); i++){
            if(i == students[name].size()-1){
                printf("%d\n", students[name][i]);
            } else {
                printf("%d ", students[name][i]);
            }
        }
    }
}
