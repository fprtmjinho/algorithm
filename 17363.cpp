#include <iostream>

using namespace std;

int main(){
    int N,M; cin >> N >> M;
    string first[N];
    char second[M][N];
    for (int i=0; i<N; i++){
        cin >> first[i];
    }
    for (int i=0; i<N;i++){
        for (int j=0; j<M;j++){
            if (first[i][j] =='O') second[M-j-1][i]='O';
            else if (first[i][j]=='-') second[M-j-1][i] = '|';
            else if (first[i][j]=='|') second[M-j-1][i] = '-';
            else if (first[i][j]=='/') second[M-j-1][i] = '\\';
            else if (first[i][j]=='\\') second[M-j-1][i] = '/';
            else if (first[i][j]=='^') second[M-j-1][i] = '<';
            else if (first[i][j]=='<')second[M-j-1][i] ='v';
            else if (first[i][j]=='v')second[M-j-1][i] ='>';
            else if (first[i][j]== '>')second[M-j-1][i] = '^';
            else second[M-j-1][i] =first[i][j];
        }
    }
    for (int i=0; i<M;i++){
        for(int j=0; j<N;j++){
            cout << second[i][j];
        }
        cout << endl;
    }
}