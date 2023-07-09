#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define PAIR pair<int,int>
#define PPAIR pair<PAIR,int>

using namespace std;
int visited[201][201][201];
queue<PPAIR> q;

vector<int> v;

int A,B,C;

void bfs(){
    q.push(PPAIR(PAIR(0,0),C));
    while(!q.empty()){
        int a=q.front().first.first;
        int b=q.front().first.second;
        int c=q.front().second;
        q.pop();
        if(visited[a][b][c]) continue;
        visited[a][b][c]=1;
        if(a==0) v.push_back(c);
        
        if (a + b > B) q.push(PPAIR(PAIR(a + b - B, B), c));
        else q.push(PPAIR(PAIR(0, a + b), c));
 
        if (a + c > C) q.push(PPAIR(PAIR(a + c - C, b), C));
        else q.push(PPAIR(PAIR(0, b), a + c));
 
        if (b + a > A) q.push(PPAIR(PAIR(A, b + a - A), c));
        else q.push(PPAIR(PAIR(b + a, 0), c));
 
        if (b + c > C) q.push(PPAIR(PAIR(a, b + c - C), C));
        else q.push(PPAIR(PAIR(a, 0), b + c));
 
        if (c + a > A) q.push(PPAIR(PAIR(A, b), c + a - A));
        else q.push(PPAIR(PAIR(c + a, b), 0));
 
        if (c + b > B) q.push(PPAIR(PAIR(a, B), c + b - B));
        else q.push(PPAIR(PAIR(a, b + c), 0));
    }
}

int main(){
    cin>>A>>B>>C;
    bfs();
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout <<v[i]<<" ";
    }
    cout << endl;
}