#include <iostream>
#include <queue>
#define PAIR pair<int,int>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int graph[100][100];
int visited[100][100];
queue<PAIR> q;

int N;

void INIT(){
    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=0;
        }
    }
}

void BFS(int sx,int sy,int maxx){
    q.push(PAIR(sx,sy));
    visited[sy][sx]=1;
    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = vx+dx[i];
            int yy = vy+dy[i];
            if(xx>=0&&xx<N&&yy>=0&&yy<N&&graph[yy][xx]>maxx&&visited[yy][xx]==0){
                q.push(PAIR(xx,yy));
                visited[yy][xx]=1;
            }
        }
    }
}

int main(){
    cin >> N;
    int maxx=-1;
    int re=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a; cin >> a;
            if(maxx<a)
                maxx=a;
            graph[i][j]=a;
        }
    }
    for(int k=0; k<=maxx; k++){
        int cnt=0;
        INIT();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(graph[i][j]>k&&visited[i][j]==0){
                    cnt++;
                    BFS(j,i,k);
                }
            }
        }
        if(re<cnt)
            re=cnt;
    }
    cout << re;
}