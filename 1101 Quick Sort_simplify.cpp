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
			//因为a[i]前面的元素都小于它，所以如果它在有序的位置上，后面所有元素一定都大于它，否则后面一定有元素小于它 
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
