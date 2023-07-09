#include <iostream>
#include <string>

using namespace std;

int main(){
    string S;
    cin >> S;
    int start =0;
    int range = min(3, (int)S.length());
    for(int i=0; i< range; i++){
        start = start *10 + S[i] - 48;
        string add;
        for(int i = start;;i++){
            add = add+to_string(i);
            if (add==S){
                cout << start<<" " << i;
                return 0;
            }
            if(add.size() > S.size())
                break;
        }
    }
}