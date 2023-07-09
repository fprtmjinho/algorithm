#include <iostream>
#include <string>

using namespace std;

int main(){
    int N; cin >> N;
    int cnt=0;
    int a = 666;
    bool flag = false;
    string re;
    while(1){
        re = to_string(a);
        for (int i = 0; i<re.length()-2; i++){
            if(re[i]=='6' && re[i+1]=='6' && re[i+2]=='6'){
                cnt++;
                if(cnt == N){
                    cout << a;
                    flag = true;
                }
                break;
            }
        }
        if (flag)
            break;
        a++;
    }
}