#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> n;
int N,M;
int s,e,mmax;
int re;
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        n.push_back(a);
    }
    e = *max_element(n.begin(),n.end());
    while(s<=e){
        long long int t = 0;
        int mid = (s+e)/2;
        for(int i=0; i<N; i++){
            if(n[i]>mid) t+=n[i] - mid;
        }
        if(t<M){
            e = mid - 1;
        }else{
            re = mid;
            s = mid+1;
        }
    }
    cout << re;
}