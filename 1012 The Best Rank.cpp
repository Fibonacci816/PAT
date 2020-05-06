#include <iostream>
#include <algorithm>
using namespace std;

typedef struct StudentScoreS {
    int StudentId;
    int Score;
} StudentScore;

bool cmp(StudentScore s1, StudentScore s2)
{
    return s1.Score > s2.Score;
}
int findRankSort(StudentScore studentsScore[], int n, int StudentId)
{
    for(int i = 0; i < n; i++) {
        if(studentsScore[i].StudentId == StudentId){
            for(int j = i-1; j>=0; j--){
                if(studentsScore[i].Score == studentsScore[j].Score)
                    i = j;
                else
                    break;
            }
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int N, M;
    char bestRank;
    int studentId, cscore, mscore, escore, rankSort, bestRankSort;
    scanf("%d %d", &N, &M);
    StudentScore studentsScoreC[N];
    StudentScore studentsScoreM[N];
    StudentScore studentsScoreE[N];
    StudentScore studentsScoreA[N];
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &studentId, &cscore, &mscore, &escore);
        studentsScoreC[i].StudentId = studentsScoreM[i].StudentId = studentsScoreE[i].StudentId = studentsScoreA[i].StudentId = studentId;
        studentsScoreC[i].Score = cscore;
        studentsScoreM[i].Score = mscore;
        studentsScoreE[i].Score = escore;
        studentsScoreA[i].Score = (cscore + mscore + escore) / 3;
    }
    sort(studentsScoreA, studentsScoreA+N, cmp);
    sort(studentsScoreC, studentsScoreC+N, cmp);
    sort(studentsScoreM, studentsScoreM+N, cmp);
    sort(studentsScoreE, studentsScoreE+N, cmp);
    for(int i = 0; i < M; i++) {
        scanf("%d", &studentId);
        bestRank = 'A';
        bestRankSort = findRankSort(studentsScoreA, N, studentId);
        rankSort = findRankSort(studentsScoreC, N, studentId);
        if(rankSort < bestRankSort) {
            bestRankSort = rankSort;
            bestRank = 'C';
        }
        rankSort = findRankSort(studentsScoreM, N, studentId);
        if(rankSort < bestRankSort) {
            bestRankSort = rankSort;
            bestRank = 'M';
        }
        rankSort = findRankSort(studentsScoreE, N, studentId);
        if(rankSort < bestRankSort) {
            bestRankSort = rankSort;
            bestRank = 'E';
        }
        if(bestRankSort == -1) {
            printf("%s", "N/A");
        } else {
            printf("%d %c", bestRankSort, bestRank);
        }
        if(i != M - 1){
            printf("\n");
        }
    }
    return 0;
}
