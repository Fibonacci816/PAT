#include <stdio.h>
#include <math.h> 
#include <vector>
using namespace std;

int main()
{
	int N, number, fn;
	vector<int> factor;
	vector<int> factorNum;
	scanf("%d", &N);
    if(N==1){
        printf("1=1");
        return 0;
    }
	number = N;
	for(int i = 2; i <= sqrt(number); i++){
		if(number % i == 0){
			if(factor.empty() || factor.back() != i){
				factor.push_back(i);
				fn = 0;
				do {
					fn++;
					number /= i;
				} while(number % i == 0);
				factorNum.push_back(fn);
			}
		} 
	}
	if(number != 1){
		factor.push_back(number);
		factorNum.push_back(1);
	} 
	printf("%d=", N);
	for(int i = 0; i < factor.size(); i++){
		printf("%d", factor[i]);
		if(factorNum[i] != 1){
			printf("^%d", factorNum[i]);
		}
		if(i != factor.size()-1){
			printf("*");
		}
	}
	return 0;
}
