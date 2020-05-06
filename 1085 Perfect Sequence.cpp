#include <iostream>
#include <algorithm>
using namespace std;

int integers[100000];

int main()
{
	int N, p, m, M, maxNumber = 0;
	scanf("%d %d", &N, &p);
	for(int i = 0; i < N; i++){
		scanf("%d", &integers[i]);
	}
	sort(integers, integers+N);
	int start = 0;
	for(int i = 0; i < N; i++){
		if(N-i <= maxNumber || start == N)
			break;  //当数列剩余元素个数小于当前最大元素个数时或者start超过最后一个元素的位置时退出 
		m = integers[i];
		while(start < N){
			M = integers[start];
			if(M > (long long)m * p){  //m*p可能溢出，因此将至少一个操作数转为long long类型 
				break;
			}
			start++;
		}
        if(start - i > maxNumber)
			maxNumber = start - i;
	}
	printf("%d", maxNumber);
	return 0;
}
