#include <stdio.h>
#include <algorithm>
using namespace std;

struct Person{
	int ID_Number;
	int Virtue_Grade;
	int Talent_Grade;
	int Total_Grade;
	int flag;
};
Person people[100000];
bool cmp(Person person1, Person person2)
{
	if(person1.flag != person2.flag){
		return person1.flag < person2.flag;
	} else if(person1.Total_Grade != person2.Total_Grade){
		return person1.Total_Grade > person2.Total_Grade;
	} else if(person1.Virtue_Grade != person2.Virtue_Grade){
		return person1.Virtue_Grade > person2.Virtue_Grade;
	}else {
		return person1.ID_Number < person2.ID_Number;
	}
}
int main()
{
	int N, L, H;
	int ID_Number, Virtue_Grade, Talent_Grade, rankNum = 0;
	scanf("%d %d %d", &N, &L, &H);
	for(int i = 0; i < N; i++){
		scanf("%d %d %d", &ID_Number, &Virtue_Grade, &Talent_Grade);
		if(Virtue_Grade>=L && Talent_Grade>=L){
			people[rankNum].ID_Number = ID_Number;
			people[rankNum].Virtue_Grade = Virtue_Grade;
			people[rankNum].Talent_Grade = Talent_Grade;
			people[rankNum].Total_Grade = Virtue_Grade + Talent_Grade;
			if(Virtue_Grade>=H &  Talent_Grade>=H){
				people[rankNum++].flag = 1;
			} else if(Talent_Grade<H && Virtue_Grade>=H){
				people[rankNum++].flag = 2;
			} else if(Talent_Grade<H && Virtue_Grade<=H && Virtue_Grade>=Talent_Grade){
				people[rankNum++].flag = 3;
			} else {
				people[rankNum++].flag = 4;
			}
		}
	}
	sort(people, people+rankNum, cmp);
	printf("%d\n", rankNum);
	for(int i = 0; i < rankNum; i++){
		printf("%08d %d %d\n", people[i].ID_Number, people[i].Virtue_Grade, people[i].Talent_Grade);
	}
	return 0;
}
