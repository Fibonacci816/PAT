#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d\n", &N);
	string number, cut1, cut2;
	for(int i = 0; i < N; i++){
		cin >> number;
		cut1 = number.substr(0, number.length()/2);
		cut2 = number.substr(number.length()/2);
		if(stol(cut1)*stol(cut2) != 0 && stol(number) % (stol(cut1)*stol(cut2)) == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
 } 
