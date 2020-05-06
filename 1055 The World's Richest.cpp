#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct Node{
	string Name;
	int Age;
	int Net_Worth;
} Person;

bool cmp(Person person1, Person person2)
{
	if(person1.Net_Worth != person2.Net_Worth){
		return person1.Net_Worth > person2.Net_Worth; 
	} else if(person1.Age != person2.Age){
		return person1.Age < person2.Age;
	} else {
		return person1.Name < person2.Name;
	}
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	Person people[N];
	for(int n = 0;  n < N; n++){
		cin >> people[n].Name;
		scanf("%d %d", &people[n].Age, &people[n].Net_Worth);
	}
	sort(people, people+N, cmp);
	int queNum, quedNum, Amin, Amax;
	for(int k = 1;  k <= K; k++){
		printf("Case #%d:\n", k);
		quedNum = 0;
		scanf("%d %d %d", &queNum, &Amin, &Amax);
		for(int i = 0; i < N; i++){
			if(people[i].Age >= Amin && people[i].Age <= Amax){
				cout << people[i].Name;
				printf(" %d %d\n", people[i].Age, people[i].Net_Worth);
				quedNum++;
				if(quedNum == queNum)
					break;
			}
		}
		if(quedNum == 0){
			printf("None\n");
		} 
	}
	return 0;
}
