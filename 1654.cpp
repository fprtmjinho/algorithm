#include <iostream>

using namespace std;

unsigned int N,K,re;
unsigned int n[10000];
int main(){
    cin >> K >> N;

    unsigned int maxx = 0;

    for(int i=0; i<K; i++){
        int a; cin >> a;
        n[i]=a;
        maxx = max(maxx, n[i]);
    }

    unsigned int l = 1, r = maxx, m;

    while(l <= r){
        m=(l+r)/2;
        unsigned int t = 0;
        for(int i=0; i<K; i++){
            t += n[i]/m;
        }
        if(t>=N){
            l = m +1;
            re = max(re,m);
        }else{
            r = m-1;
        }
    }
    cout << re << "\n";
}