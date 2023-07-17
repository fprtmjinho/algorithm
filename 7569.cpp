#include <iostream>
#include <queue>
#define PAIR pair<int,int>
#define PPAIR pair<PAIR,int>

using namespace std;

int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

int graph[101][101][101];
int visited[101][101][101];
queue<PPAIR> q;

void print(){
    for (int i =0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for (int k = 0; k < 5; k++){
                cout << graph[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
void bfs(int M, int N, int H){
    int date =0 ;
    while(!q.empty()){
        date++;
        int size = q.size();
        for(int j = 0; j < size; j++){
            int nx = q.front().first.first;
            int ny = q.front().first.second;
            int nz = q.front().second;
            q.pop();
            for(int i = 0; i < 6; i++){
                int xx = nx+dx[i];
                int yy = ny+dy[i];
                int zz = nz+dz[i];
                if (xx >= 0 && yy >= 0 && zz >= 0 && xx < M && yy < N && zz < H && graph[zz][yy][xx] == 0){
                    q.push(PPAIR(PAIR(xx,yy),zz));
                    graph[zz][yy][xx]=1;
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                if (graph[i][j][k]==0){
                    cout << -1;
                    return;
                }
            }
        }
    }
    cout << date - 1;
}

int main(){
    int M,N,H; cin >> M >> N >> H;
    bool flag = false;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                int a; cin >> a;
                graph[i][j][k] = a;
                if (a == 1) q.push(PPAIR(PAIR(k,j),i));
                if (a==0) flag = true;
            }
        }
    }
    if (!flag){
        cout << 0;
        return 0;
    }
    bfs(M,N,H);
}