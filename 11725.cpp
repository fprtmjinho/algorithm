#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[100001];
int visited[100001];
queue<int> q;

int N;

void BFS(){
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<graph[v].size();i++){
            if(visited[graph[v][i]]==0){
                q.push(graph[v][i]);
                visited[graph[v][i]]=v;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N-1;i++){
        int s,e; cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    BFS();
    for(int i=2; i<=N; i++){
        cout << visited[i] << "\n";
    }
}