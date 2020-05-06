#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str, sign, value, result; //sign为正负号，value为正负号与E之间的字符串 
	int pointIndex, eIndex, exp; // pointIndex为小数点的位置，eIndex为E的位置，exp为指数 
	cin >> str;
	eIndex = str.find('E'); //找到E的位置作为分割点，将字符串分割为两部分 
	exp = stoi(str.substr(eIndex+1));
	value = str.substr(0, eIndex);
	sign = value[0];
	value = value.substr(1); //正负号单独保存方便后续处理 
	pointIndex = value.find('.'); //找到小数点的位置作为分割点，将无符号的value进行分割 
	string frontPoint = value.substr(0, pointIndex);
	string afterPoint = value.substr(pointIndex+1);
	if(exp > 0){
		result = frontPoint;
		if(exp >= afterPoint.length()){
			result += afterPoint;
			for(int i = afterPoint.length(); i < exp; i++)
				result += "0";
		} else {
			result += afterPoint.substr(0, exp);
			result += ".";
			result += afterPoint.substr(exp);
		}
	} else if(exp < 0){
		result = "0.";
		for(int i = 1; i < -exp; i++)
			result += "0";
		result += frontPoint + afterPoint;
	} else {
		result = value;
	}
	if(sign == "-")
	    result = sign + result;
	cout << result;
	return 0;
}
