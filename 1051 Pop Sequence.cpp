#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    int pushNumber, popNumber, flag;
    stack<int> Stack;
    for(int i = 0; i < K; i++){
        while (!Stack.empty()){
            Stack.pop();
        }
        flag = 1;
        pushNumber = 1;
        for(int j = 0; j < N; j++){
            scanf("%d", &popNumber);
            if(flag == 0)
                continue;
            if(pushNumber > popNumber){
                if(Stack.top() == popNumber){
                    Stack.pop();
                } else {
                    flag = 0;
                }
            } else {
                while(pushNumber <= popNumber){
                    Stack.push(pushNumber++);
                    if(Stack.size() > M){
                        flag = 0;
                        break;
                    }
                }
                Stack.pop();
            }
        }
        if(flag){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
