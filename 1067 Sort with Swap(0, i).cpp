#include <stdio.h>
#include <map>
using namespace std;

int main()
{
    int N, value, disorderedNum = 0, minSwapNum = 0;
    map<int, int> Map;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &value);
        Map[value] = i;
        if(value != i){
            disorderedNum++;
        }
	}
    value = 1;
	int index0;
    while(disorderedNum > 0){
        if(Map[0] == 0){
        	while(value < N){
        		if(Map[value] != value){
        			Map[0] = Map[value];
        			Map[value] = 0;
        			minSwapNum++;
        			disorderedNum++;
        			break;
				}
				value++;
			}
		}
		while(Map[0] != 0){
			index0 = Map[0];
			Map[0] = Map[index0];
            Map[index0] = index0;
			minSwapNum++;
			disorderedNum--;
		}
        disorderedNum--;
    }
    printf("%d", minSwapNum);
    return 0;
}
