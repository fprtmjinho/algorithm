#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N,M;

void backtracking(vector<int> v){
    if(v.size()==M){
        for(int i=0; i<M;i++){
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=1; i<=N;i++){
        if(v.size()==0 && find(v.begin(),v.end(),i)==v.end()){
            v.push_back(i);
            backtracking(v);
            v.pop_back();
        }
        else if(find(v.begin(),v.end(),i)==v.end() && i>v.back()){
            v.push_back(i);
            backtracking(v);
            v.pop_back();
        }
    }
}

int main(){
    cin >> N >> M;
    vector<int> v;
    backtracking(v);
}