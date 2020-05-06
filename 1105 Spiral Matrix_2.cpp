#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int m, n= sqrt(N);
	while(N % n) n--;
	m = N / n;
	int matrix[m][n];
	int numbers[N];
	for(int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	}
	sort(numbers, numbers+N);
	for(int start = 0, maxRow = m-1, maxCol = n-1; maxRow >= start && maxCol >= start; maxRow--, maxCol--, start++) {
		int i = start, j = start;
		for(; j <= maxCol && N > 0; j++)
			matrix[start][j] = numbers[--N];
		for(i = start+1; i <= maxRow && N > 0; i++)
			matrix[i][maxCol] = numbers[--N];
		for(j = maxCol-1; j >= start && N > 0; j--)
			matrix[maxRow][j] = numbers[--N];
		for(i = maxRow-1; i > start && N > 0; i--)
			matrix[i][start] = numbers[--N];
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++){
			printf("%d", matrix[i][j]);
			if(j == n-1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
