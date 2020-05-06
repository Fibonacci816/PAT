#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct NodeS{
    long long registration_number;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
} Node;
Node nodes[30000];
bool cmp(Node a, Node b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.registration_number < b.registration_number;
}
int main()
{
    int N, K;
    int totalNum = 0;
    long long registration_number;
    int score;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &K);
        for(int j = 0; j < K; j++){
            scanf("%lld %d", &registration_number, &score);
            nodes[totalNum].registration_number = registration_number;
            nodes[totalNum].score = score;
            nodes[totalNum].location_number = i + 1;
            totalNum++;
        }
        sort(nodes + totalNum - K, nodes + totalNum, cmp);
        for(int j = totalNum - K; j < totalNum; j++){
            if(j == totalNum - K){
                nodes[j].local_rank = 1;
            } else {
                if(nodes[j].score == nodes[j-1].score){
                    nodes[j].local_rank = nodes[j-1].local_rank;
                } else {
                    nodes[j].local_rank = j - totalNum + K + 1;
                }
            }
        }
    }
    sort(nodes, nodes + totalNum, cmp);
    for(int i = 0; i < totalNum; i++){
        if(i == 0){
            nodes[i].final_rank = 1;
        } else {
            if(nodes[i].score == nodes[i-1].score){
                nodes[i].final_rank = nodes[i-1].final_rank;
            } else {
                nodes[i].final_rank = i + 1;
            }
        }
    }
    printf("%d\n", totalNum);
    for(int i = 0; i < totalNum; i++){
        printf("%013lld %d %d %d\n", nodes[i].registration_number, nodes[i].final_rank, nodes[i].location_number, nodes[i].local_rank);
    }
    return 0;
}
