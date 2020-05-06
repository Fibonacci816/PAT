#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int countP = 0, countPA = 0, countPAT = 0;
	for(auto ch: str){
		if(ch == 'P'){
			countP++;
		} else if(ch == 'A'){
			countPA += countP;
		} else {
			countPAT += countPA;
            countPAT %= 1000000007;
		}
	}
	cout << countPAT;
	return 0;
}
