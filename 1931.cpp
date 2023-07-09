#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    vector<pair<int,int> > v;
    for (int i=0; i<N;i++){
        int s,e; cin >> s>>e;
        v.push_back(pair<int,int>(e,s));
    }
    sort(v.begin(),v.end());
    int cnt=1;
    int time=v[0].first;
    for(int i=1; i< N; i++){
        if(time <= v[i].second){
            cnt++;
            time = v[i].first;
        }
    }
    cout << cnt;
}