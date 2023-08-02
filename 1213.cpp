#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[26];

int main(){
    string name; cin >> name;
    
    for (int i=0; i<name.size(); i++)
        alpha[name[i] - 'A']++;
 
    int err = 0;
    int index = -1;
 
    for (int i=0; i<26; i++){
        if (alpha[i] > 0){
            if (alpha[i] % 2 == 1){
                index = i;
                alpha[i]--;
                err++;
            }
        }
    }
     if (err>1)
        printf("I'm Sorry Hansoo\n");
    else {
        string ans = "";
        string temp = "";
        for (int i = 0; i < 26; i++) {
            if (alpha[i] > 0) {
                for (int j = 0; j < alpha[i] / 2; j++) {
                    ans += i + 'A';
                }
            }
        }
        temp = ans;
        reverse(temp.begin(), temp.end());
        if (index != -1) {
            ans += index + 'A';
        }
        ans += temp;
        cout << ans << '\n';
    }
}