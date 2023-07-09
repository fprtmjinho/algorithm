#include <iostream>

using namespace std;

string day[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

int dp[13];
int main(){
    int x,y; cin >> x >> y;
    int date=0;
    for(int i=1; i<=12;i++){
        if(i==2)
            dp[i]=dp[i-1]+28;
        else if(i<=7&&i%2==1){
            dp[i]=dp[i-1]+31;
        }
        else if(i<=7&&i%2==0){
            dp[i]=dp[i-1]+30;
        }
        else if(i>7&&i%2==0){
            dp[i]=dp[i-1]+31;
        }
        else if(i>7&&i%2==1){
            dp[i]=dp[i-1]+30;
        }
    }
    date=dp[x-1]+y;
    cout << day[date%7];
}