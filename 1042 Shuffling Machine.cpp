#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string cards[54];
int indes[54];
void InitialCard()
{
    string numbers[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
    for(int i = 0; i < 13; i++){
        cards[i] = "S" + numbers[i];
        cards[i+13] = "H" + numbers[i];
        cards[i+26] = "C" + numbers[i];
        cards[i+39] = "D" + numbers[i];
    }
    cards[52] = "J1";
    cards[53] = "J2";
}
int main()
{
    int K;
    string temp[54]; //Ã¿´ÎshuffleÇ°ÔÝ´æcards
    InitialCard();
    scanf("%d", &K);
    for(int i = 0; i < 54; i++){
        scanf("%d", &indes[i]);
    }
    for(int k = 0; k < K; k++){
        for(int i = 0; i < 54; i++){
            temp[i] = cards[i];
        }
        for(int i = 0; i < 54; i++){
            cards[indes[i]-1] = temp[i];
        }
    }
    for(int i = 0; i < 54; i++){
        cout << cards[i];
        if(i != 53){
            printf(" ");
        }
    }
    return 0;
}
