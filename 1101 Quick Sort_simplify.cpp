#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, max = 0;
	scanf("%d", &N);
    int a[N], b[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b+N);
	vector<int> ans;
	for(int i = 0; i < N; i++){
		if(a[i] > max){
			//��Ϊa[i]ǰ���Ԫ�ض�С����������������������λ���ϣ���������Ԫ��һ�������������������һ����Ԫ��С���� 
			if(a[i] == b[i])
				ans.push_back(a[i]);
			max = a[i];
		}
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		if(i != 0)
			printf(" ");
		printf("%d", ans[i]);
	}
	cout << endl;
	return 0;
 } 
