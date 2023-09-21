#include <iostream>
#include <queue>

using namespace std;

int N,K;
int graph[100001];

void bfs(){
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if (v+1<=100000)
            if(graph[v+1]==0||graph[v+1]>graph[v]+1){
                graph[v+1] = graph[v]+1;
                q.push(v+1);
            }
        if (v-1>=0){
            if(graph[v-1]==0||graph[v-1]>graph[v]+1){
                graph[v-1] = graph[v]+1;
                q.push(v-1);
            }
        }
        if (v*2<=100000)
            if(graph[v*2]==0||graph[v*2]>graph[v]){
                graph[v*2] = graph[v];
                q.push(v*2);
            }
    }
}

int main(){
    cin >> N >> K;
    graph[N]=1;
    bfs();
    cout<< graph[K]-1;
}