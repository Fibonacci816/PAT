#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int K, N;
	scanf("%d", &K);
	int sequence[1001];
	for(int i = 0; i < K; i++){
		scanf("%d", &N);
		bool judge = true;
		for(int j = 1; j <= N; j++){
			scanf("%d", &sequence[j]);
			for (int t = 1; t < j; t++) {
                if (sequence[j] == sequence[t] || abs(sequence[j]-sequence[t]) == abs(j-t)) {
                    judge = false;
                    break;
                }
            }
		}
		printf("%s\n", judge ? "YES" : "NO");
	}
	return 0;
}
