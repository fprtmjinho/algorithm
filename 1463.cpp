#include <iostream>
#include <queue>

using namespace std;

int dp[1000001];
queue<int> q;
int main(){
    int X; cin >>X;
    q.push(X);
    dp[X]=1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v%3==0){
            if (dp[v/3]==0){
                q.push(v/3);
                dp[v/3]=dp[v]+1;
            }
            else if(dp[v/3]>dp[v]+1){
                q.push(v/3);
                dp[v/3]=dp[v]+1;
            }
        }
        if(v%2==0){
            if(dp[v/2]==0){
                q.push(v/2);
                dp[v/2]=dp[v]+1;
            }
            else if(dp[v/2]>dp[v]+1){
                q.push(v/2);
                dp[v/2]=dp[v]+1;
            }
        }
        if(v-1!=0){
            if(dp[v-1]==0){
                q.push(v-1);
                dp[v-1]=dp[v]+1;
            }
            else if(dp[v-1]>dp[v]+1){
                q.push(v-1);
                dp[v-1]=dp[v]+1;
            }
        }
    }
    cout << dp[1]-1;
}