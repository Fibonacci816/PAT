#include <iostream>
#include <math.h>
using namespace std;

bool IsPrime(int number)
{
	if(number < 2){
		return false;
	}
	bool flag = true;
	for(int i = 2; i <= sqrt(number); i++){
		if(number % i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}
int ChangeToPrime(int number)
{
	while(!IsPrime(number)){
		number++;
	}
	return number;
}

int main()
{
	int MSize, N;
	scanf("%d %d", &MSize, &N);
	MSize = ChangeToPrime(MSize);
	int key, Hkey, insertable[MSize];
	fill(insertable, insertable+MSize, 0);
	for(int i = 0; i < N; i++){
		scanf("%d", &key);
		Hkey = key % MSize;
		if(i == 0){
			printf("%d", Hkey);
			insertable[Hkey] = 1;
		} else if(insertable[Hkey] == 0){
			printf(" %d", Hkey);
			insertable[Hkey] = 1;
		} else {
			//进行平方探测（仅向前探测） 
			int index = -1;
			for(int q = 1; q <= MSize/2; q++){
				if(insertable[(Hkey+q*q)%MSize] == 0){
					index = (Hkey+q*q)%MSize;
					break;
				}
			}
			if(index != -1){
				printf(" %d", index);
				insertable[index] = 1;
			} else {
				printf(" -");
			}
		}
	}
	return 0;
}
