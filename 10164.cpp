#include <iostream>

using namespace std;

int dp[16][16];


int main(){
    int N,M,K,Kx,Ky; cin >> N>>M>>K;
    int cnt = 0;
    dp[1][1]=1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] += dp[i-1][j]+dp[i][j-1];
        }
    }
    if(K!=0){
        if(K%M!=0){
            Ky=K%M;
            Kx=(K-Ky)/M+1;
        }
        else{
            Kx=K/M;
            Ky=M;
        }
    }
    if(K==0) cout << dp[N][M];
    else cout << dp[Kx][Ky]*dp[N-Kx+1][M-Ky+1];
}