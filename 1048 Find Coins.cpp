#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, coin, coin1, coin2 = 0;
    int head, rear, mid;
    vector<int> coins;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &coin);
        coins.push_back(coin);
    }
    sort(coins.begin(), coins.end());
    for(int i = 0; i < N; i++){
        coin1 = coins[i];
        if(coin1 > M/2){
            break;
        }
        if(coin1+coins[N-1] == M){
            coin2 = coins[N-1];
            break;
        }
        if(coin1+coins[N-1] < M){
            continue;
        }
        head = i + 1;
        rear = N - 2;
        while(head <= rear){
            mid = (head + rear)/2;
            if(coin1+coins[mid] == M){
                coin2 = coins[mid];
                break;
            } else if(coin1+coins[mid] < M){
                head = mid + 1;
            } else {
                rear = mid -1;
            }
        }
        if(coin2){
            break;
        }
    }
    if(coin2){
        printf("%d %d", coin1, coin2);
    } else {
        printf("No Solution");
    }
    return 0;
}
