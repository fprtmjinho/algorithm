#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define PAIR pair<int,int>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int graph[100][100];
int visited[100][100];
queue<PAIR> q;

int M,N,K;

int bfs(int sx,int sy){
    int cnt=1;
    q.push(PAIR(sx,sy));
    visited[sy][sx]=1;
    while(!q.empty()){
        int vx=q.front().first;
        int vy=q.front().second;
        q.pop();
        for(int i=0; i<4;i++){
            int xx = vx+dx[i];
            int yy = vy+dy[i];
            if(xx>=0&&yy>=0&&xx<N&&yy<M&&visited[yy][xx]==0&&graph[yy][xx]==0){
                q.push(PAIR(xx,yy));
                visited[yy][xx]=1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    cin >> M>>N>>K;
    int cnt=0;
    vector<int> re;
    for(int i =0; i<K; i++){
        int lbx,lby,rtx,rty;
        cin>>lbx>>lby>>rtx>>rty;
        for(int i=lby;i<rty;i++){
            for(int j=lbx;j<rtx;j++){
                graph[i][j]=1;
            }
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0; j<N; j++){
            if(graph[i][j]==0&&visited[i][j]==0){
                re.push_back(bfs(j,i));
                cnt++;
            }
        }
    }
    sort(re.begin(),re.end());
    cout << cnt <<"\n";
    for(int i=0; i<cnt;i++){
        cout<<re[i]<< " ";
    }

}