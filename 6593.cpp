#include <iostream>
#include <queue>
#define PAIR pair<int,int>
#define PPAIR pair<int,PAIR>

using namespace std;

int dx[6]={0,0,0,0,1,-1};
int dy[6]={1,-1,0,0,0,0};
int dz[6]={0,0,1,-1,0,0};

int L,R,C;
int graph[32][32][32];
int visited[32][32][32];
bool flag = false;
queue<PPAIR> q;

void BFS(int sx,int sy, int sz){
    q.push(PPAIR(sx,PAIR(sy,sz)));
    visited[sz][sy][sx]=1;
    while(!q.empty()){
        int vx=q.front().first;
        int vy=q.front().second.first;
        int vz=q.front().second.second;
        q.pop();
        if(graph[vz][vy][vx]==2){
            flag = true;
            break;
        }
        for(int i=0; i<6; i++){
            int xx = vx+dx[i];
            int yy = vy+dy[i];
            int zz = vz+dz[i];
            if(xx<0||yy<0||zz<0||xx>=C||yy>=R||zz>=L)
                continue;
            if(visited[zz][yy][xx]==0&&graph[zz][yy][xx]!=0){
                q.push(PPAIR(xx,PAIR(yy,zz)));
                visited[zz][yy][xx]=visited[vz][vy][vx]+1;
            }
        }
    }
}
void INIT(){
    for(int i=0;i<30;i++){
        for(int j=0; j<30; j++){
            for(int k=0;k<30; k++){
                visited[i][j][k]=0;
                graph[i][j][k]=0;
            }
        }
    }
}

int main(){gggggg
    while(1){
        cin >> L >> R >> C;
        if (L==0&&R==0&&C==0)
            break;
        int sx,sy,sz;
        int ex,ey,ez;
        flag = false;
        INIT();
        for(int i=0; i<L; i++){
            for(int j=0; j<R;j++){
                string a; cin >>a;
                for (int k=0; k<C;k++){
                    if(a[k]=='S'||a[k]=='.')
                        graph[i][j][k]=1;
                    else if(a[k]=='E'){
                        graph[i][j][k]=2;
                        ex=k;
                        ey=j;
                        ez=i;
                    }
                    else
                        graph[i][j][k]=0;
                    if(a[k]=='S'){
                        sx=k;
                        sy=j;
                        sz=i;
                    }
                }
            }
        }
        BFS(sx,sy,sz);
        if (flag)
            cout << "Escaped in " << visited[ez][ey][ex]-1 << " minute(s).";
        else
            cout << "Trapped!";
        cout <<"\n";
    }
}