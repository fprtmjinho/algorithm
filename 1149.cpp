#include <iostream>
#include <algorithm>

using namespace std;

int cost[3];
int a[1001][3];

int main(){
    int N; cin >> N;
    a[0][0] = 0;
    a[0][1] = 0;
    a[0][2] = 0;
    for(int i = 1; i <=N; i++){
        cin >> cost[0] >> cost[1] >> cost[2];
        a[i][0] = min(a[i-1][1],a[i-1][2]) + cost[0];
        a[i][1] = min(a[i-1][0],a[i-1][2]) + cost[1];
        a[i][2] = min(a[i-1][1],a[i-1][0]) + cost[2];
    }
    cout << min(a[N][2],min(a[N][0],a[N][1]));
}