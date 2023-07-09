#include <iostream>
#include <queue>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

queue<pair<int,int> > q;
int graph[50][50];
int visited[50][50];
int N,M,K;

void BFS(int x,int y){
    q.push(pair<int,int>(x,y));
    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();
        visited[vx][vy] = 1;
        for(int i=0;i<4;i++){
            int xx = vx+dx[i];
            int yy = vy+dy[i];
            if(xx >= 0 && yy >= 0 && xx < N && yy < M && !visited[xx][yy] && graph[xx][yy] == 1){
                visited[xx][yy] = true;
                q.push(pair<int,int>(xx,yy));
            }
        }
    }
}
void init() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
			graph[i][j] = 0;
		}
	}
}

int main(){
    int T; cin>>T;
    for(int t=0; t<T; t++){
        init();
        int cnt=0;
        cin>>M>>N>>K;
        for(int i=0; i<K;i++){
            int x,y; cin>>y>>x;
            graph[x][y]=1;
        }
        for(int i=0; i<N; i++){
            for (int j=0; j< M; j++){
                if(graph[i][j]==1 && visited[i][j]==0){
                    BFS(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt<<endl;
    }
    
}