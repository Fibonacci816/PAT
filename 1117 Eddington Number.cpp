#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, Eddington = 0;
	scanf("%d", &N);
	int distances[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &distances[i]);
	}
	sort(distances, distances+N, greater<int>());
	while(Eddington<N && distances[Eddington]>Eddington+1) Eddington++;
	printf("%d", Eddington);
	return 0;
}
