#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int graph[600][600];
int visited[600][600];

queue<pair<int,int> > q;

int N,M;
int sx,sy,cnt;

void BFS(int sx,int sy){
    cnt = 0;
    q.push(pair<int,int>(sx,sy));
    visited[sy][sx]=1;
    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++){
            int xx = vx + dx[i];
            int yy = vy + dy[i];
            if(xx>=0 && xx<M && yy>=0 && yy<N && visited[yy][xx]==0 && graph[yy][xx]!=1){
                q.push(pair<int,int>(xx,yy));
                visited[yy][xx]=1;
                if(graph[yy][xx]==2)
                    cnt++;
            }
        }
    }
}

int main(){
    cin >>N >>M;
    string a;
    for(int i=0; i<N; i++){
        cin >> a;
        for(int j=0; j<M;j++){
            if (a[j]=='X')
                graph[i][j]=1;
            else if(a[j]=='P')
                graph[i][j]=2;
            else if(a[j]=='I'){
                graph[i][j]=-1;
                sx=j;
                sy=i;
            }
        }
    }
    BFS(sx,sy);
    if (cnt ==0)
        cout << "TT";
    else
        cout << cnt;
}