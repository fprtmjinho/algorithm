#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
    int L; cin >> L;
    string l; cin >> l;
    int re=0;
    for(int i = 0; i<L; i++){
        re = re+(l[i]-96)*pow(31,i);
    }
    re = re%1234567891;
    cout << re;
}