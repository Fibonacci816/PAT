#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
bool cmp(string str1, string str2){
    return str1+str2 < str2+str1;
}
int main()
{
    int N;
    scanf("%d", &N);
    string numberSegments[N];
    for(int i = 0; i < N; i++){
        cin >> numberSegments[i];
    }
    sort(numberSegments, numberSegments+N, cmp);
    int index1 = 0, index2 = 0;
    int flag = 1;
    //从第一个不为0的字符开始输出
    for(index1 = 0; index1 < N; index1++){
        for(index2 = 0; numberSegments[index1][index2] != '\0'; index2++){
            if(numberSegments[index1][index2] != '0'){
                flag = 0;
            }
            if(flag == 0){
                printf("%c", numberSegments[index1][index2]);
            }
        }
    }
    if(flag){
        printf("%d", 0);
    }
    return 0;
}


