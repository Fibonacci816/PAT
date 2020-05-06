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
			break;  //������ʣ��Ԫ�ظ���С�ڵ�ǰ���Ԫ�ظ���ʱ����start�������һ��Ԫ�ص�λ��ʱ�˳� 
		m = integers[i];
		while(start < N){
			M = integers[start];
			if(M > (long long)m * p){  //m*p�����������˽�����һ��������תΪlong long���� 
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
