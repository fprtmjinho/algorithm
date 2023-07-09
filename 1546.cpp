#include <iostream>

using namespace std;

int main(){
    int N; cin>>N;
    int score[1000];
    int max=0;
    double re=0;
    for(int i=0;i<N;i++){
        cin >> score[i];
        if (max<score[i])
            max = score[i];
        re += score[i];
    }
    re = (re/max *100)/N;
    cout << re << endl;
}