#include <iostream>

using namespace std;

long long dp[101];
int main(){
    int T; cin >> T;
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<101;i++){
        dp[i]=dp[i-2]+dp[i-3];
    }
    for (int i=0; i<T; i++){
        int n; cin>>n;
        cout << dp[n] << endl;
    }
}