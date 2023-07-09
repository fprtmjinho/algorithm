#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int ograph[100][100];
int ngraph[100][100];
int visited[100][100];
int N;

void init(){
    for(int i=0; i<N; i++)
        fill_n(visited[i],N,0);
}

void NBFS(int sx,int sy){
    queue<pair<int, int> > q;
    q.push(pair<int,int>(sx,sy));
    visited[sx][sy]=1;
    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = vx + dx[i];
            int yy = vy + dy[i];
            if(xx>=0&&xx<N&&yy>=0&&yy<N&&visited[xx][yy]==0&&ngraph[xx][yy]==ngraph[vx][vy]){
                q.push(pair<int,int>(xx,yy));
                visited[xx][yy]=1;
            }
        }
    }
}
void OBFS(int sx,int sy){
    queue<pair<int, int> > q;
    q.push(pair<int,int>(sx,sy));
    visited[sx][sy]=1;
    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = vx + dx[i];
            int yy = vy + dy[i];
            if(xx>=0&&xx<N&&yy>=0&&yy<N&&visited[xx][yy]==0&&ograph[xx][yy]==ograph[vx][vy]){
                q.push(pair<int,int>(xx,yy));
                visited[xx][yy]=1;
            }
        }
    }
}

int main(){
    cin >> N;
    string a;
    int cntn =0;
    int cnto =0;
    for(int i=0; i<N;i++){
        cin >>a;
        for(int j=0; j<N;j++){
            if(a[j]=='B'){
                ograph[i][j]=1;
                ngraph[i][j]=1;
            }
            else if(a[j]=='R'){
                ograph[i][j]=2;
                ngraph[i][j]=3;
            }
            else{
                ograph[i][j]=2;
                ngraph[i][j]=2;
            }
        }
    }
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if(visited[i][j]==0){
                NBFS(i,j);
                cntn++;
            }
        }
    }
    init();
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if(visited[i][j]==0){
                OBFS(i,j);
                cnto++;
            }
        }
    }
    cout << cntn << " " << cnto;
}