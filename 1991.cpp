#include <iostream>

using namespace std;

int v[26][2];

void first(int n){
    if (n==-1)
        return;
    cout << (char)(n+65);
    first(v[n][0]);
    first(v[n][1]);
}
void second(int n){
    if (n==-1)
        return;
    second(v[n][0]);
    cout << (char)(n+65);
    second(v[n][1]);
}
void third(int n){
    if (n==-1)
        return;
    third(v[n][0]);
    third(v[n][1]);
    cout << (char)(n+65);
}


int main(){
    int n; cin>>n;
    for (int i=0; i<n;i++){
        char a,b,c; cin >>a>>b>>c;
        if(b=='.')
            v[a-65][0]=-1;
        else
            v[a-65][0]=b-65;
        if(c=='.')
            v[a-65][1]=-1;
        else
            v[a-65][1]=c-65;
    }
    first(0);
    cout << "\n";
    second(0);
    cout << "\n";
    third(0);
}