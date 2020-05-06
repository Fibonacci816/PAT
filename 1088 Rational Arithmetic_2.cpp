#include <iostream>
using namespace std;

int GCD(long long a, long long b)
{
	return b == 0 ? a : GCD(b, a%b);
}
void PrintSimplestForm(long long a, long long b)
{
	if(b == 0) {
		printf("Inf");
		return;
	}
	if((a < 0 && b > 0) || (a > 0 && b < 0))
		printf("(-");
	long long absa = abs(a), absb = abs(b);
	long long gcd = GCD(absa, absb);
	absa /= gcd;
	absb /= gcd;
	long long integetPart = absa / absb;
	if(absa % absb == 0) {
		printf("%lld", integetPart);
	} else {
		if(integetPart != 0)
			printf("%lld ", integetPart);
		printf("%lld/%lld", absa%absb, absb);
	}
	if((a < 0 && b > 0) || (a > 0 && b < 0)) 
		printf(")");
}

int main()
{
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	string opreation = "+-*/";
	for(auto ch: opreation) {
		PrintSimplestForm(a1, b1);
		printf(" %c ", ch);
		PrintSimplestForm(a2, b2);
		printf(" = ");
		if(ch == '+') PrintSimplestForm(a1*b2+a2*b1, b1*b2);
		if(ch == '-') PrintSimplestForm(a1*b2-a2*b1, b1*b2);
		if(ch == '*') PrintSimplestForm(a1*a2, b1*b2);
		if(ch == '/') PrintSimplestForm(a1*b2, b1*a2);
		printf("\n");
	}
	return 0;
}
