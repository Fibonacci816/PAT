#include <iostream>
#include <algorithm>
using namespace std;

string AddRev(string number)
{
	string revNumber = number;
	reverse(revNumber.begin(), revNumber.end());
	string result;
	int digit, offset = 0, len = number.length();
	for(int i = 0; i < len; i++){
		digit = (number[i] - '0') + (revNumber[i] - '0') + offset;
		offset = digit / 10;
		digit %= 10;
		result =  to_string(digit) + result;
	}
	if(offset)
		result =  to_string(offset) + result;
	cout << number << " + " << revNumber << " = " << result << endl;
	return result;
}
bool IsPalindromic(string number)
{
	int len = number.length();
	for(int i = 0; i < len/2; i++){
		if(number[i] != number[len-1-i])
			return false;
	}
	return true;
}

int main()
{
	string number;
	cin >> number;
	for(int i = 0; i < 10; i++){
        if(IsPalindromic(number))
			break;
		number = AddRev(number);
	}
	if(IsPalindromic(number))
		cout << number << " is a palindromic number.";
	else
		cout << "Not found in 10 iterations.";
	return 0;
 } 
