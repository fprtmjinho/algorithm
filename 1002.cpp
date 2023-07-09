#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int i=0; i<T; i++){
        int ax,ay,ar,bx,by,br;
        cin>>ax>>ay>>ar>>bx>>by>>br;
        int len =pow(abs(ax-bx),2)+pow(abs(ay-by),2);
        int rmin = pow(abs(ar-br),2);
        int rmax = pow(ar+br,2);
        if (ax==bx && ay==by && ar==br)
            cout << -1;
        else if(ax==bx && ay==by)
            cout << 0;
        else if(len == rmax || len == rmin)
            cout << 1;
        else if(len < rmax && len > rmin)
            cout << 2;
        else
            cout <<0;
        cout << endl;
    }
}