#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	map<int, int> colorMap;
	int M, N;
	int color, dominantColor, maxColorNum = 0;
	scanf("%d %d", &M, &N);
	for(int n = 0;  n < N; n++){
		for(int m = 0; m < M; m++){
			scanf("%d", &color);
			colorMap[color]++;
			if(colorMap[color] > maxColorNum){
				maxColorNum = colorMap[color];
				dominantColor = color;
			}
		}
	}
	printf("%d", dominantColor);
	return 0;
 } 
