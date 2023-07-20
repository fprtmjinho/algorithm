#include <iostream>

using namespace std;

int main(){
    int T; cin >> T;
    for(int i=0; i<T; i++){
        vector<int> ju;
        vector<int> mx;
        int re=0;
        int N; cin >> N;
        for(int j=0; j<N; j++){
            int a;cin>>a;
            ju.push_back(a);
        }
        int m=ju[0];
        mx.push_back(0);
        int cnt=0;
        for(int j=1; j<ju.size();j++){
            if(ju[j]>=m){
                mx[cnt]=j;
            }else{
                if(ju[mx[cnt]]<m){
                    mx[cnt]=j-1;
                    mx.push_back(j);
                }else{
                    mx.push_back(j);aaa
                }
            }
            m=ju[j];
            cnt++;
        }
        int nx=0;
        for(int j=0;j<mx.size();j++){
            for(int k=nx;k<=mx[j];k++){
                if(ju[mx[j]]-ju[k]>=0)
                    re=re+ju[mx[j]]-ju[k];
            }
            nx=mx[j];
        }
        cout << re << "\n";
    }
}