#include <iostream>
#include <algorithm>
using namespace std;

string lines[100];

int main()
{
	int lineNum;
	string line;
	scanf("%d\n", &lineNum);
	for(int i = 0; i < lineNum; i++){
		getline(cin, line);
		reverse(line.begin(), line.end());
		lines[i] = line;
	}
	sort(lines, lines+lineNum);
	string kuchiguse;
	//排序后只需找出第一个字符串和最后一个字符串的最长前缀
	for(int i = 0; i < lines[0].length(); i++){
		if(lines[0][i] == lines[lineNum-1][i]){
			kuchiguse += lines[0][i];
		} else {
			break;
		}
	}
	if(kuchiguse.empty()){
		cout << "nai";
	} else {
		reverse(kuchiguse.begin(), kuchiguse.end());
		cout << kuchiguse;
	}
	return 0;
}
