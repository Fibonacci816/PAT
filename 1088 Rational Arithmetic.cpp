#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

char operators[4] = {'+', '-', '*', '/'};

long GCD(long n1, long n2)
{
	n1 = abs(n1);
	n2 = abs(n2);
	return n2 ? GCD(n2, n1%n2) : n1; 
}
//化简分数 
void Simplify(long * numerator, long * denominator)
{
	long gcd = GCD(*numerator, *denominator);
	*numerator /= gcd;
	*denominator /= gcd;
}
//将分数转为整数部分和真分数部分组成的字符串 
string ToString(long numerator, long denominator)
{
	string str;
	if(numerator % denominator == 0){
		str += to_string(numerator/denominator);
	} else {
		if(numerator/denominator != 0){
			str += to_string(numerator/denominator) + " ";
			str += to_string(abs(numerator)%denominator) + "/" + to_string(denominator);
		} else {
			str += to_string(numerator%denominator) + "/" + to_string(denominator);
		}
	}
	if(numerator < 0){
		str = "(" + str;
		str = str + ")";
	}
	return str;
}
//两个分数进行运算并将结果以字符串形式返回
string Operate(long numerator1, long denominator1, long numerator2, long denominator2, char ope)
{
	long resultNumerator, resultDenominator;
	if(ope == '+'){
		long lcm = denominator1 * denominator2 / GCD(denominator1, denominator2);
		resultNumerator = numerator1 * lcm / denominator1 + numerator2 * lcm / denominator2;
		resultDenominator = lcm;
	} else if(ope == '-'){
		long lcm = denominator1 * denominator2 / GCD(denominator1, denominator2);
		resultNumerator = numerator1 * lcm / denominator1 - numerator2 * lcm / denominator2;
		resultDenominator = lcm;
	} else if(ope == '*'){
		resultNumerator = numerator1 * numerator2;
		resultDenominator = denominator1 * denominator2;
	} else if(ope == '/'){
		if(numerator2 == 0){
			return "Inf";
		}
		resultNumerator = numerator1 * denominator2;
		resultDenominator = denominator1 * numerator2;
		//如果分母小于0，则分子分母都乘-1 
		if(resultDenominator < 0){
			resultNumerator = -resultNumerator;
			resultDenominator = -resultDenominator;
		}
	} 
	Simplify(&resultNumerator, &resultDenominator);
	return ToString(resultNumerator, resultDenominator);
}

int main()
{
	long numerator1, denominator1, numerator2, denominator2, gcd;
	string number1, number2, result;
	scanf("%ld/%ld %ld/%ld", &numerator1, &denominator1, &numerator2, &denominator2);
	Simplify(&numerator1, &denominator1);
	Simplify(&numerator2, &denominator2);
	number1 = ToString(numerator1, denominator1);
	number2 = ToString(numerator2, denominator2);
	for(int i = 0; i < 4; i++){
		result = Operate(numerator1, denominator1, numerator2, denominator2, operators[i]);
		cout << number1 << " " << operators[i] << " " << number2 << " = " << result << endl;
	}
	return 0;
}
