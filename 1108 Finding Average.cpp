#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool IsNumber(string str)
{
	if(str[0] == '-')
		str = str.substr(1);
	int pointNum = 0;
	for(auto ch: str){
		if(!((ch>='0'&&ch<='9') || ch=='.'))
			return false;
		if(ch == '.')
			pointNum++;
		if(pointNum > 1)
			return false;
	}
	return true;
}
bool IsLegal(string str)
{
	if(IsNumber(str)){
		if(abs(stof(str))>1000)
			return false;
		int pointIndex = str.find('.');
		if(pointIndex!=string::npos && str.length()-pointIndex>3)  //判断小数点后是否超过两位 
			return false;
		else
			return true;
	}
	return false;
} 

int main()
{
	int N, legalNum = 0;
	scanf("%d\n", &N);
	string str;
	float total = 0;
	for(int i = 0; i < N; i++){
		cin >> str;
		if(IsLegal(str)){
			total += stof(str);
			legalNum++;
		} else {
			cout << "ERROR: " << str << " is not a legal number" << endl;
		}
	}
	if(legalNum == 0)
		cout << "The average of 0 numbers is Undefined";
	else if(legalNum == 1)
		printf("The average of 1 number is %.2f", total);
	else
		printf("The average of %d numbers is %.2f", legalNum, total/legalNum);
	return 0;
} 
