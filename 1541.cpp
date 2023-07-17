#include <iostream>
#include <string>

using namespace std;
string a;


int main(){
    cin>> a;
    int re=0;
    string number;
    bool flag=false;
    for(int i=0; i<=a.size(); i++){
        if(a[i]=='-'||a[i]=='+'||i==a.size()){
            if(flag){
                re-=stoi(number);
                number = "";
            }else{
                re+=stoi(number);
                number="";
            }
        }else{
            number+=a[i];
        }
        if(a[i]=='-'){
            flag=true;
        }
    }
    cout << re;
}