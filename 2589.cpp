#include <iostream>
#include <queue>
#define PAIR pair<int,int>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int graph[51][51];
int visited[51][51];
int path[51][51];
queue<PAIR> q;

int N,M;
int maxxx=0;

void INIT(){
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            visited[i][j]=0;
            path[i][j]=0;
        }
    }
}
int bfs(int sx,int sy){
    q.push(PAIR(sx,sy));
    visited[sy][sx]=1;
    path[sy][sx]=1;
    while(!q.empty()){
        int vx=q.front().first;
        int vy=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx=vx+dx[i];
            int yy=vy+dy[i];
            if(xx>=0&&yy>=0&&xx<N&&yy<M&&graph[yy][xx]==1&&visited[yy][xx]==0){
                visited[yy][xx]=1;
                path[yy][xx]=path[vy][vx]+1;
                q.push(PAIR(xx,yy));
                if(maxxx<path[yy][xx])
                    maxxx=path[yy][xx];
            }
        }
    }
    return maxxx-1;
}

int main(){
    cin >> N>>M;
    int maxx=0;
    for(int i=0; i<N;i++){
        string a; cin >> a;
        for(int j=0; j<M;j++){
            if(a[j]=='W')
                graph[i][j]=0;
            else if(a[j]=='L')
                graph[i][j]=1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0; j<M;j++){
            if(graph[i][j]==1){
                int bmax=bfs(j,i);
                if(maxx<bmax)
                    maxx=bmax;
                INIT();
            }
        }
    }
    cout << maxx;
}