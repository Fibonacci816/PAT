#include <stdio.h> 
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, operand;
	char operationc[10];
	string operation;
	stack<int> s;
	vector<int> v;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", operationc);
		operation = operationc;
		if(operation == "Pop"){
			if(s.empty()){
				printf("Invalid\n");
			} else {
				printf("%d\n", s.top());
				if(s.top() == v.back()){
					v.pop_back();
				} else {
					vector<int>::iterator it = find(v.begin(), v.end(), s.top());
					v.erase(it);
				}
				s.pop();
			}
		} else if(operation == "Push"){
			scanf("%d\n", &operand);
			s.push(operand);
			v.push_back(operand);
			if(v[v.size()-1] < v[v.size()-2])
				sort(v.begin(), v.end());
		} else if(operation == "PeekMedian"){
			if(s.empty()){
				printf("Invalid\n");
			} else {
				printf("%d\n", v[(v.size()-1)/2]);
			}
		}
	}
	return 0;
}
