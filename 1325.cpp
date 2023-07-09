#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[10001];
queue<int> re[10001];
queue<int> q;

int BFS(int s){
    int cnt=0;
    int visited[10001]={0};
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<graph[v].size();i++){
            if(visited[graph[v][i]]==0){
                q.push(graph[v][i]);
                visited[graph[v][i]]=1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int N,M; cin>>N>>M;
    int mcnt=0;
    for(int i=0; i<M; i++){
        int a,b; cin >> a>>b;
        graph[b].push_back(a);
    }
    for(int i=1; i<=N;i++){
        int cnt = BFS(i);
        if(mcnt<=cnt){
            mcnt=cnt;
            re[mcnt].push(i);
        }
    }
    int j= re[mcnt].size();
    for(int i=0; i<j;i++){
        cout<<re[mcnt].front()<<" ";
        re[mcnt].pop();
    }
}