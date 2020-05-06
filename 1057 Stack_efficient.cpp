#include <iostream>
#include <stack>
#define MAX 100001
using namespace std;

int elements[MAX];

int Lowbit(int i)
{
	return i & -i;
}
void Update(int index, int val)
{
	for(int i = index; i < MAX; i+=Lowbit(i))
		elements[i] += val;
}
int GetSum(int n)
{
	int sum = 0;
	for(int i = n; i > 0; i-=Lowbit(i))
		sum += elements[i];
	return sum;
}
int GetKth(int k)
{
	int l = 1, r = MAX-1;
	while(l < r) {
		int m = (l + r) / 2;
		if(GetSum(m) >= k) r = m;
		else l = m + 1;
	}
	return l;
}

int main()
{
	int N;
	scanf("%d\n", &N);
	char command[10];
	int key;
	stack<int> keys;
	for(int i = 0; i < N; i++){
		scanf("%s", command);
		if(string(command) == "Push") {
			scanf("%d", &key);
			keys.push(key);
			Update(key, 1);
		} else if(string(command) == "Pop") {
			if(keys.empty()) {
				printf("Invalid\n");
			} else {
				printf("%d\n", keys.top());
				Update(keys.top(), -1);
				keys.pop();
			}
		} else {
			if(keys.empty()) {
				printf("Invalid\n");
			} else {
				int median = GetKth((keys.size()+1)/2);
				printf("%d\n", median);
			}
		}
	}
	return 0;
 } 
