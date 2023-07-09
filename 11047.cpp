#include <iostream>

using namespace std;

int main(){
    int N,K; cin >> N >> K;
    int n[N];
    int max;
    int cnt=0;
    for (int i=0;i<N;i++){
        cin >> n[i];
    }
    for (int i = N-1; i>=0; i--){
        cnt = cnt + K/n[i];
        K=K%n[i];
    }
    cout << cnt << endl;
}