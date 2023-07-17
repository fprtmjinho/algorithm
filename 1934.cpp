#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b){
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main(){
    int T; cin>>T;
    for(int i=0; i<T; i++){
        int A,B,maxx; cin>>A>>B;
        maxx=GCD(A,B);
        cout << A * B / maxx<<'\n';
    }
}