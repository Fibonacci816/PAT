#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string ori, typed, result;
	int p = 0, q = 0;
	cin >> ori >> typed;
	while(p < ori.length()){
		if(ori[p] == typed[q]){
			p++;
			q++;
		} else {
			if(result.find(toupper(ori[p])) == string::npos)
				result += toupper(ori[p]);
			p++;
		}
	}
	cout << result;
	return 0;
}
