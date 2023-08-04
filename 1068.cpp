#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[50];
int S,cnt,D;

int DFS(int node){
    if(node==D) return -1;
    if(graph[node].size()==0){
        cnt++;
        return 0;
    }
    for(int i=0; i < graph[node].size(); i++){
        if(DFS(graph[node][i])==-1 && graph[node].size() == 1) cnt++;
    }
    return 0;
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int n; cin >> n;
        if (n==-1) S=i;
        else graph[n].push_back(i);
    }
    cin >> D;
    cnt = 0;
    DFS(S);
    cout << cnt;
}