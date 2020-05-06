#include <iostream>
using namespace std;

string LookAndSay(string number)
{
	string result;
	number += ";";
	char pre = number[0];
	int count = 1;
	for(int i = 1; i < number.length(); i++, count++){
		if(number[i] != pre){
			result += pre + to_string(count);
			pre = number[i];
			count = 0;
		}
	}
	return result;
}

int main()
{
	int D, N;
	scanf("%d %d", &D, &N);
	string number = to_string(D);
	for(int i = 1; i < N; i++){
		number = LookAndSay(number);
	}
	cout << number;
	return 0;
 } 
