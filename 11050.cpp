#include <iostream>

using namespace std;

int factorial(int a){
    if(a==0) return 1;
    int b=1;
    for(int i=a;i>=1;i--){
        b*=i;
    }
    return b;
}
int main(){
    int N,K; cin >> N >> K;
    cout << factorial(N)/(factorial(K)*factorial(N-K)) << endl;
}