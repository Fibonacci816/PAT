#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int Nc, Np;
    vector<int> couponNumP, couponNumN, productNumP, productNumN; //P:positive N:negative
    int value, maxTotalValue = 0;
    scanf("%d", &Nc);
    for(int i = 0; i < Nc; i++){
        scanf("%d", &value);
        if(value > 0){
            couponNumP.push_back(value);
        } else if (value < 0){
            couponNumN.push_back(value);
        }
    }
    sort(couponNumP.rbegin(), couponNumP.rend());
    sort(couponNumN.begin(), couponNumN.end());
    scanf("%d", &Np);
    for(int i = 0; i < Np; i++){
        scanf("%d", &value);
        if(value > 0){
            productNumP.push_back(value);
        } else if (value < 0){
            productNumN.push_back(value);
        }
    }
    sort(productNumP.rbegin(), productNumP.rend());
    sort(productNumN.begin(), productNumN.end());
    int i = 0;
    while(i < couponNumP.size() && i < productNumP.size()){
        maxTotalValue += couponNumP[i] * productNumP[i];
        i++;
    }
    i = 0;
    while(i < couponNumN.size() && i < productNumN.size()){
        maxTotalValue += couponNumN[i] * productNumN[i];
        i++;
    }
    printf("%d", maxTotalValue);
    return 0;
}
