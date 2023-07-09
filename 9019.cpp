#include <iostream>
#include <queue>
#include <string>

using namespace std;

int visited[10000];

void BFS(int s, int e){
    queue<pair<int, string> > q;
    q.push(pair<int,string>(s,""));
    visited[s]=1;
    while(!q.empty()){
        int v=q.front().first;
        string vs=q.front().second;
        q.pop();
        if(v==e){
            cout << vs<<endl;
            return;
        }
        int D,S,L,R, tmp;
        D = (v*2) %10000;
        if(!visited[D]){
            visited[D]=1;
            q.push(pair<int,string>(D,vs+"D"));
        }
        S=v-1<0?9999:v-1;
        if(!visited[S]){
            visited[S]=1;
            q.push(pair<int,string>(S,vs+"S"));
        }
        L=(v%1000)*10 + (v/1000);
        if(!visited[L]){
            visited[L]=1;
            q.push(pair<int,string>(L,vs+"L"));
        }
        R=v/10+(v%10)*1000;
        if(!visited[R]){
            visited[R]=1;
            q.push(pair<int,string>(R,vs+"R"));
        }

    }
}
int main(){
    int T; cin >> T;
    for(int i=0; i<T; i++){
        int s,e; cin >> s>>e;
        fill_n(visited,10000,0);
        BFS(s,e);
    }

}