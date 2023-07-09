#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;
    int start=N;
    int cnt=0;
    while(true){
        cnt++;
        int a = start/10;
        int b = start%10;
        int c = a+b;
        start=b*10+c%10;
        if(N==start)
            break;
    }
    cout << cnt;
}