#include <iostream>

using namespace std;

int main(){
    double a,d,k; cin >>a>>d>>k;
    double re = 0;
    double gg = 1;
    d/=100;
    k/=100;
    for(int i=1;;i++){
        re+=i*a*gg*d;
        if(d==1)
            break;
        gg = gg*(1-d);
        d+=d*k;
        if(d>=1)
            d=1;
    }
    cout.precision(7);
    cout << fixed <<re;

}