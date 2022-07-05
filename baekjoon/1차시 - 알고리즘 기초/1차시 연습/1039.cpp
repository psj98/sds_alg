#include <iostream>
#include <queue>
#include <set>

using namespace std;

queue<string> q;
int n;

void swap(string& s, int a, int b){
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

int main(){
    string str, answer = "0";
    cin >> str >> n;
    q.push(str); // queue에 값 추가

    for(int i = 0; i < n; i++) {
        set<string> st; // 중복 제거할 set
        int qsize = q.size();

        for(int j = 0; j < qsize; j++){
            string s = q.front(); // queue에서 값을 가져옴
            q.pop();

            // 중복 값인 경우
            if(st.count(s) != 0)
                continue;
            st.insert(s);

            for(int k = 0; k < s.size() - 1; k++) {
                for(int l = k + 1; l < s.size(); l++) {
                    // 맨 앞자리이고 바꿀 자리의 숫자가 0이면 False
                    if(!(k == 0 && s[l] == '0')) {
                        swap(s, k, l);
                        q.push(s);
                        swap(s, k, l); // 원래대로 되돌림
                    }
                }
            }
        }
    }

    while(!q.empty()) {
        answer = max(answer, q.front());
        q.pop();
    }

    if(answer[0] == '0') printf("%d\n", -1);
    else cout << answer << '\n';

    return 0;
}