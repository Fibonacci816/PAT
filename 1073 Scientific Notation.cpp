#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str, sign, value, result; //signΪ�����ţ�valueΪ��������E֮����ַ��� 
	int pointIndex, eIndex, exp; // pointIndexΪС�����λ�ã�eIndexΪE��λ�ã�expΪָ�� 
	cin >> str;
	eIndex = str.find('E'); //�ҵ�E��λ����Ϊ�ָ�㣬���ַ����ָ�Ϊ������ 
	exp = stoi(str.substr(eIndex+1));
	value = str.substr(0, eIndex);
	sign = value[0];
	value = value.substr(1); //�����ŵ������淽��������� 
	pointIndex = value.find('.'); //�ҵ�С�����λ����Ϊ�ָ�㣬���޷��ŵ�value���зָ� 
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
