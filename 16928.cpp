#include <iostream>
#include <queue>

using namespace std;

vector<int> graph[101];
int visited[101];
int N,M;

void BFS(int s){
    queue<int> q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=1; i<=6; i++){
            if(v+i<=100&&visited[v+i]==0){
                if(graph[v+i].size()==0){
                    q.push(v+i);
                    visited[v+i]=visited[v]+1;
                }
                else{
                    for(int j=0; j<graph[v+i].size();j++){
                        if(visited[graph[v+i][j]]==0){
                            q.push(graph[v+i][j]);
                            visited[graph[v+i][j]]=visited[v]+1;
                        }
                        else if (visited[graph[v+i][j]]>visited[v]+1){
                            q.push(graph[v+i][j]);
                            visited[graph[v+i][j]]=visited[v]+1;
                        }
                    }
                }
            }
            else if(v+i<=100 && visited[v+i]>visited[v]+1){
                if(graph[v+i].size()==0){
                    q.push(v+i);
                    visited[v+i]=visited[v]+1;
                }
                else{
                    for(int j=0; j<graph[v+i].size();j++){
                        if (visited[graph[v+i][j]]>visited[v]+1){
                            q.push(graph[v+i][j]);
                            visited[graph[v+i][j]]=visited[v]+1;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N+M;i++){
        int x,y; cin >> x >> y;
        graph[x].push_back(y);
    }
    BFS(1);
    cout << visited[100]-1;
}