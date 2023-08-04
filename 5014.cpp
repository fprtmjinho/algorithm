#include <iostream>
#include <queue>
#include <cmath>
#define MAX 1000001

using namespace std;

int visited[1000001];
queue<int> q;

int F,S,G,U,D;
int B[2];

void BFS(){
    q.push(S);
    visited[S]=1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<2; i++){
            int vb = v+B[i];
            if (vb<=F&&vb>0){
                if (visited[vb]==0){
                    q.push(vb);
                    visited[vb] = visited[v]+1;
                }
            }
            
        }
    }
}

int main(){
    cin >>F>>S>>G>>U>>D;
    B[0]=U;
    B[1]=-1*D;
    BFS();
    if (visited[G]==0) cout << "use the stairs";
    else cout << visited[G] - 1;
}