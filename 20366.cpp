#include <iostream>
#include <algorithm>

using namespace std;

vector<int> n;

int main(){
    int N; cin >> N;
    for(int i=0; i<N; i++){
        int a; cin >>a;
        n[i] = a;
    }
    sort(n.begin(),n.end());
    
}