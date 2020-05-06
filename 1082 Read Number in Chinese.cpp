#include <iostream>
#include <algorithm>
using namespace std;

string digit[10] = {" ling", " yi", " er", " san", " si", " wu", " liu", " qi", " ba", " jiu"};
string unit[] = {"", " Shi", " Bai", " Qian"};
string bigUnit[] = {"", " Wan", " Yi"};

bool IsZero(string str)
{
	bool flag = true;
	for(int i = 0; i < str.length(); i++){
		if(str[i] != '0'){
			flag = false;
			break;
		}
	}
	return flag;
}
string ChineseQian(string str)  //����С��һ�������Ӧ�����Ķ����ַ��� 
{
	string result;
	int flag = 0;  //���ƶ����������ֻ���һ��ling 
	for(int i = 0; i < str.length(); i++){
		if(str[i] != '0'){
			result += digit[str[i]-'0'];
			result += unit[str.length()-i-1];
			flag = 0;
		} else if(flag == 0){
			result += digit[0];
			flag = 1;
		}
        if(IsZero(str.substr(i+1))){
            break;
        }
	}
	return result;
}

int main()
{
	string str;
	cin >> str;
	string sign;
	if(str[0] == '-'){
		sign = "Fu";
		str = str.substr(1);
	}
	string result;
	reverse(str.begin(), str.end());  //��ת�ַ���Ȼ����λһ����д��� 
	for(int i = 0; 4*i < str.length(); i++){
		string substr = str.substr(4*i, 4);
		reverse(substr.begin(), substr.end());
		result = ChineseQian(substr) + bigUnit[i] + result;
	}
	if(sign.empty()){  //����λΪ����ȥ����ͷ�Ŀո� 
		result = result.substr(1);
	} else {
		result = sign + result;
	}
	cout << result;
	return 0;
}
