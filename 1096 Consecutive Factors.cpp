#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, temp;
	vector<int> v, vt;
	scanf("%d", &N);
	for(int i = 2; i <= sqrt(N); i++){
		temp = N;
		int j = i;
		vt.clear();
		while(temp % j == 0){
			vt.push_back(j);
			temp /= j++;
		}
		if(vt.size() > v.size()){
			v = vt;
		}
	}
	if(v.empty()){
	    printf("%d\n%d", 1, N);
    } else {
    	printf("%d\n", v.size());
		for(int i = 0; i < v.size(); i++){
			printf("%d", v[i]);
			if(i != v.size()-1)
				printf("*");
		}
	}
	return 0;
}
