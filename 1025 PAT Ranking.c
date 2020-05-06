#include <stdio.h>
typedef struct NodeS{
    long long registration_number;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
} Node;
Node nodes[30000];
int main()
{
    int N, K;
    int totalNum = 0;
    int local_rank;
    long long registration_number;
    int score;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &K);
        for(int j = 0; j < K; j++){
            scanf("%lld %d", &registration_number, &score);
            int k;
            //Ѱ�Һ��ʵĲ���λ���԰�score����
            for(k = totalNum; k > 0; k--){
                if(score <= nodes[k-1].score){
                    break;
                }
                nodes[k] = nodes[k-1];
            }
            nodes[k].registration_number = registration_number;
            nodes[k].score = score;
            nodes[k].location_number = i + 1;
            totalNum++;
            //��ǰԪ�ص�local_rank��final_rank
            if(k == 0){
                nodes[k].local_rank = 1;
                nodes[k].final_rank = 1;
            } else {
                //�����ǰԪ�ص�local_rank
                local_rank = 1;
                for(int l = k - 1; l >= 0; l--){
                    if(nodes[l].location_number == nodes[k].location_number){
                        if(nodes[l].score == nodes[k].score){
                            local_rank = nodes[l].local_rank;
                            break;
                        }
                        local_rank++;
                    }
                }
                nodes[k].local_rank = local_rank;
                if(nodes[k].score == nodes[k-1].score){
                    nodes[k].final_rank = nodes[k-1].final_rank;
                } else {
                    nodes[k].final_rank = k + 1;
                }
            }
            //���²���λ��֮���Ԫ�ص�local_rank��final_rank
            for(int l = k + 1; l < totalNum; l++){
                //ͬһlocation��Ԫ�زŸ�����local_rank
                if(nodes[l].location_number == nodes[k].location_number){
                    nodes[l].local_rank++;
                }
                nodes[l].final_rank++;
            }
        }
    }
    printf("%d\n", totalNum);
    for(int i = 0; i < totalNum; i++){
        printf("%lld %d %d %d\n", nodes[i].registration_number, nodes[i].final_rank, nodes[i].location_number, nodes[i].local_rank);
    }
    return 0;
}
