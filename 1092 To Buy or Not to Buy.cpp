#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string shopOwner, Eva;
	cin >> shopOwner >> Eva;
	int index, missingNum = 0;
	for(auto ch: Eva){
		if((index = shopOwner.find(ch)) != string::npos){
			//shopOwner.replace(index, 1, "");
            shopOwner.erase(index, 1);
		} else {
			missingNum++;
		}
	}
	if(missingNum == 0){
		printf("Yes %d", shopOwner.length());
	} else {
		printf("No %d", missingNum);
	}
	return 0;
}
