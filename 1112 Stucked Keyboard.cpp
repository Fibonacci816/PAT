#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	int k;
	string resulting, original;
	cin >> k >> resulting;
	original = resulting;
	resulting += '#';  //末尾添加一个字符串中不存在的字符以便下面的for循环能处理字符串最后一个字符 
	unordered_map<char, int> charMap;
	vector<char> stuckedKeys;
	char pre = '#';  //初始化pre为一个字符串中不存在的字符 
	int count = 0;
	for(int i = 0; i < resulting.length(); i++){
		if(count == k){
			if(charMap.count(pre) == 0){
				charMap[pre] = 1;
				stuckedKeys.push_back(pre);
			}
			pre = '#'; 
			count = 0;
		}
		if(resulting[i] != pre){
			if(count != 0){  //count不为0说明连续相同字符的个数不足k 
				charMap[pre] = 0;
				vector<char>::iterator it = find(stuckedKeys.begin(), stuckedKeys.end(), pre);
				if(it != stuckedKeys.end())
					stuckedKeys.erase(it);
				count = 0;
			}
			pre = resulting[i];
		}
		count++;
	}
	for(int i = 0; i < original.length(); i++){
		if(charMap[original[i]] == 1)
			original.erase(i+1, k-1);
	}
	for(int i = 0; i < stuckedKeys.size(); i++)
		cout << stuckedKeys[i];
	cout << endl << original;
	return 0;
}
