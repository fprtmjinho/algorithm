#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1000];

int main(){
    int N; cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++){
        int p; cin >> p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    dp[0]=v[0];
    int cnt=dp[0];
    for (int i=1; i<N; i++){
        dp[i]=dp[i-1]+v[i];
        cnt = cnt +dp[i];
    }
    cout << cnt;
}