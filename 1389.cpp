#include <iostream>
#include <queue>

using namespace std;

int N,M;
int graph[101][101];
int visited[101][101];

int cal(int s){
    int cnt=0;
    for(int i=1; i<=N; i++){
        cnt= cnt+visited[s][i];
    }
    return cnt;
}
void BFS(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=1; i<=N;i++){
            if (i==v)
                continue;
            if(graph[v][i]==1){
                if(visited[s][i]==0){
                    visited[s][i]=visited[s][v]+1;
                    q.push(i);
                }
                else if(visited[s][i]>visited[s][v]+1){
                    visited[s][i]=visited[s][v]+1;
                    q.push(i);
                }
            }
        }
    }
}
void init(){
    for(int i=0; i<=N; i++){
        fill_n(visited[i],N+1,0);
    }
}

int main(){
    cin >> N >> M;
    int min=0;
    int minv=0;
    for(int i=0; i<M; i++){
        int u,v; cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    for(int i=1; i<=N; i++){
        init();
        BFS(i);
        int bcal = cal(i);
        if(min==0){
            min=bcal;
            minv=i;
        }
        else if(min>bcal){
            min=bcal;
            minv=i;
        }
    }
    cout << minv;
}