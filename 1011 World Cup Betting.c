#include <stdio.h>
#define GAME_NUM 3
int main()
{
    char winTeams[GAME_NUM]; //记录每局游戏获胜概率最大的队伍
    double odd;
    double maxOdd; //每局游戏的最大获胜概率
    double profit = 1;
    char teams[3] = {'W', 'T', 'L'};
    for(int i = 0; i < GAME_NUM; i++){
        maxOdd = 0;
        for(int j = 0; j < 3; j++){
            scanf("%lf", &odd);
            if(odd > maxOdd){
                maxOdd = odd;
                winTeams[i] = teams[j];
            }
        }
        profit *= maxOdd;
    }
    profit = (profit * 0.65 - 1) * 2;
    for(int i = 0; i < GAME_NUM; i++){
        printf("%c ", winTeams[i]);
    }
    printf("%.2f", profit);
    return 0;
}
