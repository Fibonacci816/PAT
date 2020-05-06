#include <stdio.h>
int addresses[100000];
int main()
{
    int startAddress1, startAddress2;
    int N;
    int nodeAddress, nextAddress, commonStartAddress = -1;
    char character;
    scanf("%d %d %d", &startAddress1, &startAddress2, &N);
    for(int i = 0; i < N; i++){
        scanf("%d %c %d", &nodeAddress, &character, &nextAddress);
        addresses[nodeAddress]++;
        addresses[nextAddress]++;
    }
    for(int i = 0; i < 100000; i++){
        if(addresses[i] == 3){
            commonStartAddress = i;
        }
    }
    if(commonStartAddress == -1){
        printf("-1");
    } else {
        printf("%05d", commonStartAddress);
    }
    return 0;
}
