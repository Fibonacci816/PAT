#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, number, count = 0;
	scanf("%d", &N);
	map<int, int> numbers;
	for(int i = 0; i < N; i++){
		scanf("%d", &number);
		if(number > 0) count++;
		numbers[number] = 1;
	}
	for(int i = 1; i <= count+1; i++){
		if(numbers.count(i) == 0){
			printf("%d", i);
			break;
		}
	}
	return 0;
 } 
