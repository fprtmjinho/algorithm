#include <iostream>

using namespace std;

bool N[1000001];

int main(){
    int n; cin>> n;
    int cnt=0;
    for (int i=0; i<n; i++){
        int a; cin >> a;
        N[a]=true;
    }
    int x; cin >> x;
    for(int i=1; i<1000001; i++){
        if(!N[i]) continue;
        if(x-i>1000000) continue;
        if(x-i<1) continue;
        if(!N[x-i]) continue;
        cnt++;
    }
    cout << cnt/2;
}