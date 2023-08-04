#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double dp[10001];
vector<double> n;

int main(){
    int N; cin >> N;
    for (int i=0; i<N; i++){
        double a; cin >> a;
        n.push_back(a);
    }
    double mmax = 0.0;
    dp[0] = n[0];
    for(int i = 1; i<N;i++){
        dp[i] = max(n[i], n[i] * dp[i-1]);
        mmax = max(mmax, dp[i]);
    }
    printf("%.3f",mmax);
}