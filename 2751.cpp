#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> n;

int main(){
    int N; cin >> N;
    for(int i=0; i<N;i++){
        int a; cin >> a;
        n.push_back(a);
    }
    sort(n.begin(),n.end());  
    for(int i=0; i<N;i++){
        cout << n[i] << '\n';
    } 
}