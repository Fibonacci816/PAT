#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int numbers[N];
	for(int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	} 
	sort(numbers, numbers+N);
    int n = sqrt(N);
	while(N % n)
		n--;
	int m = N / n;
	int spiralMatrix[m][n];
	int k = N-1, minR = 0, maxR = m - 1, minC = 0, maxC = n - 1;
    while (k >= 0) {
        for(int nowC = minC, nowR = minR; nowC <= maxC; nowC++) {
            spiralMatrix[nowR][nowC] = numbers[k--];
        }
        ++minR;
        for(int nowR = minR, nowC = maxC; nowR <= maxR; nowR++) {
            spiralMatrix[nowR][nowC] = numbers[k--];
        }
        --maxC;
        if(k < 0) 
            break;
        for(int nowC = maxC, nowR = maxR; nowC >= minC; nowC--) {
            spiralMatrix[nowR][nowC] = numbers[k--];
        }
        --maxR;
        for(int nowR = maxR, nowC = minC; nowR >= minR; nowR--) {
            spiralMatrix[nowR][nowC] = numbers[k--];
        }
        ++minC;
    }
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d", spiralMatrix[i][j]);
			if(j == n-1) {
				printf("\n");
			} else {
				printf(" ");
			}
		}
	} 
	return 0;
}
