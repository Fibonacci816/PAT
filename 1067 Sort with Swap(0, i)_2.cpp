#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int val, indexs[N];
	for(int i = 0; i < N; i++) {
		scanf("%d", &val);
		indexs[val] = i;
	}
	int swapNum = 0, index = 1;
	while(true) {
		if(indexs[0] == 0) {
			for(; index < N && indexs[index] == index; index++);
			if(index == N) break;
			swap(indexs[0], indexs[index]);
		} else {
			swap(indexs[0], indexs[indexs[0]]);
		}
		swapNum++;
	}
	printf("%d", swapNum);
	return 0;
} 
