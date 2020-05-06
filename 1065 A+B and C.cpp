#include <stdio.h>

int main()
{
	int T;
	long long a, b, c, sum;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		printf("Case #%d: ", i);
		scanf("%lld %lld %lld", &a, &b, &c);
		sum = a + b;
		if(a>0 && b>0 && sum<=0){
			printf("true\n");
		} else if(a<0 && b<0 && sum>=0){
			printf("false\n");
		}else if(sum > c){
			printf("true\n");
		} else {
			printf("false\n");
		}
	}
	return 0;
 } 
