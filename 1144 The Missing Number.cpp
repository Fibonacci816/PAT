#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, number;
	scanf("%d", &N);
	set<int> numbers;
	for(int i = 0; i < N; i++){
		scanf("%d", &number);
		if(number > 0)
			numbers.insert(number);
	}
	if(numbers.empty()){
		printf("%d", 1);
	} else {
		number = 1; 
		for(auto it = numbers.begin(); it != numbers.end(); it++, number++){
			if(*it != number){
				printf("%d", number);
				break;
			}
		}
		if(number > numbers.size())
			printf("%d", number);
	}
	return 0;
 } 
