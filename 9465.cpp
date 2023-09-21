#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][100001];
int dpp[2][100001];

int main(){
    int T; cin >> T;
    for(int k=0; k<T; k++){
        int n; cin >>n;
        for(int j=0; j<n; j++)
            cin >> dpp[0][j];
        for (int j=0; j<n; j++)
            cin >> dpp[1][j];
        dp[0][0] = dpp[0][0];
        dp[1][0] = dpp[1][0];
        dp[0][1] = dpp[0][1] + dp[1][0];
        dp[1][1] = dpp[1][1] + dp[0][0];
        for(int i=2; i<n; i++){
            dp[0][i] = dpp[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = dpp[1][i] + max(dp[0][i-1],dp[0][i-2]);
        }
        cout << max(dp[0][n-1],dp[1][n-1]) << endl;
    }
}