#include <iostream>
#include <string>

using namespace std;

int main(){
    while(1){
        string a; cin >> a;
        bool flag = true;
        if (a=="0")
            break;
        for(int i = 0;i<a.size();i++){
            if (a[i]!=a[a.size()-i-1]){
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}