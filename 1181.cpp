#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;    
}
int main(){
    vector <string> str;
    string name;
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> name;
        if(find(str.begin(),str.end(),name) == str.end()){
            str.push_back(name);
        }   
    }
    sort(str.begin(),str.end(),cmp);
    for(int i = 0; i < str.size(); i++){
        cout << str[i] << endl;
    }
}