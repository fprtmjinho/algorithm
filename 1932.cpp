#include <iostream>
#include <vector>

using namespace std;

int dp[500][500];

int main(){
    int N; cin >> N;
    vector<int> v[N];
    for(int i=1; i<=N; i++){
        for(int j=0; j<i; j++){
            int a; cin >> a;
            v[i-1].push_back(a);
        }
    }
    dp[0][0]=v[0][0];
    for(int i=1; i<N; i++){
        for(int j=0; j<v[i].size();j++){
            if(v[i].size()-1>j && j>0){
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+v[i][j];
            }
            else if(j==0)
                dp[i][j]=dp[i-1][j]+v[i][j];
            else if(j==v[i].size()-1)
                dp[i][j]=dp[i-1][j-1]+v[i][j];
        }
    }
    int maxx=0;
    for(int i=0;i<N; i++){
        maxx=max(maxx,dp[N-1][i]);
    }
    cout << maxx;
}