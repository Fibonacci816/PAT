#include <iostream>
#include <cmath>
using namespace std;

int MSize, N, M, numbers[11000];
bool IsPrime(int n)
{
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return false;
	}
	return true;
}
int FindMinPrime(int n)
{
	while(!IsPrime(n)) n++;
	return n;
}
bool Insert(int number)
{
	for(int i = 0; i < MSize; i++){  //ƽ��̽�ⷨ��������ݽṹ�̲���d��ȡ ��i^2��i <= MSize/2��������ĿҪ��positive increments only������i < MSize�� 
		int index = (number + i * i) % MSize;
		if(numbers[index] == 0){
			numbers[index] = number;
			return true;
		}
	}
	return false;
}
int Search(int number)
{
	int searchTime = 0;
	for(int i = 0; i <= MSize; i++){  //ʵ��û�б�Ҫ�����һ�β��ң����Ƕ���û�ҵ�������µıȽϴ�������Ŀ�ǰ���+1���е� 
		int index = (number + i * i) % MSize;
		searchTime++;
		if(numbers[index] == number || numbers[index] == 0)
			break;
	}
	return searchTime;
}

int main()
{
	int number;
	scanf("%d %d %d", &MSize, &N, &M);
	MSize = FindMinPrime(MSize);
	for(int i = 0; i < N; i++){
		scanf("%d", &number);
		if(!Insert(number))
			printf("%d cannot be inserted.\n", number);
	}
	double searchTime = 0;
	for(int i = 0; i < M; i++){
		scanf("%d", &number);
		searchTime += Search(number);
	}
	printf("%.1lf", searchTime/M);
	return 0;
 } 
