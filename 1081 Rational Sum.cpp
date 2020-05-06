#include <iostream>
using namespace std;

int GCD(long n1, long n2)
{
	return n2 ? GCD(n2, n1%n2) : n1;
}

int main()
{
	int N;
	scanf("%d", &N);
    long lcm, gcd, gn = 0, gd = 1;
    long numerator, denominator;
	for(int i = 0; i < N; i++){
		scanf("%ld/%ld", &numerator, &denominator);
        lcm = gd * denominator / GCD(gd, denominator);
        gn = gn * (lcm/gd) + numerator * (lcm/denominator);
        gd = lcm;
        gcd = GCD(gn, gd);
        gn /= gcd;
        gd /= gcd;
	}
	if(gn % gd == 0){
		printf("%ld", gn/gd);
	} else {
        if(gn/gd != 0){
            printf("%ld ", gn/gd);
        }
        printf("%ld/%ld", gn%gd, gd);
	}
	return 0;
}
