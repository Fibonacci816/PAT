#include <stdio.h>
typedef struct NodeS{
    char character;
    int nextAddress;
} Node;
Node nodes[100000];
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
        nodes[nodeAddress].character = character;
        nodes[nodeAddress].nextAddress = nextAddress;
    }
    nodeAddress = startAddress1;
    while(nodeAddress != -1){
        addresses[nodeAddress]++;
        nodeAddress = nodes[nodeAddress].nextAddress;
    }
    nodeAddress = startAddress2;
    while(nodeAddress != -1){
        addresses[nodeAddress]++;
        if(addresses[nodeAddress] == 2){
            commonStartAddress = nodeAddress;
            break;
        }
        nodeAddress = nodes[nodeAddress].nextAddress;
    }
    if(commonStartAddress == -1){
        printf("-1");
    } else {
        printf("%05d", commonStartAddress);
    }
    return 0;
}
