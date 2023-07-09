#include <iostream>
#include <algorithm>
#include<limits.h>

using namespace std;

int dp[50001];

int main(){
    int n; cin >>n;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        int minn = INT_MAX;
        for(int j= 1; j*j<=i;j++){
            int tmp =i- j*j;
            minn = min(minn, dp[tmp]);
        }
        dp[i]= minn+1;
    }
    cout << dp[n];
}