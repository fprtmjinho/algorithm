#include <iostream>
#include <queue>

using namespace std;

int N,M;
queue<int> q;

int graph[1001][1001];
int visited[1001];
int cnt=0;

void BFS(int s){
    q.push(s);
    int flag=0;
    visited[s]=1;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=1; i<=N; i++){
            if (graph[v][i]==1 && visited[i]==0){
                q.push(i);
                visited[i]=1;
                flag=1;
            }
        }
    }
}
int main(){
    cin >> N >>M;
    for(int i=0; i<M; i++){
        int u,v; cin >> u >>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    for(int i=1;i<=N;i++){
        if(visited[i]==0){
            BFS(i);
            cnt++;
        }
    }
    cout << cnt;
}