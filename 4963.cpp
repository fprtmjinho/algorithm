#include <iostream>
#include <queue>
#define PAIR pair<int,int>

using namespace std;

int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={1,1,1,0,-1,-1,-1,0};

int w,h;
int graph[50][50];
int visited[50][50];
queue<PAIR> q;

void INIT(){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            visited[i][j]=0;
        }
    }
}

void BFS(int x, int y){
    q.push(PAIR(x,y));
    visited[y][x]=1;
    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int xx = vx+dx[i];
            int yy = vy+dy[i];
            if(xx>=0&&xx<w&&yy>=0&&yy<h&&graph[yy][xx]==1&&visited[yy][xx]==0){
                q.push(PAIR(xx,yy));
                visited[yy][xx]=1;
            }
        }
    }

}

int main(){
    while(1){
        cin >> w>>h;
        int cnt=0;
        INIT();
        if(w==0 && h==0) break;
        for(int i=0; i<h;i++){
            for(int j=0; j<w; j++){
                int a; cin >> a;
                graph[i][j]=a;
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(graph[i][j]==1&&visited[i][j]==0){
                    BFS(j,i);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}