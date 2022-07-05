#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000000000 // MAX 개수(10^9)

typedef long long ll;

using namespace std;

stack<ll> s; // 스택
vector<string> vec; // 명령어 벡터
vector<ll> num; // NUM일 때 받을 숫자 벡터

int NUM(ll a){
    s.push(a);

    return 0;
}

int POP(){
    if(s.empty()) return 1;

    s.pop();
    return 0;
}

int INV(){
    if(s.empty()) return 1;

    ll a = -s.top();
    s.pop();
    s.push(a);
    return 0;
}

int DUP(){
    if(s.empty()) return 1;
    s.push(s.top());
    return 0;
}

int SWP(){
    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(s.empty()) return 1;
    ll b = s.top();
    s.pop();

    s.push(a);
    s.push(b);
    return 0;
}

int ADD(){
    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(s.empty()) return 1;
    a += s.top();

    s.pop();
    s.push(a);
    return 0;
}

int SUB(){
    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(s.empty()) return 1;
    a = s.top() - a;
    
    s.pop();
    s.push(a);
    return 0;
}

int MUL(){
    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(s.empty()) return 1;
    a *= s.top();

    s.pop();
    s.push(a);
    return 0;
}

int DIV(){
    int ch=0;

    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(a==0) return 1;
    if(a<0) ch++;

    if(s.empty()) return 1;
    ll b = s.top();
    s.pop();

    if(b<0) ch++;

    b/=a;
    if(ch==1) s.push(-abs(b));
    else s.push(abs(b));
    
    return 0;
}

int MOD(){
    int ch=0;

    if(s.empty()) return 1;
    ll a = s.top();
    s.pop();

    if(a==0) return 1;

    if(s.empty()) return 1;
    ll b = s.top();
    s.pop();

    if(b<0) ch++;

    b%=a;
    if(ch==1) s.push(-abs(b));
    else s.push(abs(b));
    
    return 0;
}

int main(){
    string str; 
    ll n;
    int x, y, checkNum, errorCh; // 반복 횟수, 각 입력 숫자, NUM일 때 가져올 숫자 위치, ERROR 체크

    while(1){
        errorCh = 0;

        // 명령어 입력 (END나 QUIT 나올 때까지)
        while(1){
            cin >> str;
            if(str=="NUM"){
                cin >> n;
                num.push_back(n);
            }
            if(str=="END") break;
            if(str=="QUIT") return 0;
            vec.push_back(str); // 명령어 벡터에 push_back
        }

        cin >> x; // 반복 횟수 입력

        // 숫자 입력
        while(x>0){
            checkNum=0;

            cin >> y; s.push(y);

            // 명령어 개수만큼 반복
            for(int i=0; i<vec.size(); i++){
                if(vec[i]=="NUM"){
                    errorCh=NUM(num[checkNum]);
                    checkNum++;
                }
                else if(vec[i]=="POP") errorCh=POP();
                else if(vec[i]=="INV") errorCh=INV();
                else if(vec[i]=="DUP") errorCh=DUP();
                else if(vec[i]=="SWP") errorCh=SWP();
                else if(vec[i]=="ADD") errorCh=ADD();
                else if(vec[i]=="SUB") errorCh=SUB();
                else if(vec[i]=="MUL") errorCh=MUL();
                else if(vec[i]=="DIV") errorCh=DIV();
                else if(vec[i]=="MOD") errorCh=MOD();

                // 조건 체크 (스택이 비어있지 않고 MAX값보다 크거나 -MAX값보다 작을 경우)
                if(!s.empty() && (s.top()>MAX || s.top()<-MAX)) errorCh=1;
                if(errorCh) break;
            }

            // ERROR이거나 스택 크기가 1이 아닌 경우, ERROR 출력
            if(errorCh || s.size()!=1) printf("ERROR\n");
            else printf("%d\n", s.top()); // 아닌 경우, 스택의 가장 위의 값 출력

            while(!s.empty()) s.pop(); // 스택 비우기

            x--;
        }

        // 벡터 비우기
        vec.clear();
        num.clear();
        printf("\n");
    }

    return 0;
}