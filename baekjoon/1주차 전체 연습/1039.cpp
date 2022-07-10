#include <iostream>
#include <queue>
#include <set>

using namespace std;

queue<string> q;

void swap(string &a, int l, int r){
    char temp=a[l];
    a[l]=a[r];
    a[r]=temp;
}

int main(){
    string ans="0";
    string n;
    int k;
    cin >> n >> k;

    if(n.size()==1){
        printf("-1");
        return 0;
    }

    q.push(n);

    for(int i=0; i<k; i++){
        set<string> s;

        int qsize=q.size();

        for(int j=0; j<qsize; j++){
            string a=q.front();
            q.pop();

            if(s.count(a)!=0) continue;

            s.insert(a); 
            
            // 각 자리에 대해 바꿈
            for(int k=0; k<a.size()-1; k++){
                for(int l=k+1; l<a.size(); l++){
                    if(!(k==0 && a[l]=='0')){
                        swap(a, k, l);
                        q.push(a);
                        swap(a, k, l);
                    }
                }
            }
        }
    }

    while(!q.empty()){
        ans=max(ans, q.front());
        q.pop();
    }

    if(ans[0]=='0') printf("-1");
    else cout << ans;

    return 0;
}