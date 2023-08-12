#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int a;
    for(int i=0; i<N*N; i++){
        cin >> a;
        q.push(a);
        if(q.size() > N) q.pop();
    }
    cout << q.top();
}