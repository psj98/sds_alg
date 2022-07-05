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
    q.push(str); // queue�� �� �߰�

    for(int i = 0; i < n; i++) {
        set<string> st; // �ߺ� ������ set
        int qsize = q.size();

        for(int j = 0; j < qsize; j++){
            string s = q.front(); // queue���� ���� ������
            q.pop();

            // �ߺ� ���� ���
            if(st.count(s) != 0)
                continue;
            st.insert(s);

            for(int k = 0; k < s.size() - 1; k++) {
                for(int l = k + 1; l < s.size(); l++) {
                    // �� ���ڸ��̰� �ٲ� �ڸ��� ���ڰ� 0�̸� False
                    if(!(k == 0 && s[l] == '0')) {
                        swap(s, k, l);
                        q.push(s);
                        swap(s, k, l); // ������� �ǵ���
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