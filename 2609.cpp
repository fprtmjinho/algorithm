#include <iostream>


using namespace std;
int gcd(int a, int b){
    if (b%a==0)
        return a;
    if (b%a>a)
        return gcd(a,b%a);
    return gcd(b%a,a);
}
int main(){
    int a,b;cin >> a >> b;
    if (a<b)
        cout << gcd(a,b) << endl;
    else
        cout << gcd(b,a) << endl;
    cout << (a * b) / gcd(a,b);
}