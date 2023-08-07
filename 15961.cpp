#include <iostream>
#include <algorithm>

using namespace std;

int cho[30000001];
int check[3001];

int main(){
    int N,d,k,c; cin >>N>>d>>k>>c;
    for(int i=0; i<N; i++){
        int n; cin>>n;
        cho[i]=n;
    }
    int start = 0;
    int find = 0;
    for (int i=0; i<k; i++){
        if(!check[cho[i]]){
            find++;
        }
        check[cho[i]]++;
    }
    int mmax = find;
    for(int i=0; i<=N; i++){
        if(check[c]==0) mmax = max(mmax,find+1);
        else mmax = max(mmax, find);
        if(!check[cho[(start + k)%N]]++) find++;
        if(--check[cho[start]]==0) find--;
        start++;
    }
    cout << mmax;
}