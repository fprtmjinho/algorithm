#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M,V;
int graph[1001][1001];
bool visited[1001];
queue<int> q;

void BFS(int s){
    q.push(s);
    visited[s]=1;
    cout << s << " ";
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=1; i<=N;i++){
            if(graph[v][i]==1&&visited[i]==0){
                q.push(i);
                visited[i]=1;
                cout << i << " ";
            }
        }
    }
}

void DFS(int s){
    visited[s]=1;
    cout << s << " ";
    for(int i=1;i<=N;i++){
        if(graph[s][i]==1&&visited[i]==0){
            DFS(i);
        }
    }
}
void INIT(){
    for(int i=1; i<=N; i++) visited[i]=0;
}

int main(){
    cin >> N>>M>>V;
    for(int i=0; i<M; i++){
        int s,e; cin >> s>>e;
        graph[s][e]=1;
        graph[e][s]=1;
    }
    DFS(V);
    cout << "\n";
    INIT();
    BFS(V);
    
}