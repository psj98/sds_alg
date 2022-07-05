#include <iostream>
#include <queue>
#include <set>

using namespace std;

queue<string> q; // 숫자
int n; // 교환 횟수

void swap(string& mystr, int left, int right){
    char temp = mystr[left];
    mystr[left] = mystr[right];
    mystr[right] = temp;
}

int main() {
    string str;
    string answer = "0";

    cin >> str >> n;
    q.push(str);

    for(int i=0; i<n; i++){
        set<string> s;
        
        int qsize = q.size();

        for(int j=0; j<qsize; j++){
            string item = q.front();
            q.pop();

            // 중복 값 확인
            if(s.count(item)!=0) continue;

            s.insert(item);

            for(int k=0; k<item.size()-1; k++){
                for(int l=k+1; l<item.size();l++){
                    if(!(k==0 && item[l]=='0')){
                        swap(item, k, l);
                        q.push(item);
                        swap(item, k, l);
                    }
                }
            }
        }
    }

    while(!q.empty()){
        answer = max(answer, q.front());
        q.pop();
    }

    if(answer[0] == '0') printf("%d\n", -1);
    else cout << answer << '\n';

    return 0;
}