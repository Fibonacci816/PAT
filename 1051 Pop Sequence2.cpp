#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    int nextNumber, popNumber, flag;
    stack<int> Stack;
    for(int i = 0; i < K; i++){
        while (!Stack.empty()){
            Stack.pop();
        }
        flag = 1;
        nextNumber = 1;
        for(int j = 0; j < N; j++){
            scanf("%d", &popNumber);
            if(flag == 0)
                continue;
            while(Stack.empty() || Stack.top()!=popNumber){
                Stack.push(nextNumber++);
                if(Stack.size() > M){
                    flag = 0;
                    break;
                }
            }
            if(Stack.top() == popNumber)
                Stack.pop();
            else
                flag = 0;
        }
        if(flag){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
