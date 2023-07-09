#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 50;
int visited[50];

int check_diff(string a, string b){
    int dif_cnt =0;
    for(int i=0; i<a.size();i++){
        if(a[i]!=b[i]){
            dif_cnt++;
        }
    }
    if(dif_cnt==1){
        return 1;
    }
    return 0;
}

void dfs(string begin, string target, vector<string>words, int i){
    if(answer <= i)
        return;
    if(begin==target){
        answer =min(answer,i);
        return;
    }
    for(int j=0; j<words.size();j++){
        if(check_diff(begin,words[j])&& !visited[j]){
            visited[j]=1;
            dfs(words[j],target,words,i+1);
            visited[j]=0;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    dfs(begin,target,words,0);

    if(answer == 50)
    return 0;

    return answer;
}

int main(){

}