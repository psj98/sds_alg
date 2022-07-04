#include <iostream>
#include <vector>

using namespace std;

vector<string> words;
bool alpha[26];
int n, k, answer;

int check(){
    bool can;
    int cnt=0;

    for(int i=0; i<words.size(); i++){
        can = true;
        string str = words[i];
        for(int j=0; j<str.length(); j++){
            if(!alpha[str[j]-'a']){
                can = false;
                break;
            }
        }

        if(can) cnt++;
    }

    return cnt;
}

void solve(int a, int b){
    if(b==k){
        if(answer > check()) answer = answer;
        else answer = check();
        return;
    }

    for(int i=a; i<26; i++){
        if(alpha[i]) continue;
        alpha[i] = true;
        solve(i, b+1);
        alpha[i] = false;
    }
}

int main(){
    cin >> n >> k;

    // n개만큼 단어 입력
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }

    if(k<5) {
        printf("0");
        return 0;
    }

    // a, c, i, n, t
    alpha[0] = alpha[2] = alpha[8] = alpha[13] = alpha[19] = true;
    k-=5;

    solve(0, 0);
    printf("%d", answer);

    return 0;
}