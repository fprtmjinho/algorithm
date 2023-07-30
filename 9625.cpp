#include <iostream>

using namespace std;

int dpa[46];
int dpb[46];

void dp(int k){
    for(int i=3; i<=k; i++){
        dpa[i] = dpa[i-1]+dpa[i-2];
        dpb[i] = dpb[i-1]+dpb[i-2];
    }
}

int main(){aaa
    int k; cin >>k;
    dpa[1] = 0;
    dpb[1] = 1;
    dpa[2] = 1;
    dpb[2] = 1;
    if (k>2){
        dp(k);
    }
    cout << dpa[k] << " " << dpb[k];
    
}