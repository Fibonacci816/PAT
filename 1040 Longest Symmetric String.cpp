#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int MaxCommonStrLen(string str1, string str2) //str1为较长字符串
{
    int maxCommonStrLen = 0;
    for(int i = 0; i < str2.size(); i++){
        //当起始位置到字符串结尾的子串长度小于已知最大公共子串长度时，最大公共子串长度不会再更新，算法终止返回最大公共子串长度
        if(str2.size()-i <= maxCommonStrLen)
            break;
        for(int len = str2.size()-i; len > 0; len--){
            if(str1.find(str2.substr(i, len)) != string::npos){
                if(len > maxCommonStrLen){
                    maxCommonStrLen = len;
                }
                break;
            }
        }
    }
    return maxCommonStrLen;
}
int MaxSymmetricStrLen(string str)
{
    int maxSymmetricStrLen = 0;
    string str1, str2;
    for(int i = 0; i < str.size(); i++){
        if(str.size()-i <= maxSymmetricStrLen)
            break;
        for(int len = str.size()-i; len > 0; len--){
            str1 = str2 = str.substr(i, len);
            reverse(str2.begin(), str2.end());
            if(str1 == str2){
                if(len > maxSymmetricStrLen){
                    maxSymmetricStrLen = len;
                }
                break;
            }
        }
    }
    return maxSymmetricStrLen;
}
int main()
{
    string ori_string, rev_string;
    getline(cin,ori_string);
    //rev_string = ori_string;
    //reverse(rev_string.begin(), rev_string.end());
    printf("%d", MaxSymmetricStrLen(ori_string));
    //printf("%d", MaxCommonStrLen(ori_string, rev_string));
    return 0;
}
