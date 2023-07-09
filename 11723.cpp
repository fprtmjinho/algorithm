#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M; cin >> M;
    int bit=0;
    int x;
    string order;
    while(M--){
        cin >> order;
        if (order=="add"){
            cin >> x;
            bit|=(1<<x);
        }
        else if(order=="remove"){
            cin >> x;
            bit&=~(1<<x);
        }
        else if(order=="check"){
            cin >> x;
            if(bit & (1 << x))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(order=="toggle"){
            cin >> x;
            bit ^=(1<<x);
        }
        else if(order=="all"){
            bit = (1<<21)-1;
        }
        else if(order=="empty"){
            bit = 0;
        }
    }
}