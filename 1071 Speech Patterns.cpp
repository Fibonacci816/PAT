#include <string>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	char word[100], ch;
	map<string, int> Map;
	int i = 0, maxCount = 0;
	while(true){
        ch = getchar();
		if(ch>='0'&&ch<='9' || ch>='A'&&ch<='Z' || ch>='a'&&ch<='z'){
			if(ch>='A'&&ch<='Z'){
				ch += 32;
			}
			word[i++] = ch;
		} else if(i != 0){
			word[i] = '\0';
			Map[word]++;
			if(maxCount < Map[word]){
				maxCount = Map[word];
			}
			i = 0;
		}
        if(ch == '\n')
            break;
	}
	map<string, int>::iterator it = Map.begin();
	while(it != Map.end()){
		if(it->second == maxCount){
            cout << it->first << ' ' << maxCount;
            break;
		}
		it++;
	}
	return 0;
}
