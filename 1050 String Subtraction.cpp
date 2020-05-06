#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);
    for(int i = 0; i < S1.size(); i++){
        if(S2.find(S1[i]) == string::npos){
            cout << S1[i];
        }
    }
    return 0;
}
