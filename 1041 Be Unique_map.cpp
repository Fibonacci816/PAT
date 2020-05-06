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
        numberMap[numbers[i]] += 1; //���map������key��ʹ���±���һ��Σ�յĸ����ã�����map�в���һ��key��Ԫ�أ�valueȡĬ��ֵ
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
