#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <int, int> m;
int N, M, a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a;
        m[a]++;
    }
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> a;
        cout << m[a] << " ";
    }
}