#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#define DIGIT_NUM 4
using namespace std;

vector<int> non_increasing(DIGIT_NUM), non_decreasing(DIGIT_NUM);

int ToNumber(vector<int> v)
{
	int number = 0;
	for(int i = 0; i < DIGIT_NUM; i++){
		//number += v[i] * pow(10, DIGIT_NUM-i-1);
		number = number * 10 + v[i];
	}
	return number;
}

void ToNon_increasing(int number)
{
	for(int i = 0; i < DIGIT_NUM; i++){
		non_increasing[DIGIT_NUM-i-1] = number % 10;
		number /= 10;
	}
	sort(non_increasing.rbegin(), non_increasing.rend());
}

void ToNon_decreasing(int number)
{
	for(int i = 0; i < DIGIT_NUM; i++){
		non_decreasing[DIGIT_NUM-i-1] = number % 10;
		number /= 10;
	}
	sort(non_decreasing.begin(), non_decreasing.end());
}

int main()
{
	int number, bigger, smaller;
	scanf("%d", &number);
	while(1){
		ToNon_increasing(number);
		bigger = ToNumber(non_increasing);
		ToNon_decreasing(number);
		smaller = ToNumber(non_decreasing);
		number = bigger - smaller;
		printf("%04d - %04d = %04d\n", bigger, smaller, number);
		if(number==0 || number==6174){
			break;
		}
	}
	return 0;
}
