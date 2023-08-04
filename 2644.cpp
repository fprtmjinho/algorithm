#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
queue<int> q;
int visited[101];

int n,s,e,m;

void BFS(){
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<graph[v].size();i++){
            if (visited[graph[v][i]]==0 || visited[graph[v][i]]>visited[v]+1){
                q.push(graph[v][i]);
                visited[graph[v][i]]=visited[v]+1;
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> s>>e;
    cin >> m;
    for(int i =0; i<m; i++){
        int x,y; cin >> x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    BFS();
    cout << visited[e] - 1;
}