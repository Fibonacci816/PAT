#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string digit1[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string digit2[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> earthToMars1, earthToMars2;

bool IsEarthNumber(string number)
{
	if(number[0]>='0' && number[0]<='9')
		return true;
	return false;
}
int ToEarthNumber(string number)
{
	size_t pos = number.find(' ');
	if(pos != string::npos){
		return earthToMars2[number.substr(0, pos)] * 13 + earthToMars1[number.substr(pos+1)];
	} else {
		if(earthToMars1.count(number)){
			return earthToMars1[number];
		} else {
			return earthToMars2[number] * 13;
		}
	}
}
string ToMarsNumber(int number)
{
	if(number/13!=0 && number%13!=0){
		return digit2[number/13] + " " + digit1[number%13];
	} else if(number/13!=0) {
		return digit2[number/13];
	} else {
		return digit1[number];
	}
}

int main()
{
	for(int i = 0; i < 13; i++){
		earthToMars1[digit1[i]] = i;
		earthToMars2[digit2[i]] = i;
	}
	int N;
	string number;
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		getline(cin, number);
		if(IsEarthNumber(number)){
			cout << ToMarsNumber(stoi(number)) << endl;
		} else {
			cout << ToEarthNumber(number) << endl;
		} 
	}
	return 0;
} 
