#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[300001];
int visited[300001];
queue<int> q;

int N,M,K,X;

void BFS(int s){
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int v =q.front();
        q.pop();
        for(int i=0;i<graph[v].size();i++){
            if(visited[graph[v][i]]>visited[v]+1||visited[graph[v][i]]==0){
                visited[graph[v][i]]=visited[v]+1;
                q.push(graph[v][i]);
            }
        }
    }
}

int main(){
    cin>>N>>M>>K>>X;
    int cnt=0;
    for(int i=0; i<M; i++){
        int s,e; cin>>s>>e;
        graph[s].push_back(e);
    }
    BFS(X);
    for(int i=2; i<=N;i++){
        if(visited[i]==K+1){
            cnt++;
            cout << i << endl;
        }
    }
    if (cnt==0)
        cout<<-1;
}