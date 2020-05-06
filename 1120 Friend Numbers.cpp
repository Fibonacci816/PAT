#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int Count(int number)
{
	int count = 0;
	while(number){
		count += number % 10;
		number /= 10;
	}
	return count;
}

int main()
{
	int N, number;
	scanf("%d", &N);
	map<int, int> ans;
	for(int i = 0; i < N; i++){
		scanf("%d", &number);
		ans[Count(number)] = 1;
	}
	printf("%d\n", ans.size());
	map<int, int>::iterator it = ans.begin();
	while(it != ans.end()){
		printf("%d", it->first);
		if(++it != ans.end())
			printf(" ");
	}
	return 0;
}
