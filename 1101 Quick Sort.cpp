#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
	int N, max = 0, min = INF;
	scanf("%d", &N);
    int a[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	unordered_map<int, int> temp;
	for(int i = 0; i < N; i++){
		if(a[i] > max){
			temp[a[i]] = 1;
			max = a[i];
		}
	}
	vector<int> ans;
	for(int i =  N-1; i >= 0; i--){
		if(a[i] < min){
			if(temp[a[i]] == 1){
                ans.push_back(a[i]);
            }
            min = a[i];
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		if(i != 0)
			printf(" ");
		printf("%d", ans[i]);
	}
	cout << endl;
	return 0;
 } 
