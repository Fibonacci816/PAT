#include <stdio.h>
#include <map>

using namespace std;

int numbers[100000];
map<int, int> numberMap;
int IsUnique(int number)
{
    if(numberMap[number] > 1){
        return 0;
    }
    return 1;
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &numbers[i]);
        numberMap[numbers[i]] += 1; //如果map不包含key，使用下标有一个危险的副作用，会在map中插入一个key的元素，value取默认值
    }
    int flag = 1;
    for(int i = 0; i < N; i++){
        if(IsUnique(numbers[i])){
            printf("%d", numbers[i]);
            flag = 0;
            break;
        }
    }
    if(flag){
        printf("None");
    }
}
