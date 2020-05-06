#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int numbers[N];
	int n = sqrt(N);
	while(N % n)
		n--;
	int m = N / n;
	int spiralMatrix[m][n];
	for(int i = 0; i < N; i++){
		scanf("%d", &numbers[i]);
	} 
	sort(numbers, numbers+N, greater<int>());
	int k = 0, i, j, temp_m = m, temp_n = n;
	while(k < N){
		i = m - temp_m;
		j = n - temp_n;
		for(; j < temp_n-1 && k < N; j++){
			spiralMatrix[i][j] = numbers[k++];
		}	
		for(; i < temp_m-1 && k < N; i++){
			spiralMatrix[i][j] = numbers[k++];
		}	
		for(; j > n-temp_n && k < N; j--){
			spiralMatrix[i][j] = numbers[k++];
		}
		for(; i > m-temp_m && k < N; i--){
			spiralMatrix[i][j] = numbers[k++];
		}
		temp_m--;
		temp_n--;
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%d", spiralMatrix[i][j]);
			if(j == n-1){
				printf("\n");
			} else {
				printf(" ");
			}
		}
	} 
	return 0;
}
