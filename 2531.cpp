#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int cho[30001];
int check[3001];

int main(){
    int N,d,k,c; cin >>N>>d>>k>>c;
    int flag,coupon;
    int mmax=0;
    for(int i=0; i<N; i++){
        int n; cin>>n;
        cho[i]=n;
    }
    for(int i=0; i<N; i++){
        flag=0;
        coupon=1;
        for(int j=i; j<i+k;j++){
            if(check[cho[j%N]]==1)flag++;
            else check[cho[j%N]] =1;

            if(cho[j%N]==c) coupon = 0;
        }
        mmax = max(mmax,k-flag+coupon);
        memset(check,0,sizeof(check));
    }
    cout << mmax;
}