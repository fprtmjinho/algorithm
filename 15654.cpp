#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> n;
bool selected[8];
vector<int> v;
 
void print() {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}
 
void DFS(int cnt) {
    if (cnt == M) {
        print();
        return;
    }
    for (int i = 0; i < N; i++) {
        if (selected[i]) continue;
        selected[i] = true;
        v.push_back(n[i]);
        DFS(cnt + 1);
        v.pop_back();
        selected[i] = false;
    }
}
 
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        n.push_back(a);
    }
 
    sort(n.begin(), n.end());
 
    DFS(0);
 
    return 0;
}
