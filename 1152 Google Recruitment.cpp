#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number)
{
	if(number < 2) return false;
	for(int i = 2; i <= sqrt(number); i++){
		if(number % i == 0) return false;
	} 
	return true;
}

int main()
{
	int L, K;
	string number;
	cin >> L >> K >> number;
	for(int i = 0; i <= L-K; i++){
		if(isPrime(stoi(number.substr(i, K)))){
			cout << number.substr(i, K);
			return 0;
		}
	}
	cout << 404;
	return 0;
 } 
