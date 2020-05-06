#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int M, N, S;
	scanf("%d %d %d", &M, &N, &S);
	char name[21];
	map<string, int> winners;
	int count = 1;
	for(int i = 1; i <= M; i++){
		scanf("%s", name);
		if(count>=S && (count-S)%N==0){
			if(winners.count(name)==0){
				printf("%s\n", name);
				winners[name] = 1;
				count++;
			}
		} else {
			count++;
		}
	} 
	if(winners.size() == 0)
		printf("Keep going...\n");
	return 0;
 } 
