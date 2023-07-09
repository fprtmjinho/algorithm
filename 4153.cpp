#include <iostream>
#include <math.h>

using namespace std;

int main(){
    while(1){
        int a,b,c; cin >> a >> b >> c;
        if(a==0 && b==0 && c==0)
            break;
        if(a<c&&b<c){
            if(pow(a,2) + pow(b,2) == pow(c,2))
                cout << "right" << endl;
            else
                cout << "wrong"<< endl;
        }
        else if(c<b&&a<b){
            if(pow(a,2) + pow(c,2) == pow(b,2))
                cout << "right" << endl;
            else
                cout << "wrong"<< endl;
        }
        else if(c<a&&b<a){
            if(pow(c,2) + pow(b,2) == pow(a,2))
                cout << "right" << endl;
            else
                cout << "wrong"<< endl;
        }
        else
            cout << "wrong"<< endl;
    }
}