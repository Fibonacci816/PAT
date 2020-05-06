#include <stdio.h>
typedef struct StudentInfoS {
    int StudentId;
    int C;
    int M;
    int E;
    double A;
} StudentInfo;
typedef struct StudentScoreS {
    int StudentId;
    double Score;
} StudentScore;
void sort(StudentScore studentsScore[], int n);
void swap(StudentScore * studentScore1, StudentScore * studentScore2);
int findRankSort(StudentScore studentsScore[], int n, int StudentId);
char ranks[4] = {'A', 'C', 'M', 'E'};
int main()
{
    int N, M;
    char bestRank;
    int rankSort;
    int bestRankSort;
    scanf("%d %d", &N, &M);
    StudentInfo studentsInfo[N];
    StudentScore studentsScoreC[N];
    StudentScore studentsScoreM[N];
    StudentScore studentsScoreE[N];
    StudentScore studentsScoreA[N];
    int studentsId[M];
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &studentsInfo[i].StudentId, &studentsInfo[i].C, &studentsInfo[i].M, &studentsInfo[i].E);
        studentsInfo[i].A = (studentsInfo[i].C + studentsInfo[i].M + studentsInfo[i].E) / 3.0;
        studentsScoreC[i].StudentId = studentsScoreM[i].StudentId = studentsScoreE[i].StudentId = studentsScoreA[i].StudentId = studentsInfo[i].StudentId;
        studentsScoreC[i].Score = studentsInfo[i].C;
        studentsScoreM[i].Score = studentsInfo[i].M;
        studentsScoreE[i].Score = studentsInfo[i].E;
        studentsScoreA[i].Score = studentsInfo[i].A;
    }
    sort(studentsScoreA, N);
    sort(studentsScoreC, N);
    sort(studentsScoreM, N);
    sort(studentsScoreE, N);
    for(int i = 0; i < M; i++) {
        scanf("%d", &studentsId[i]);
    }
    for(int i = 0; i < M; i++) {
        bestRank = 'A';
        bestRankSort = findRankSort(studentsScoreA, N, studentsId[i]);
        rankSort = findRankSort(studentsScoreC, N, studentsId[i]);
        if(rankSort < bestRankSort) {
            bestRankSort = rankSort;
            bestRank = 'C';
        }
        rankSort = findRankSort(studentsScoreM, N, studentsId[i]);
        if(rankSort < bestRankSort) {
            bestRankSort = rankSort;
            bestRank = 'M';
        }
        rankSort = findRankSort(studentsScoreE, N, studentsId[i]);
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
void sort(StudentScore studentsScore[], int n)
{
    int flag;
    for(int i = n - 1; i > 0; i--) {
        flag = 1;
        for(int j = 0; j < i; j++) {
            if(studentsScore[j].Score < studentsScore[j+1].Score){
                swap(&studentsScore[j], &studentsScore[j+1]);
                flag = 0;
            }
        }
        if(flag) {
            break;
        }
    }
}
void swap(StudentScore * studentScore1, StudentScore * studentScore2)
{
    StudentScore temp;
    temp = *studentScore1;
    *studentScore1 = *studentScore2;
    *studentScore2 = temp;
}
int findRankSort(StudentScore studentsScore[], int n, int StudentId)
{
    for(int i = 0; i < n; i++) {
        if(studentsScore[i].StudentId == StudentId){
            for(int j = i - 1; j > 0; j--){
                if(studentsScore[i].StudentId == studentsScore[j].StudentId) {
                    i = j;
                } else {
                    break;
                }
            }
            return i + 1;
        }
    }
    return -1;
}
