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
	//�����ֻ���ҳ���һ���ַ��������һ���ַ������ǰ׺
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
